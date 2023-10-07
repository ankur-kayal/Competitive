#include <bits/stdc++.h>
using namespace std;

//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

map<array<int, 3> ,int> cache;

int bg(int n, int i, int j) {
    if(cache.count({n, i, j})) {
        return cache[{n, i, j}];
    }
    if(i==1) return j;
    if(j==n) return n-1+i;
    if(i==n) return n*3-j-1;
    if(j==1) return 4*n-i-2;//The above is if the current point is the outermost layer, return directly

    if(!cache.count({n - 2, i - 1, j - 1})) {
        cache[{n - 2, i - 1, j - 1}] = bg(n - 2, i - 1, j - 1);
    }
    return 4 * n - 4 + cache[{n - 2, i - 1, j - 1}];//If it is not the outermost layer, let the next layer be the outermost layer, and add [this layer] ! ! ! ! (2,1) The value at the position.
}

int manhatten(pair<int,int> a, pair<int,int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void run_cases() {
    cache.clear();
    int N, K;
    cin >> N >> K;
    
    int k = 0, l = 0;

    int n = N, m = N;

    int i;

    int mid = N / 2;

    pair<int,int> start = {-1, -1};


    while (k < m && l < n) {
        for (i = l; i < n; ++i) {
            // {k, i}
            if(manhatten({mid, mid}, {k, i}) == K) {
                start = {k, i};
                goto outer;
            }
            K--;

        }
        k++;
 

        for (i = k; i < m; ++i) {
            if(manhatten({mid, mid}, {i, n - 1}) == K) {
                start = {i, n - 1};
                goto outer;
            }
            K--;
        }
        n--;

        if (k < m) {
            
            for (i = n - 1; i >= l; --i) {
                if(manhatten({mid, mid}, {m - 1, i}) == K) {
                    start = {m - 1, i};
                    goto outer;
                }
                K--;
            }
            m--;
        }

        if (l < n) {
            
            for (i = m - 1; i >= k; --i) {
                if(manhatten({mid, mid}, {i, l}) == K) {
                    start = {i, l};
                    goto outer;
                }
                K--;
            }
            l++;
        }
    }

    outer: 

    if(start != make_pair(-1, -1)) {
        pair<int,int> end = {mid, mid};

        vector<pair<int, int>> shortcuts;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(start != end) {
            int x = start.first;
            int y = start.second;

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(0 <= nx && nx < N && 0 <= ny && ny < N && manhatten({nx, ny}, {mid, mid}) < manhatten({x, y}, {mid, mid}) && bg(N, nx + 1, ny + 1) > bg(N, x + 1, y + 1)) {
                    if(bg(N, nx + 1, ny + 1) > bg(N, x + 1, y + 1) + 1) {
                        // debug() << imie(x) imie(y) imie(nx) imie(ny);
                        shortcuts.emplace_back(bg(N, x + 1, y + 1), bg(N, nx + 1, ny + 1));
                    }
                    x = nx;
                    y = ny;
                    start = {x, y};
                    break;
                }
            }
        }


        cout << shortcuts.size() << '\n';

        for(auto [x, y]: shortcuts) {
            cout << x << " " << y << '\n';
        }
        return;
    }

    

    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}