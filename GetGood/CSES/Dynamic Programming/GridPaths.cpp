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

const int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<vector<char>> grid(n,vector<char>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> grid[i][j];
		}
	}

	vector<vector<int>> dp(n, vector<int>(n,0));
	vector<vector<int>> used(n, vector<int>(n,0));


	queue<pair<int,int>> q;
	if(grid[0][0] == '.') {
		q.push({0,0});
		dp[0][0] = 1;
	}
	while(!q.empty()) {
		pair<int,int> ele = q.front();
		q.pop();
		int x = ele.first, y = ele.second;
		// check right cell
		if(y + 1 < n and grid[x][y+1] == '.') {
			dp[x][y + 1] = (dp[x][y+1] + dp[x][y])%mod;
			if(used[x][y + 1] == 0) {
				used[x][y + 1] = 1;
				q.push(make_pair(x,y+1));
			}
		}
		// check down cell
		if(x + 1 < n and grid[x+1][y] == '.') {
			dp[x+1][y] = (dp[x+1][y] + dp[x][y])%mod;
			if(used[x+1][y] == 0) {
				used[x+1][y] = 1;
				q.push(make_pair(x+1,y));
			}
		}
	}
	cout << dp[n-1][n-1] << '\n';
}