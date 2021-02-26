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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define nl '\n'
#pragma GCC optimize("trapv")

//----------------------------------- END DEFINES -------------------------------- 

int distance(pair<int, int>& p1, pair<int,int>& p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

bool verify(vector<pair<int,int>>& marked, vector<pair<int,int>>& essential, vector<pair<int,int>>& random_points) {
    int marker = 1;
    map<pair<int,int>, int> store;

    for(auto u: marked) {
        store[u] = marker;
        marker++;
    }

    for(auto u: essential) {
        store[u] = marker;
        marker++;
    }

    for(auto u: random_points) {
        store[u] = marker;
        marker++;
    }

    vector<vector<int>> dp(marker + 1, vector<int>(marker + 1, 100000));

    for(auto u: store) {
        pair<int,int> pt = u.first;
        int x = pt.first;
        int y = pt.second;

        pair<int,int> up, down, left, right;

        if(x - 1 >= 1) {
            left = {x - 1, y};
        }
        if(x + 1 <= 4) {
            right = {x + 1, y};
        }
        if(y - 1 >= 1) {
            up = {x, y - 1};
        }
        if(y + 1 <= 5) {
            down = {x, y + 1};
        }

        if(store.count(right)) {
            dp[store[pt]][store[right]] = 1;
            dp[store[right]][store[pt]] = 1;
        }

        if(store.count(left)) {
            dp[store[pt]][store[left]] = 1;
            dp[store[left]][store[pt]] = 1;
        }

        if(store.count(up)) {
            dp[store[pt]][store[up]] = 1;
            dp[store[up]][store[pt]] = 1;
        }

        if(store.count(down)) {
            dp[store[pt]][store[down]] = 1;
            dp[store[down]][store[pt]] = 1;
        }
    }

    int maxN = store.size();
    for(int k=1;k<=maxN;k++) {
        for(int i=1;i<=maxN;i++) {
            for(int j=1;j<=maxN;j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    for(auto u: marked) {
        for(auto v: marked) {
            if(u != v) {
                // debug() << imie(dp[store[u]][store[v]]) imie(u) imie(v) imie(distance(u, v));
            
                if(dp[store[u]][store[v]] != distance(u, v)) {
                    return false;
                }
            }
        }
    }
    return true;
}

void run_cases() {
    int maxP = 1 << 20;
    // debug() << imie(maxP);
    vector<vector<int>> bits(21);

    
    vector<pair<int,int>> unmarked;
    vector<pair<int,int>> marked;
    vector<pair<int,int>> essentials;
    vector<vector<int>> grid(5, vector<int>(6, 0));
    vector<vector<int>> req(5, vector<int>(6, 0));
    int N,T;
    cin >> N >> T;
    assert(N <= 20);
    for(int i=0;i<N;i++) {
        int x,y;
        cin >> x >> y;
        marked.emplace_back(4 - y + 1, x);
        grid[4 - y + 1][x] = 1;
    }

    // for(int i=1;i<=4;i++) {
    //     int first = 100;
    //     int last = -1;
    //     for(int j=1;j<=5;j++) {
    //         if(grid[i][j] == 1) {
    //             first = min(first, j);
    //             last = max(first, j);
    //         }
    //     }
    //     for(int j=first;j<=last;j++) {
    //         if(grid[i][j] != 1 and req[i][j] != 1) {
    //             req[i][j] = 1;
    //             essentials.emplace_back(i,j);
    //         }
    //     }
    // }



    // for(int i=1;i<=5;i++) {
    //     int first = 100;
    //     int last = -1;
    //     for(int j=1;j<=4;j++) {
    //         if(grid[j][i] == 1) {
    //             first = min(first, j);
    //             last = max(first, j);
    //         }
    //     }
    //     for(int j=first;j<=last;j++) {
    //         if(grid[j][i] != 1 and req[j][i] != 1) {
    //             req[j][i] = 1;
    //             essentials.emplace_back(j, i);
    //         }
    //     }
    // }

    for(int i=1;i<=4;i++) {
        for(int j=1;j<=5;j++) {
            if(grid[i][j] != 1 and req[i][j] != 1) {
                unmarked.emplace_back(i, j);
            }
        }
    }

    // debug() << imie(essentials) imie(marked) imie(unmarked);

    // for(int i=0;i<=(1 << int(unmarked.size()));i++) {
    //     // if(__builtin_popcount(i) > 20) {
    //     //     cout << i << nl;
    //     //     debug() << imie(__builtin_popcount(i));
    //     //     return;
    //     // }
    //     bits[__builtin_popcount(i)].push_back(i);
    // }
    // debug() << imie(bits);
    vector<pair<int,int>> empty;
    // if(verify(marked, essentials, empty)) {
    //     if(T == 1) {
    //         cout << N << " " << 1 << nl;
    //     }
    //     else {
    //         cout << N << nl;
    //     }
    //     return;
    // }
    vector<int> ans(21);
    int min_pt = 21;
    for(int i=0;i<(1 << unmarked.size());i++) {
        // if(__builtin_popcount(i) > min_pt) {
        //     continue;
        // }
        vector<pair<int,int>> random_points;
        for(int j=0;j<int(unmarked.size());j++) {
            if((i & (1 << j))) {
                random_points.pb(unmarked[j]);
            }
        }
        // if(verify(marked, empty, random_points) and __builtin_popcount(i) <= min_pt) {
        if(verify(marked, empty, random_points)) {
            ans[__builtin_popcount(i)]++;
            min_pt = __builtin_popcount(i);
        }
    }

    debug() << imie(ans);
    for(int i=0;i<21;i++) {
        if(ans[i] != 0) {
            if(T == 1) {
                cout << i + N << " " << ans[i] << nl;
            }
            else {
                cout << i + N << nl;
            }
            return;
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}