#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
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

    cout << setprecision(10) << fixed;

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        for(auto &u: a) {
            cin >> u;
        }

        double ans = 0;
        double anti = 1;

        int index = n;
        for(int i=n-1;i>=0;i--) {
            if(a[i] == index) {
                index--;
            }
            else {
                break;
            }
        }
        while(m--) {
            int r;
            double p;
            cin >> r >> p;
            if(r >= index) {
                ans += anti * p;
                anti *= (1 - p);
            }

        }

        if(index == 0) {
            cout << (double)1 << '\n';
        }
        else {
            cout << ans << '\n';
        }

    }
}