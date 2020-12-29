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

// const int maxN = 3e5 + 10;

vector<vector<int>> adj;
vector<int> in,out;
vector<long long> match, vals;
vector<int> euler, level;
int timer;

void dfs(int node, int par, int d) {
	in[node] = timer++;
	euler.push_back(node + 1);
	level[node] = d;
	for(auto u: adj[node]) {
		if(u != par) {
			dfs(u, node, d + 1);
		}
	}
	out[node] = timer++;
	euler.push_back(node + 1);
}

void upd(int index, long long val) {
	while(index < timer) {
		match[index] += val;
		index += (index & -index);
	}
}

long long get(int i) {
	long long res = 0;
	while(i > 0) {
		res += match[i];
		i -= (i & -i);
	}
	return res;
}

long long rangeSum(int start, int end) {
	return get(end) - get(start - 1);
}

long long calculate(int x, int y) {
	long long ans = 0;
	int node;
	if(level[x] > level[y]) {
		swap(x,y);
	}
	ans = rangeSum(in[y], out[y]);
	return ans;
}

void solve() {
	int n;
	cin >> n;
	int q;
	cin >> q;
	{
		adj.clear();
		in.clear();
		out.clear();
		level.clear();
	}
	{
		adj.resize(n, vector<int>());
		in.resize(n);
		out.resize(n);
		level.resize(n);
	}
	
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin >> u >> v;
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	debug() << imie(adj);
	// exit(0);

	timer = 1;
	euler.clear();
	dfs(0,-1, 0);

	match.assign(timer, 0);
	vals.assign(timer, 0);
	debug() << imie(euler);


	// seeds contribute +value
	// pots contribute -value
	while(q--) {
		int a,b;
		long long val;
		cin >> a >> b >> val;
		--a; --b;
		if(val != 0) {
			upd(in[a], val);
			upd(in[b], -val);
		}
		else {
			cout << abs(calculate(a,b)) << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}