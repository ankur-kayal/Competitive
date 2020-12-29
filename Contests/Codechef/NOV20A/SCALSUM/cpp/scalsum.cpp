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

#define int64_t unsigned int

vector<int64_t> w, dot, level, mark, p;
vector<vector<int>> adj, nodesAtEachLevel;
vector<bool> precomputed;
vector<vector<int64_t>> cache;

void dfs(int node, int par) {
	p[node] = par;
	dot[node] = w[node] * w[node];
	if(par != -1) {
		dot[node] +=dot[par];
		level[node] = level[par] + 1;
	}
	for(auto child: adj[node]) {
		if(child != par) {
			dfs(child, node);
		}
	}
}

int64_t query(int u, int v) {
	int64_t ans = 0;
	while(u != v and !precomputed[u]) {
		ans = ans + w[u] * w[v]; 
		u = p[u];
		v = p[v];
	}
	if(u == v) {
		ans += dot[u];
	} else {
		ans = ans + cache[level[u]][mark[u] * (int)nodesAtEachLevel[level[u]].size() + mark[v]];
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,q;
	cin >> n >> q;
	w = vector<int64_t>(n + 1);
	dot = vector<int64_t>(n + 1);
	level = vector<int64_t>(n + 1);
	mark = vector<int64_t>(n + 1);
	p = vector<int64_t>(n + 1);
	precomputed = vector<bool>(n + 1);
	adj = vector<vector<int>> (n + 1, vector<int>());
	for(int i=1;i<=n;i++) {
		cin >> w[i];
	}
	for(int i=1;i<n;i++) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	level[1] = 0;
	dfs(1, -1);
	int maxDepth = *max_element(level.begin(), level.end());
	nodesAtEachLevel = vector<vector<int>>(maxDepth + 1);
	cache = vector<vector<int64_t>>(maxDepth + 1, vector<int64_t>());
	for(int i=1;i<=n;i++) {
		nodesAtEachLevel[level[i]].push_back(i);
	}

	int blockSize = sqrtl(n);

	for(int i=0;i<=maxDepth;i+=blockSize) {
		int currentDepth = i, sz = nodesAtEachLevel[i].size();
		for(int j=i;j<=min(i+blockSize,maxDepth);j++) {
			if((int)nodesAtEachLevel[j].size() < sz) {
				sz = nodesAtEachLevel[j].size();
				currentDepth = j;	
			}
		}
		int id = 0;
		for(auto x: nodesAtEachLevel[currentDepth]) 
			mark[x] = id++;
		for(auto u: nodesAtEachLevel[currentDepth]) {
			for(auto v: nodesAtEachLevel[currentDepth]) {
				if(mark[u] <= mark[v]) {
					cache[currentDepth].push_back(query(u,v));
				} else {
					cache[currentDepth].push_back(cache[currentDepth][mark[v] * sz + mark[u]]);
				}
			}
			precomputed[u] = true;
		}
	}
	for(int i=1;i<=q;i++) {
		int u,v;
		cin >> u >> v;
		cout << query(u, v) << '\n';
	}
}