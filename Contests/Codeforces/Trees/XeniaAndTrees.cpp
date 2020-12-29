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
#include <bits/stdc++.h>
using namespace std;


struct LCABinaryLift {
	int lg;
	int n;
	vector<int> depth;
	vector<vector<int>> edges;
	vector<vector<int>> lift;

	void init(int sz) {
		n = sz;
		lg = ceil(log2(sz));
		depth = vector<int>(n);
		edges = vector<vector<int>>(n, vector<int>());
		lift = vector<vector<int>>(n, vector<int>(lg, -1));
	}

	void addEdge(int a, int b) {
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	void initLift(int v = 0) {
		depth[v] = 0;
		dfs(v, -1);

		for(int j=1;j<lg;j++) {
			for(int i=0;i<n;i++) {
				if(lift[i][j-1] != -1) {
					int par = lift[i][j-1];
					lift[i][j] = lift[par][j-1];
				}
			}
		}
	}

	void dfs(int v, int par) {
		lift[v][0] = par;
		for(auto u: edges[v]) {
			if(u != par) {
				depth[u] = depth[v] + 1;
				dfs(u, v);
			}
		}
	}

	int getKthAncestor(int v, int k) {
		for(int i=lg-1;i>=0;i--) {
			if(v == -1) return v;

			if((1 << i) <= k) {
				v = lift[v][i];
				k -= (1 << i);
			}
		}
		return v;
	}

	int getLCA(int a, int b) {
		if(depth[a] < depth[b]) swap(a,b);
		int d = depth[a] - depth[b];
		int v = getKthAncestor(a,d);

		if(v == b) {
			return v;
		}
		else {
			for(int i=lg-1;i>=0;i--) {
				if(lift[v][i] != lift[b][i]) {
					v = lift[v][i];
					b = lift[b][i];
				}
			}
			return lift[b][0];
		}
	}

	int getDistance(int a, int b) {
		int v = getLCA(a,b);
		return depth[a] + depth[b] - 2 * depth[v];
	}
};

struct CentroidDecomposition {
	vector<vector<int>> edges;
	vector<bool> vis;
	vector<int> par;
	vector<int> sz;
	int n;

	void init(int s) {
		n = s;
		edges = vector<vector<int>>(n, vector<int>());
		vis = vector<bool>(n, false);
		par = vector<int>(n);
		sz = vector<int>(n);
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
		vis[c] = true;
		par[c] = p;

		for(auto u: edges[c]) {
			if(!vis[u]) {
				initCentroid(u, c);
			}
		}
	}
};

LCABinaryLift lc;
CentroidDecomposition cd;
const int maxN = 2e5;
const int inf = 1e9 + 7;
vector<int> closest;

void upd(int v) {
	closest[v] = 0;
	int u = v;
	while(cd.par[u] != -1) {
		u = cd.par[u];
		assert(u != -1);
		int d = lc.getDistance(v, u);
		closest[u] = min(closest[u], d);
	}
}

void query(int v) {
	int ans = closest[v];
	int u = v;
	while(cd.par[u] != -1) {
		u = cd.par[u];
		assert(u != -1);
		int d = lc.getDistance(v, u);
		ans = min(ans, d + closest[u]);
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin >> n >> m;
	lc.init(n);
	cd.init(n);
	for(int i=0;i<n-1;i++) {
		int a,b;
		cin >> a >> b;
		--a; --b;
		lc.addEdge(a,b);
		cd.addEdge(a,b);
	}

	lc.initLift();
	cd.initCentroid();
	closest.assign(maxN, inf);
	upd(0);

	for(int i=0;i<m;i++) {
		int ch, v;
		cin >> ch >> v;
		--v;
		if(ch == 1) {
			upd(v);
		}
		else {
			query(v);
		}
	}
}