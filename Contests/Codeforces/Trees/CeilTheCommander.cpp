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

struct CentroidDecomposition {
	vector<vector<int>> edges;
	vector<vector<int>> adj;
	vector<bool> vis;
	vector<int> par;
	vector<int> sz;
	vector<int> level;
	vector<int> color;
	int root;
	int n;

	void init(int s) {
		n = s;
		edges = vector<vector<int>>(n, vector<int>());
		vis = vector<bool>(n, false);
		par = vector<int>(n);
		sz = vector<int>(n);
		adj = vector<vector<int>>(n, vector<int>());
		level = vector<int>(n);
		color = vector<int>(n);
	}

	void addEdge(int a, int b) {
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int findSize(int v, int p = -1) {
		if(vis[v]) return 0;
		sz[v] = 1;

		for(auto u: edges[v]) {
			if(u != p) {
				sz[v] += findSize(u,v);
			}
		}
		return sz[v];
	}

	int findCentroid(int v, int p, int cap) {
		for(auto u: edges[v]) {
			if(u != p) {
				if(!vis[u] and sz[u] > cap / 2) {
					return findCentroid(u, v, cap);
				}
			}
		}
		return v;
	}

	void initCentroid(int v = 0, int p = -1) {
		findSize(v);

		int c = findCentroid(v, -1, sz[v]);
		debug() << imie(c);
		if(p == -1) {
			root = c;
		}
		if(p != -1) {
			adj[v].push_back(p);
			adj[p].push_back(v);
		}
		vis[c] = true;
		par[c] = p;

		for(auto u: edges[c]) {
			if(!vis[u]) {
				initCentroid(u, c);
			}
		}
	}

	void dfs(int node, int p) {
		color[node] = color[p] + 1;
		debug() << imie(node) imie(color[node]);
		level[node] = level[p] + 1;
		for(auto u: adj[node]) {
			if(u != p) {
				dfs(u, node);
			}
		}
	}

	void compute() {
		color[root] = -1;
		level[root] = -1;
		dfs(root, root);
	}
};

CentroidDecomposition cd;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	cd.init(n);
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin >> u >> v;
		--u; --v;
		cd.addEdge(u,v);
	}
	debug() << imie(cd.edges);
	// exit(0);
	cd.initCentroid();
	// cout  << "Initialised CentroidDecomposition Done!";
	// exit(0);
	cd.compute();
	debug() << imie(cd.adj);
	// cout << *max_element(cd.level.begin(), cd.level.end());
	if(*max_element(cd.level.begin(), cd.level.end()) > 25) {
		cout << "Impossible!" << '\n';
	}
	else {
		for(auto u: cd.color) {
			cout << char(u + 'A') << ' ';
		}
	}
}