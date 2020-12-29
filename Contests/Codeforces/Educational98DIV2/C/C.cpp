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
		string s;
		cin >> s;
		int o1 = 0, c1 = 0, o2 = 0, c2 = 0;
		int ans = 0;
		for(auto u: s) {
			if(u == '(') {
				o1++;
			}
			if(u == ')') {
				c1++;
			}
			if(u == '[') {
				o2++;
			}
			if(u == ']') {
				c2++;
			}
			if(c1 > 0 and o1 == 0) {
				c1--;
			}
			if(c2 > 0 and o2 == 0) {
				c2--;
			}
			if(c1 > 0 and o1 > 0) {
				ans++;
				c1--;
				o1--;
			}
			if(c2 > 0 and o2 > 0) {
				ans++;
				o2--;
				c2--;
			}
		}
		cout << ans << '\n';
	}
}