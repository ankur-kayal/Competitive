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

template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);

struct edge {
	int u, v, w;
	edge() { u = v = w = 0; }
	edge(int _u, int _v, int _w) {
		u = _u;
		v = _v;
		w = _w;
	}
};

edge e[MAXN];

int n, m;
int64_t sum;
int val[MAXN];

set<pair<int, pair<int, int>>> edge_values;

int par[MAXN];
int root(int x) { 
	return par[x] == x ? x : (par[x] = root(par[x])); 
}

void read() {
	sum = 0;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		par[i] = i;
	}

	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		e[i] = edge(u, v, w);

		if(u == 1) {
			sum += w;
			val[v] = w;
		} 
	}
}

bool used[MAXN];
int64_t answer[MAXN];

void solve() {
	for(int i = 0; i < m; i++) {
		if(e[i].u != 1) {
			edge_values.insert({e[i].w - val[e[i].u], {i, e[i].u}});
			edge_values.insert({e[i].w - val[e[i].v], {i, e[i].v}});
		}
	}

	answer[n - 1] = sum;
	for(int i = n - 2; i >= 1; i--) {
		while(true) {
			auto it = edge_values.begin();
			int w = it->first, index = it->second.first, v = it->second.second;
			edge_values.erase(it);
			
			if(used[index]) {
				continue;
			}

			if(root(v) != v) {
				edge_values.insert({e[index].w - val[root(v)], {index, root(v)}});
				continue;
			}

			if(root(e[index].u) == root(e[index].v)) {
				continue;
			}
			
			int u = root(e[index].u) == v ? root(e[index].v) : root(e[index].u);
			
			sum += w;
			par[v] = u;
			used[index] = true;
			break;
		}

		answer[i] = sum;
	}

	for(int i = 1; i <= n - 1; i++) {
		cout << answer[i] << " ";
	}

	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	read();
	solve();
	return 0;
}