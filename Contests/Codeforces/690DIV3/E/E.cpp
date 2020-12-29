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

#define int int64_t

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        vector<int> cnt(n+10);
        // map<int,int> cnt;
        for(int i=0;i<n;i++) {
            cnt[a[i]]++;
        }
        // debug() << imie(cnt);
        int64_t ans = 0;
        for(int i=1;i<=n;i++) {
            if(cnt[i] >= 1 and cnt[i + 1] >= 1 and cnt[i + 2] >= 1)
                ans += cnt[i] * cnt[i + 1] * cnt[i + 2];
            // debug() << imie(ans);
            ans += (cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6);
            // debug() << imie(ans);
            if(cnt[i+1] + cnt[i] >= 3) {
                ans += (cnt[i] * (cnt[i] - 1) / 2) * cnt[i + 1] + cnt[i] * (cnt[i+1] * (cnt[i+1] - 1) / 2);
            }
            // debug() << imie(ans);
            if(cnt[i + 2] + cnt[i] >= 3) {
                ans += (cnt[i] * (cnt[i] - 1) / 2) * cnt[i + 2] + cnt[i] * (cnt[i+2] * (cnt[i+2] - 1) / 2);
            }
            // debug() << imie(i) imie(ans);
            // break;
        }
        cout << ans << '\n';
    }
}