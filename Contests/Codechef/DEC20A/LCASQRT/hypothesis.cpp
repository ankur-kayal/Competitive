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

    int p;
    cin >> p;
    int mx = -1;
    int val = -1;
    for(int target = 1;target < p;target++) {
        int cnt = 0;
        vector<int> ans;
        for(int i=1;i<p;i++) {
            if((i * i) % p == target) {
                cnt++;
                ans.push_back(i);
            }
        }
        if(cnt > mx) {
            mx = cnt;
            val = target;
        }
        if(ans.size() == 2) {
            if(ans[0] + ans[1] != p) {
                debug() << imie(ans);
            }
        }
        // debug() << imie(target) imie(cnt) imie(ans);   
    }
    debug() << imie(mx) imie(val);
}