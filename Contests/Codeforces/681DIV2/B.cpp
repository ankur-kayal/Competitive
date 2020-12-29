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
		int a,b;
		cin >> a >> b;
		string s;
		cin >> s;
		s += '0';
		int n = s.length();
		int one = 0;
		int zero = -1;
		int ans = 0;
		vector<int> block;
		for(int i=0;i<n;i++) {
			if(s[i] == '0') {
				if(one > 0) {
					ans += a;
					one = 0;
				}
				zero++;
			}
			else {
				if(ans > 0) {
					if(zero > 0) {
						block.push_back(zero * b);
						zero = 0;
					}
				}
				zero = 0;
				one++;
			}
			debug() << imie(i) imie(s[i]) << imie(block);
		}
		debug() << imie(block);
		for(auto u: block) {
			if(u < a) {
				ans -= a;
				ans += u;
			}
		}

		cout << ans << '\n';
	}
}