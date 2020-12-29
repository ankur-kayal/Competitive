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

	int h,w,m,n;
	cin >> h >> w >> n >> m;
	vector<vector<int>> grid(h+1, vector<int>(w+1,-1));

	// 1 denotes bulb, 2 denotes block

	for(int i=1;i<=n;i++) {
		int u,v;
		cin >> u >> v;
		grid[u][v] = 1;
	}

	for(int j=1;j<=m;j++) {
		int u,v;
		cin >> u >> v;
		grid[u][v] = 2;
	}


	int ans = 0;
	for(int i=1;i<=h;i++) {
		for(int j=1;j<=w;j++) {
			if(grid[i][j] == 0 or grid[i][j] == 1) {
				ans++;
			}
		}
	}

	cout << ans << '\n';
}