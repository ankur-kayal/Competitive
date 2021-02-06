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

//----------------------------------- END DEFINES -------------------------------- 

void run_cases() {
    int n;
    cin >> n;
    vector<int64_t> c(n), a(n), b(n);
    trav(u, c) cin >> u;
    trav(u, a) cin >> u;
    trav(u, b) cin >> u;
    reverse(all(c));
    reverse(all(a));
    reverse(all(b));
    debug() << imie(c) << nl << imie(a) << nl << imie(b);
    int64_t ans = 0;
    int64_t chain = c[n-1] - 1;
    vector<vector<int64_t>> dp(n, vector<int64_t>(2,0));
    // 0 -> dont extend to the next level
    // 1 -> extend to the next level
    dp[0][0] = 0;
    dp[0][1] = c[0] - 1;
    for(int i=0;i<n-1;i++) {
        if(a[i] > b[i]) {
            swap(a[i], b[i]);
        }
        // don't extend
        dp[i+1][0] = max(c[i] - 1, dp[i][1]) + abs(a[i] - b[i]) + 2;

        // try extending
        if(a[i] != b[i]) {
            int64_t val1 = c[i] - 1;
            dp[i+1][1] = max(dp[i][1], c[i] - 1) + 2 + a[i] - 1 + (c[i+1] - b[i]);
            if(i == n - 2) {
                dp[i+1][1] = dp[i+1][0];
            }
            // debug() << imie(c[i] - 1) imie(dp[i][1]) imie(a[i]) imie(c[i+1]) imie(b[i]);
        }
        
        debug() << imie(dp);
    }

    debug() << imie(dp);
    for(int i=0;i<n;i++) {
        ans = max({ans, dp[i][0], dp[i][1]});
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}