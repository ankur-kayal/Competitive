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

#define uint unsigned int


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	int n,q;
	cin >> n >> q;
	vector<uint> w(n+1);
	for(int i=1;i<=n;i++) {
		cin >> w[i];
	}

	vector<vector<int>> adj(n+1);
	vector<uint> p(n+1), score(n+1);

	for(int i=0;i<n-1;i++) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	function<void (int,int)> dfs = [&](int node, int par) {
		p[node] = par;
		score[node] = w[node] * w[node];
		if(par != -1) {
			score[node] = score[node] + score[par];
		}

		for(auto u: adj[node]) {
			if(u != par) {
				dfs(u,node);
			}
		}
	};

	function<uint (int, int)> calculate = [&](int u, int v) {
		uint ans = 0;
		while(u != v) {
			ans = ans + w[u] * w[v];
			u = p[u];
			v = p[v];
		}

		if(u != -1) {
			ans = ans + score[u];
		}
		return ans;
	};

	dfs(1,-1);

	debug() << imie(adj);

	while(q--) {
		int u,v;
		cin >> u >> v;
		cout << calculate(u,v) << '\n';
	}
}