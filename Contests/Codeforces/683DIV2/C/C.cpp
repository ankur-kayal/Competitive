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
        int64_t n,w;
        cin >> n >> w;
        vector<int64_t> a(n);
        vector<pair<int64_t, int64_t>> ord;
        for(int i=0;i<n;i++) {
            cin >> a[i];
            ord.emplace_back(a[i], i + 1);
        }
        sort(ord.rbegin(), ord.rend());
        vector<int> ans;
        int64_t s = 0;
        for(auto u: ord) {
            int64_t val = u.first;
            int index = u.second;
            if(s + val <= w) {
                s += val;
                ans.push_back(index);
            }
        }
        if(s < (w + 1) / 2) {
            cout << -1 << '\n';
        }
        else {
            cout << ans.size() << '\n';
            for(auto u: ans) {
                cout << u << ' ';
            }
            cout << '\n';
        }
    }	
}