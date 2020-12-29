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

/* union by size */
struct dsu {
  int n;
  vector<int> sizes, marks;
  vector<vector<int> > graph;
 
  void init(int rn) {
    n = rn;
    sizes = vector<int>(n);
    fill(sizes.begin(), sizes.end(), 1);
    marks = vector<int>(n);
    for (int i = 0; i < n; i++) marks[i] = i;
    graph = vector<vector<int> >(n);
  }
 
  void mark(int m, int node) {
    if (marks[node] == m) return;
 
    marks[node] = m;
 
    for (int i: graph[node]) mark(m, i);
  }
 
  void merge(int a, int b) {
    if (marks[a] == marks[b]) return;
    graph[a].push_back(b);
    graph[b].push_back(a);
 
    if (sizes[marks[a]] > sizes[marks[b]]) swap(a, b);
 
    sizes[marks[b]] += sizes[marks[a]];
    sizes[marks[a]] = 0;
    mark(marks[b], a);
  }
 
  int find(int n) { return marks[n]; }
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dsu ob;
	int n;
	cin >> n;
	ob.init(n);
	int k;
	cin >> k;
	for(int i=0;i<k;i++) {
		int u,v;
		cin >> u >> v;
		--u; --v;
		ob.merge(u,v);
	}
	vector<int> discard(n,0);
	int m;
	cin >> m;
	for(int i=0;i<m;i++) {
		int u,v;
		cin >> u >> v;
		--u; --v;
		if(ob.find(u) == ob.find(v)) {
			discard[ob.find(u)] = 1;
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++) {
		if(discard[ob.find(i)] == 0) {
			ans = max(ans, ob.sizes[ob.find(i)]);
		}
	}
	cout << ans << '\n';

}