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

vector<vector<int>> adj;
vector<int> w, p, high, low;
int ans = 0;

void dfs(int node, int par) {
	int mx = w[node];
	int mn = w[node];
	for(auto u : adj[node]) {
		if(u != par) {
			dfs(u, node);
			mx = max(mx, high[u]);
			mn = min(mn, low[u]);
			ans = max({ans, abs(high[u] - low[node]), abs(low[u] - high[node])});
		}
	}
	high[node] = mx;
	low[node] = mn;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	adj = vector<vector<int>>(n);
	w = vector<int>(n);
	p = vector<int>(n);
	high = vector<int>(n);
	low = vector<int>(n);
	for(int i=0;i<n;i++) {
		cin >> w[i];
		high[i] = w[i];
		low[i] = w[i];
	}
	int root;
	for(int i=0;i<n;i++) {
		int u;
		cin >> u;
		if(u == -1) {
			root = i;
		}
		else {
			--u;
			adj[i].push_back(u);
			adj[u].push_back(i);
		}
	}
	debug() << imie(root);
	dfs(root, -1);

	cout << ans << '\n';

}