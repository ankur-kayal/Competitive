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

const int maxN = 3e5;

vector<long long> adj[maxN], dp(maxN,0), leaf(maxN,0), val(maxN), sum(maxN,0);

void dfs(int node, int par) {
	leaf[node] = !(adj[node].size());
	sum[node] += val[node];
	for(auto u: adj[node]) {
		if(u != par) {
			dfs(u, node);
			dp[node] = max(dp[node], dp[u]);
			sum[node] += sum[u];
			leaf[node] += leaf[u];
		}
	}
	// debug() << imie(node) imie(sum[node]);
	dp[node] = max(dp[node], (sum[node] + leaf[node] - 1) / leaf[node]);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	for(int i=2;i<=n;i++) {
		int u;
		cin >> u;
		adj[u].push_back(i);
	}
	for(int i=1;i<=n;i++) {
		cin >> val[i];
	}
	dfs(1,-1);
	cout << dp[1] << '\n';
}