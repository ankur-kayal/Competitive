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

	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin >> u >> v;
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> leaf, deg;

	function<void(int,int)> dfs = [&](int node, int par) {
		for(auto u: adj[node]) {
			if(u != par) {
				dfs(u,node);
				if(adj[u].size() == 1) {
					leaf.push_back(u);
				}
			}
		}
	};

	dfs(0,-1);
	if(adj[0].size() == 1) {
		leaf.push_back(0);
	}
	int maxD = -1;
	int prev = -1;
	bool ok = 1;
	int root;
	for(int i=0;i<n;i++) {
		int d = adj[i].size();
		maxD = max(maxD, (int)adj[i].size());
	}

	for(int i=0;i<n;i++) {
		if(adj[i].size() == 1) {
			continue;
		}

		int d = adj[i].size();
		if(d > 2) {
			deg.push_back(i);
		}
	}

	if(deg.size() == 0) {
		cout << "Yes" << '\n';
		cout << 1 << '\n';
		cout << leaf[0] + 1 << " " << leaf[1] + 1 << '\n';
		exit(0);
	}
	if(deg.size() > 1) {
		cout << "No" << '\n';
		exit(0);
	}

	if(ok) {
		cout << "Yes" << '\n';
		int root = deg.back();
		cout << (int)leaf.size() << '\n';
		for(auto u: leaf) {
			cout << root + 1 << " " << u + 1 << '\n';
		}
	}
	else {
		cout << "No" << '\n';
	}

	cerr << maxD << '\n';

	debug() << imie(deg) imie(leaf) imie(maxD);
}