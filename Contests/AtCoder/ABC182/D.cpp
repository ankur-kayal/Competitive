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

	long long ans = 0;
	int n;
	long long score = 0;
	cin >> n;
	vector<long long> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	vector<long long> pref(n), best(n,0);
	pref[0] = a[0];
	best[0] = max(0LL, a[0]);
	long long increase = 0;
	for(int i=1;i<n;i++) {
		pref[i] = pref[i-1] + a[i];
		best[i] = max(best[i-1], pref[i]);
	}
	long long coor = 0;
	for(int i=0;i<n;i++) {
		ans = max(ans, coor + best[i]);
		coor = coor + pref[i];
	}
	cout << ans << '\n';
}