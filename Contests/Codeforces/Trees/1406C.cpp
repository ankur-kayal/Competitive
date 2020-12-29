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
		int n;
		cin >> n;
		vector<vector<int>> adj(n);
		for(int i=0;i<n-1;i++) {
			int u,v;
			cin >> u >> v;
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<int> centroids;

		vector<int> sz(n);

		int leaf,p;

		function<void(int,int)> dfs = [&](int node, int par) {
			sz[node] = 1;
			bool is_centroid = true;

			for(auto u: adj[node]) {
				if(u != par) {
					dfs(u, node);
					if(sz[u] > n / 2) {
						is_centroid = false;
					}
					sz[node] += sz[u];
				}
			}

			if(n - sz[node] > n / 2) {
				is_centroid = false;
			}

			if(is_centroid) {
				// debug() << imie(sz[node]);
				centroids.push_back(node);
			}
		};

		function<void(int,int)> findLeaf = [&](int node, int par) {
			for(auto u: adj[node]) {
				if(u != par) {
					if((int)adj[u].size() == 1) {
						p = node;
						leaf = u;
						return;
					}
					findLeaf(u, node);
					
				}
			}
		};

		dfs(0,-1);


		if((int)centroids.size() == 1) {
			cout << centroids[0] + 1 << " " << adj[centroids[0]][0] + 1 << '\n';
			cout << centroids[0] + 1 << " " << adj[centroids[0]][0] + 1<< '\n';
		}

		// debug() << imie(centroids);
		else {
			findLeaf(centroids[0],centroids[1]);
			cout << p + 1 << " " << leaf + 1 << '\n';
			cout << centroids[1] + 1 << " " << leaf + 1 << '\n';
		}
	}
}