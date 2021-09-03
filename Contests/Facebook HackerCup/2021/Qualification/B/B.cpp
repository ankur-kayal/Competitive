#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


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

const int inf = 1e9;

void run_cases() {
    int N;
    cin >> N;

    vector<vector<char>> grid(N, vector<char>(N, '#'));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    set<vector<pair<int,int>>> points;

    for(int i = 0; i < N; i++) {
        vector<pair<int,int>> curr;
        int X = 0;
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == '.') {
                curr.emplace_back(i, j);
                X++;
            } else if(grid[i][j] == 'X') {
                X++;
            }
        }
        sort(curr.begin(), curr.end());
        if(X == N) {
            points.insert(curr);
        }
    }

    for(int i = 0; i < N; i++) {
        vector<pair<int,int>> curr;
        int X = 0;
        for(int j = 0; j < N; j++) {
            if(grid[j][i] == '.') {
                curr.emplace_back(j, i);
                X++;
            } else if(grid[j][i] == 'X') {
                X++;
            }
        }
        sort(curr.begin(), curr.end());
        if(X == N) {
            points.insert(curr);
        }
    }

    int min_size = inf;
    for(auto u: points) {
        min_size = min(min_size, int(u.size()));
    } 

    int ways = 0;

    for(auto u: points) {
        if(u.size() == min_size) {
            ways++;
        }
    }

    if(min_size == inf) {
        cout << "Impossible" << '\n';
    } else {
        cout << min_size << " " << ways << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("b_validation_input.txt", "r", stdin);
    // freopen("b_validation_output.txt", "w", stdout);

    /*For final submit*/
    freopen("b_final_input.txt", "r", stdin);
    freopen("b_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}