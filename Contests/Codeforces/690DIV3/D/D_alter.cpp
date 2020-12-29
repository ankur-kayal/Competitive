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

        int64_t ans = n - 1;
        int64_t target = 0;
        for(int i=0;i<n-1;i++) {
            target += a[i];
            int64_t tmp = 0;
            int64_t moves = 0;
            for(int j = i + 1; j < n; j++) {
                tmp += a[j];
                if(tmp == target) {
                    tmp = 0;
                }
                else if(tmp > target) {
                    moves += 1000000000;
                    break;
                }
                else {
                    moves++;
                }
            }
            if(tmp == target) {
                moves++;
            }
            else if(tmp != 0) {
                moves += 1000000000;
            }
            ans = min(ans, moves + i);
            debug() << imie(ans) imie(target);
        }

        cout << ans << '\n';
    }
}