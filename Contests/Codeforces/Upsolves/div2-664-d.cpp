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

	long long n,m,d;
	cin >> n >> d >> m;
	vector<long long> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}

	sort(a.rbegin(),a.rend());
	long long ans = 0;

	debug() << imie(n) imie(d) imie(m);

	debug() << imie(a);

	// find the number of largest chunks that we can select
	int x = 0;
	for(int i=0;;i++) {
		if(a[i] > m) {
			x = i;
			ans+=a[i];
			if(((i+1) * (d+1) + 1) > n) {
				break;
			}
		}
		else {
			break;
		}
		
	}
	debug() << imie(ans);
	// (x-1)(d+1) + 1
	int smalls = n-((x) * (d + 1) + 1);
	debug() << imie(smalls);
	for(int i=0;i<n and smalls>0;i++) {
		if(a[i] <= m) {
			ans+=a[i];
			smalls--;
		}
	}
	cout << ans << '\n';

}