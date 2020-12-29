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

    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int64_t> t(n), x(n);
        t.push_back(1000000000000);
        for(int i=0;i<n;i++) {
            cin >> t[i] >> x[i];
        }

        int64_t dest = 0;
        int64_t curr = 0;
        int64_t flag = 0;
        int ans = 0;
        for(int i=0;i<n;i++) {
            if(curr == dest) {
                dest = x[i];
            }
            int64_t tmp = curr;
            int mul;
            if(dest >= curr) {
                mul = 1;

            }
            else {
                mul = -1;
            }
            curr = curr + mul * min((t[i + 1] - t[i]), abs(dest - curr));
            int64_t high = max(tmp, curr);
            int64_t low = min(tmp, curr);
            // debug() << imie(high) imie(low);
            if(low <= x[i] and x[i] <= high) {
                ans++;
            }
            // debug() << imie(curr);
        }
        // debug() << imie(curr) imie(dest);

        cout << ans << '\n';

    }
}