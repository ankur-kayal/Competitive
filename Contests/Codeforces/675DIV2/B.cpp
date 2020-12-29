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
		long long n,m, row, col;
		cin >> n >> m;
		long long grid[n][m];

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				cin >> grid[i][j];
			}
		}
		// if(n % 1) {
		// 	row = n + 1;

		// }
		long long ans = 0;
		for(int i=0;i<((n+1)/2);i++) {
			for(int j=0;j<((m+1)/2);j++) {
				long long a=0,b=0,c=0,d=0, sum1 = 0, sum2 = 0;
				if(i != n-i-1 and j != m-j-1) {
					vector<long long> v;
					v.push_back(grid[i][j]);
					v.push_back(grid[n-i-1][j]);
					v.push_back(grid[i][m-j-1]);
					v.push_back(grid[n-i-1][m-j-1]);
					sort(v.begin(), v.end());
					long long m = (v[1] + v[2]) / 2;
					ans += abs(v[0]-m) + abs(v[1]-m) + abs(v[2]-m) + abs(v[3]-m);
				}
				else if(i == n-i-1 and j != m-j-1) {
					a = grid[i][j];
					b = grid[i][m-j-1];
					long long m = (a + b) / 2;
					sum1 = abs(a-m) + abs(b-m);
					sum2 = abs(a-m-1) + abs(b-m-1);
					ans += min(sum1, sum2);
				}
				else if(i != n-i-1 and j == m-j-1) {
					a = grid[i][j];
					b = grid[n-i-1][j];
					long long m = (a + b) / 2;
					sum1 = abs(a-m) + abs(b-m);
					sum2 = abs(a-m-1) + abs(b-m-1);
					ans += min(sum1, sum2);
				}
				debug() << imie(sum1) imie(sum2);
			}
		}
		cout << ans << '\n';
	}
}