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

const int64_t INF64 = 2e18;

void run_cases() {
    
    int N, P, M, Ar, Ac;

    cin >> N >> P >> M >> Ar >> Ac;
    --Ar, --Ac;

    vector<pair<char, int64_t>> ops(4);
    for(int i = 0; i < 4; i++) {
        cin >> ops[i].first >> ops[i].second;
    }

    assert(P == 0);

    vector<vector<bool>> touched(N, vector<bool>(N, false));
    touched[Ar][Ac] = true;


    vector<vector<int64_t>> cost(N, vector<int64_t>(N, -INF64));
    cost[Ar][Ac] = 0;

    int64_t ans = 0;

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, 1, -1, 0};

    for(int t = 0; t < M; t++) {

        vector<vector<int64_t>> new_cost(N, vector<int64_t>(N, -INF64));
        for(int x = 0; x < N; x++) {
            for(int y = 0; y < N; y++) {
                if(touched[x][y]) {
                    for(int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if(0 <= nx && nx < N && 0 <= ny && ny < N) {
                            char op = ops[k].first;

                            switch(op) {
                                case '+':
                                    new_cost[nx][ny] = max(new_cost[nx][ny], cost[x][y] + ops[k].second);
                                    break;
                                case '-':
                                    new_cost[nx][ny] = max(new_cost[nx][ny], cost[x][y] - ops[k].second);
                                    break;
                                case '/':
                                    new_cost[nx][ny] = max(new_cost[nx][ny], int64_t(floor(cost[x][y] / double(ops[k].second))));
                                    break;
                                case '*':
                                    new_cost[nx][ny] = max(new_cost[nx][ny], cost[x][y] * ops[k].second);
                                    break;
                            }
                        }
                    }
                }
            }
        }

        // debug() << imie(new_cost);

        for(int x = 0; x < N; x++) {
            for(int y = 0; y < N; y++) {
                cost[x][y] = max(cost[x][y], new_cost[x][y]);
                ans = max(ans, cost[x][y]);
                if(cost[x][y] != -INF64) {
                    touched[x][y] = true;
                }
            }
        }
        debug() << imie(ans);
    }



    cout << ans << '\n';

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