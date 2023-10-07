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

void run_cases() {
    int N, L, K;
    cin >> N >> L >> K;

    vector<int64_t> D(N);
    for(auto &u: D)
        cin >> u;

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    D.push_back(L);

    const int64_t INF64 = 1e18;

    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(K + 1, INF64));

    dp[0][0] = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k + j <= K && i + k + 1 <= N; k++) {
                dp[i + k + 1][j + k] = min(dp[i + k + 1][j + k], dp[i][j] + A[i] * (D[i + k + 1] - D[i]));
            }
        }
    }

    int64_t ans = INF64;

    for(int i = 0; i <= K; i++) {
        ans = min(ans, dp[N][i]);
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}