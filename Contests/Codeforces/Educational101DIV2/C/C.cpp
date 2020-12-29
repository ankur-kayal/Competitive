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

array<int,2> intersect(const array<int,2> &a, const array<int,2> &b) {
    return {max(a[0], b[0]), min(a[1], b[1])};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<int> h(n);
        for(int i=0;i<n;i++) {
            cin >> h[i];
        }
        array<int,2> range = {h[0], h[0] + 1};
        for(int i=1;i<n;i++) {
            range[0] -= (k - 1);
            range[1] += (k - 1);
            array<int,2> nrange = {h[i], h[i] + k};
            range = intersect(range, nrange);
            if(range[0] >= range[1]) {
                break;
            }
        }
        debug() << imie(range);
        cout << (range[0] <= h.back() and h.back() < range[1] ? "YES" : "NO") << '\n';
    }
}