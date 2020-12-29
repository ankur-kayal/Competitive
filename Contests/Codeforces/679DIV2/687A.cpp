// https://codeforces.com/contest/687/problem/A
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

const int maxN = 2e5;

vector<int> adj[maxN], vis(maxN), col(maxN), ans[2]; 


void dfs(int node, int color) {
	col[node] = color;
	ans[color].push_back(node);
	vis[node] = 1;

	for(auto u: adj[node]) {
		if(vis[u] == 0) {
			dfs(u,color^1);
		}
		if(col[node] == col[u]) {
			debug() << imie(node) imie(col[node]) imie(u) imie(col[u]);
			cout << -1 << '\n';
			exit(0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin >> n >> m;

	for(int i=0;i<m;i++) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;i++) {
		col[i] = -1;
	}

	// group A -> color 0
	// group B -> color 1

	for(int i=1;i<=n;i++) {
		if((int)adj[i].size() > 0 and vis[i] == 0) {
			dfs(i,0);
		}
	}

	{
		cout << ans[1].size() << '\n';
		for(auto u: ans[1]) {
			cout << u << " ";
		}
		cout << '\n';
		cout << ans[0].size() << '\n';
		for(auto u: ans[0]) {
			cout << u << " ";
		}
		cout << '\n';
	}

}