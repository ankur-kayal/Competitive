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

const int maxN = 3e5+10;
const int logN = ceil(log2(maxN));
const int inf = 1e9+10;

vector<vector<pair<int,int>>> adj(maxN,vector<pair<int,int>>());
vector<vector<int>> lca(maxN, vector<int>(logN, -1));
vector<vector<int>> flow(maxN, vector<int>(logN, inf));
vector<int> p(maxN), d(maxN), weight(maxN, inf);

void dfs(int node, int par, int depth) {
	p[node] = par;
	lca[node][0] = par;
	d[node] = depth;

	for(auto u: adj[node]) {
		int child = u.first;
		if(child != par) {
			flow[child][0] = u.second;
			weight[child] = u.second;
			dfs(child, node, depth + 1);
		}
	} 
}

void init_lca() {
	dfs(0, -1, 0);
	for(int j=1;j<logN;j++) {
		for(int i=0;i<maxN;i++) {
			if(lca[i][j-1] != -1) {
				int par = lca[i][j-1];
				lca[i][j] = lca[par][j-1];
				flow[i][j] = min({flow[i][j-1], flow[i][j], flow[par][j-1]});
			}
		}
	}
}

int get_flow(int u, int v) {

	if(d[u] > d[v]) {
		swap(u,v);
	}
	int ans = weight[v];

	int diff = d[v] - d[u];

	while(diff > 0) {
		int i = log2(diff);
		ans = min(ans, flow[v][i]);
		v = lca[v][i];
		diff -= (1LL<<i);
		// debug() << imie(v) imie(ans);
	}

	if(u == v) {
		// ans = min({ans, weight[u], weight[v]});
		return ans;
	}

	for(int i=logN-1;i>=0;i--) {
		if(lca[u][i] != -1 and lca[u][i] != lca[v][i]) {
			ans = min({ans, flow[u][i], flow[v][i]});
			u = lca[u][i];
			v = lca[v][i];
		}
	}
	ans = min({ans, flow[u][0], flow[v][0]});
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		--u;--v;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}


	init_lca();
	// for(int i=0;i<n;i++) {
	// 	debug() << imie(flow[i]);
	// }
	int q;
	cin >> q;
	while(q--) {
		int a,b;
		cin >> a >> b;
		--a;--b;
		int ans = get_flow(a,b);
		assert(ans != inf);
		cout << get_flow(a,b) << '\n';
	}
}