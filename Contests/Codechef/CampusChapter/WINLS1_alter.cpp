#include <algorithm>
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

    int n;
    cin >> n;
    vector<int> val(n + 1);
    int marker = 0;
    set<int> st;
    for(int i=n;i>=1;i--) {
        val[i] = marker;
        st.insert(marker);
        marker++;
    }
    debug() << imie(st);
    int q;
    cin >> q;
    while(q--) {
        int tmp;
        cin >> tmp;
        cout << n - (lower_bound(st.begin(), st.end(), tmp) - st.begin()) - 1 << " ";
        st.erase(st.find(val[tmp]));
        val[tmp] = marker;
        st.insert(marker);
        marker++;
        debug() << imie(val); 
        debug() << imie(st);
        debug() << imie(st.size());
        // assert(st.size() == n);
    }
}