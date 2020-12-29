// problem link -> https://codeforces.com/problemset/problem/729/B

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

	int n,m;
	cin >> n >> m;
	vector<vector<int>> grid(n,vector<int>(m));
	vector<vector<int>> dp(n,vector<int>(m,0));
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			cin >> grid[i][j];
		}
	}
	// left and right operations
	for(int i=0;i<n;i++) {
		// or current row
		int cnt = 0;
		for(int j=0;j<m;j++) {
			cnt |= grid[i][j];
			dp[i][j] += cnt;
		}

		cnt = 0;
		for(int j=m-1;j>=0;j--) {
			cnt |= grid[i][j];
			dp[i][j] += cnt;
		}
	}

	// top and down operations

	for(int j=0;j<m;j++) {
		// for current column
		int cnt = 0;
		for(int i=0;i<n;i++) {
			cnt |= grid[i][j];
			dp[i][j] += cnt;
		}

		cnt = 0;
		for(int i=n-1;i>=0;i--) {
			cnt |= grid[i][j];
			dp[i][j] += cnt;
		}
	}

	int ans = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(grid[i][j] == 0) {
				ans+=dp[i][j];
			}
		}
	}
	cout << ans << '\n';
}