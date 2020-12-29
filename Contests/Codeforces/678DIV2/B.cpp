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

void check(int tmp) {
	for(int i=2;i*i<=tmp;i++) {
		assert(tmp % i != 0);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int ans[n][n];
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				ans[i][j] = 0;
			}
		}
		for(int i=0;i<n;i++) {
			ans[i][i] = 4;
		}
		for(int i=0;i<n;i++) {
			ans[i][n-1-i] = 1;
		}
		if(n % 2 == 1) {
			ans[n/2][n/2] = 9;
			ans[n/2][n-1] = 8;
			ans[0][n/2] = 8;
		}
		for(int i=0;i<n;i++) {
			int tmp1 = 0;
			int tmp2 = 0;
			for(int j=0;j<n;j++) {
				tmp1 += ans[i][j];
				tmp2 += ans[j][i];
			}
			// debug() << imie(tmp1) imie(tmp2) ;
			check(tmp1);
			check(tmp2);
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				cout << ans[i][j] << " ";
			}
			cout << '\n';
		}
		
	}
}