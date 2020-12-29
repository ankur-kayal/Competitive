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
int timer = 0;
int ans;
int res;

vector<long long> p(maxN), score(maxN), low(maxN), sub(maxN);
vector<vector<int>> adj;

// void dfs(int node, int par) {
// 	sub[node] = 1;

// 	for(auto u: adj[node]) {
// 		if(u != par) {
// 			dfs(u, node);
// 			sub[node] += sub[u];
// 			score[node] = max(score[node], score[u]);
// 		}
// 	}

// 	score[node] += sub[node];

	
// 	// debug() << imie(node) imie(ans);
// }

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	function<void (int, int)> dfs = [&](int node, int par) {
		sub[node] = 1;

		for(auto u: adj[node]) {
			if(u != par) {
				dfs(u, node);
				sub[node] += sub[u];
				score[node] = max(score[node], score[u]);
			}
		}

		score[node] += sub[node];
	};

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		adj.clear();
		adj.resize(n+1);
		for(int i=1;i<=n;i++) {
			p[i] = -1; 
			low[i] = maxN;
			score[i] = 0;
			sub[i] = 0;
		}
		for(int i=1;i<=n-1;i++) {
			int u;
			cin >> u;
			adj[u].push_back(i+1);
			adj[i+1].push_back(u);
			p[i+1] = u;
		}

		

		dfs(1, -1);
		// for(int i=1;i<=n;i++) {
		// 	cerr << score[i] << " ";
		// }
		// cerr << '\n';
		cout << score[1] << '\n';
	}
}