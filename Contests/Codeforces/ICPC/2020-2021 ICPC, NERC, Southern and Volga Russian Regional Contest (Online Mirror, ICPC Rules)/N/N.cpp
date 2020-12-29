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
        vector<int> c(4);
        vector<int> trash(4, 0);
        for(int i=1;i<=3;i++) {
            cin >> c[i];
        }
        vector<int> a(6);
        for(int i=1;i<=5;i++) {
            cin >> a[i];
        }


        bool ok = true;
        trash[1] = min(c[1], a[1]);
        a[1] -= trash[1];

        trash[2] = min(c[2], a[2]);
        a[2] -= trash[2];

        trash[3] = min(c[3], a[3]);
        a[3] -= trash[3];

        int parpaper = min(c[1] - trash[1], a[4]);
        a[4] -= parpaper;
        trash[1] += parpaper;

        parpaper = min(c[3] - trash[3], a[4]);
        a[4] -= parpaper;
        trash[3] += parpaper;

        int parplastic = min(c[2] - trash[2], a[5]);
        a[5] -= parplastic;
        trash[2] += parplastic;

        parplastic = min(c[3] - trash[3], a[5]);
        a[5] -= parplastic;
        trash[3] += parplastic;

        // debug() << imie(trash);
        // debug() << imie(a);
        for(int i=1;i<=5;i++) {
            if(a[i] > 0) {
                ok = false;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}