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

void verify(int n, int m, vector<vector<int>> &a) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			assert(a[i][j] == 0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n,m;
		cin >> n >> m;
		vector<vector<int>> a(n, vector<int>(m));
		vector<array<int, 6>> ans;

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				char ch;
				cin >> ch;

				a[i][j] = ch - '0';
			}
		}
		// debug() << imie(a);
		
		for(int i=n-1;i>=2;i--) {
			for(int j=m-1;j>=0;j--) {
				if(a[i][j]) {
					ans.push_back({i, j, i - 1, j, i - 1, j ? j - 1: j + 1});
					a[i][j] ^= 1;
					a[i - 1][j] ^= 1;
					a[i - 1][j ? j - 1: j + 1] ^= 1;
				}
			}
		}
		for(int j=m-1;j>=2;j--) {
			if(a[0][j] and a[1][j]) {
				ans.push_back({0, j, 1, j, 0, j - 1});
				a[0][j] ^= 1;
				a[1][j] ^= 1;
				a[0][j - 1] ^= 1;
			} else if(a[0][j]) {
				ans.push_back({0, j, 1, j - 1, 0, j - 1});
				a[0][j] ^= 1;
				a[1][j - 1] ^= 1;
				a[0][j - 1] ^= 1;
			} else if(a[1][j]) {
				ans.push_back({1, j, 1, j - 1, 0, j - 1});
				a[1][j] ^= 1;
				a[1][j - 1] ^= 1;
				a[0][j - 1] ^= 1;
			} else  {
				// already work done
			}
		}
		
		if(a[1][1] ^ a[0][1] ^ a[1][0]) {
			ans.push_back({0,1,1,0,1,1});
			a[0][1] ^= 1;
			a[1][1] ^= 1;
			a[1][0] ^= 1;
		}
		if(a[0][0] ^ a[0][1] ^ a[1][0]) {
			ans.push_back({0,0,0,1,1,0});
			a[0][0] ^= 1;
			a[0][1] ^= 1;
			a[1][0] ^= 1;
		}
		if(a[0][0] ^ a[0][1] ^ a[1][1]) {
			ans.push_back({0,0,0,1,1,1});
			a[0][0] ^= 1;
			a[1][1] ^= 1;
			a[0][1] ^= 1;
		}
		if(a[0][0] ^ a[1][0] ^ a[1][1]) {
			ans.push_back({0,0,1,0,1,1});
			a[0][0] ^= 1;
			a[1][1] ^= 1;
			a[1][0] ^= 1;
		}
		

		// assert((int)ans.size() <= n * m);
		debug() << imie((int)ans.size()) imie(n * m);
		verify(n, m, a);
		cout << ans.size() << '\n';
		for(auto u: ans) {
			for(auto v: u) {
				cout << v + 1 << " ";
			}
			cout << '\n';
		}
		// for(int i=0;i<n;i++) {
		// 	for(int j=0;j<m;j++) {
		// 		cout << a[i][j];
		// 	}
		// 	cout << '\n';
		// }
	}
}