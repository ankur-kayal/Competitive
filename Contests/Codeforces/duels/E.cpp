#include <bits/stdc++.h>
#include <stdint.h>
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

int64_t find_index(vector<int64_t> &d, int64_t cost) {
    int l = 0, r = (int)d.size();
    while(r > l + 1) {
        int64_t m = (l + r) / 2;
        if(d[m] <= cost) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int64_t n,m,k,x,s;
    cin >> n >> m >> k;
    cin >> x >> s;
    vector<int64_t> a(m), b(m), c(k + 1, 0), d(k + 1, 0);
    for(int i=0;i<m;i++) {
        cin >> a[i];
    }
    for(int i=0;i<m;i++) {
        cin >> b[i];
    }
    for(int i=1;i<=k;i++) {
        cin >> c[i];
    }
    for(int i=1;i<=k;i++) {
        cin >> d[i];
    }

    int64_t ans = n * x;
    for(int i=0;i<m;i++) {
        int64_t rem = s - b[i];
        if(rem >= 0) {
            ans = min(ans, (n - c[find_index(d, rem)]) * a[i]);
        }
    }
    for(int i=1;i<=k;i++) {
        if(d[i] <= s) {
            ans = min(ans, max(0LL, n - c[i]) * x);
        }
    }
    cout << ans << '\n';
}