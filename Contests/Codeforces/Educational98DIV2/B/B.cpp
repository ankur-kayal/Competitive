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

// int
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int64_t> a(n);
		int64_t sum = 0;
		for(int i=0;i<n;i++) {
			cin >> a[i];
			sum += a[i];
		}
		vector<int64_t> sufmax(n);
		sufmax[n-1] = a[n-1];
		for(int i=n-2;i>=0;i--) {
			sufmax[i] = max(sufmax[i + 1], a[i]);
		}
		// debug() << imie(sufmax);
		int64_t curmax = -1;
		int64_t mx = -1;
		int64_t ans = 0;
		int64_t sm = 0;
		for(int i=0;i<n;i++) {
			mx = max(curmax, i + 1 < n ? sufmax[i + 1] : -1);
			int64_t tot = sum - a[i];
			int64_t needed = mx * (n - 1) - tot;
			// needed %= (n - 1);
			debug() << imie(needed);
			if(needed >= a[i]) {
				needed -=a[i];
			}
			else {
				needed = (a[i] - needed) % (n - 1);
				if(needed > 0) {
					needed = n - 1 - needed;
				}
			}
			ans = max(ans, abs(needed));
			debug() << imie(mx) imie(ans) imie(curmax) imie(tot) imie(needed);
			curmax = max(curmax, a[i]);
		}
		cout << ans << '\n';
	}
}