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
vector<long double> moola, vals;
vector<int> euler;
int timer;

void dfs(int node, int par) {
	in[node] = timer++;
	euler.push_back(node + 1);
	for(auto u: adj[node]) {
		if(u != par) {
			dfs(u,node);
		}
	}
	out[node] = timer++;
	euler.push_back(node + 1);
}

void upd(int index, long double val) {
	while(index < timer) {
		moola[index] += val;
		index += (index & -index);
	}
}

long double get(int i) {
	long double res = 0;
	while(i > 0) {
		res += moola[i];
		i -= (i & -i);
	}
	return res;
}

long double rangeSum(int start, int end) {
	return get(end) - get(start - 1);
}

long double calculate(int x, int y) {
	long double s1 = rangeSum(in[x], out[x]);
	long double s2 = rangeSum(in[y], out[y]);

	debug() << imie(pow(10,s1)) imie(pow(10,s2));

	long double ans =  - s2  + s1;

	if(ans >= 9) {
		ans = 1e9;
	}
	else {
		ans = pow(10,ans);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cout << fixed << setprecision(20);

	int n;
	cin >> n;
	adj.resize(n, vector<int>());
	in.resize(n);
	out.resize(n);
	for(int i=0;i<n-1;i++) {
		int u,v;
		cin >> u >> v;
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// debug() << imie(adj);
	// exit(0);

	timer = 1;
	dfs(0,-1);

	moola.assign(timer, 0);
	vals.assign(timer, 0);
	debug() << imie(euler);

	int q;
	cin >> q;
	while(q--) {
		int ch;
		cin >> ch;
		if(ch == 1) {
			int x;
			long double y;
			cin >> x >> y;
			--x;
			y = log10(y);
			long double diff = y - vals[in[x]];
			vals[in[x]] = y;
			upd(in[x], diff);
		}
		else{
			int x,y;
			cin >> x >> y;
			--x; --y;
			cout << calculate(x,y) << '\n';
		}
		debug() << imie(moola);
	}


}