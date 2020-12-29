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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int64_t t;
    cin >> t;
    while(t--) {
        int64_t n, p, k;
        cin >> n >> p >> k;
        vector<int64_t> a(n + 1);
        for(int64_t i=1;i<=n;i++) {
            char ch;
            cin >> ch;
            a[i] = (ch - '0');
        }
        int64_t x,y;
        cin >> x >> y;
        int64_t ans = 1e18;
        vector<int64_t> dp(n + 1, 0);
        for(int i = n; i >= 1;i--) {
            if(a[i] == 0) {
                dp[i] = 1;
            } 
            if(i + k <= n) {
                dp[i] += dp[i + k];
            }
        }
        debug() << imie(dp);
        for(int64_t i=0;i<=n-p;i++) {
            ans = min(ans, i * y + dp[p + i] * x);
        }
        cout << ans << '\n';
    }
}