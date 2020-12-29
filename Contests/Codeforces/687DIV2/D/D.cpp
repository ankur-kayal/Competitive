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

int msb(int &num) {
	return 32 - __builtin_clz(num) - 1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}

	for(int i=1;i<n-1;i++) {
		if(msb(a[i]) == msb(a[i - 1]) and msb(a[i]) == msb(a[i + 1])) {
			cout << 1;
			exit(0);
		}
	}

	int ans = 1e9;
	for(int l=0;l<n;l++) {
		for(int r=l+2;r<n;r++) {
			for(int m=l;m<r;m++) {
				int left = 0, right = 0;
				for(int k=l;k<=m;k++) {
					left ^= a[k];
				}
				for(int k=m+1;k<=r;k++) {
					right ^= a[k];
				}
				if(left > right) {
					ans = min(ans, r - l - 1);
				}
				// debug() << imie(left) imie(right);
			}
		}
	}

	cout << (ans == int(1e9) ? -1 : ans) << '\n';
}