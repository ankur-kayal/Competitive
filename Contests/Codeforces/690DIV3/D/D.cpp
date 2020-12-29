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

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        vector<int64_t>prefix(n), suffix(n);
        prefix[0] = a[0];
        for(int i=1;i<n;i++) {
            prefix[i] = prefix[i-1] + a[i];
        }
        suffix[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--) {
            suffix[i] = suffix[i+1] + a[i];
        }

        int val = a[0];
        bool all_equal = true;
        for(int i=0;i<n;i++) {
            if(a[i] != val) {
                all_equal = false;
            }
        }

        if(all_equal) {
            cout << 0 << '\n';
        }
        else {
            int ans = n-1;

            for(int i=0;i<n-1;i++) {
                if(prefix[i] == suffix[i+1]) {
                    ans = n - 2;
                }
            }
            cout << ans << '\n';
        }
    }
}