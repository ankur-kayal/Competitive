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

	const int maxN = 1e5+10;
	vector<int> t(maxN), x(maxN), y(maxN), ans(maxN), res(maxN);
	x[0] = y[0] = 1;

	int r,n;
	cin >> r >> n;
	for(int i=1;i<=n;i++) {
		cin >> t[i] >> x[i] >> y[i];
		ans[i] = -1e9;

		for(int j=max(0,i-2*r);j<i;j++) {
			if(abs(x[i]-x[j]) + abs(y[i]-y[j]) <= t[i] - t[j]) {
				ans[i] = max(ans[i], 1 + ans[j]);
			}
		}
		if(i > 2*r) {
			ans[i] = max(ans[i], 1 + res[i-2*r]);
		}
		res[i] = max(ans[i], res[i-1]);
	}
	cout << res[n] << '\n';

	
}