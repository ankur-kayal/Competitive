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



// debug & operator << (debug & dd, Edge p) { dd << "(" << p.u << ", " << p.v << ", " << p.w << ")"; return dd; }

const long long inf = 1e15;

#define ll long long

vector<int> parent(100'005), r(100'005);
vector<int> weights(100'005,0);

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(int v) {
    parent[v] = v;
    r[v] = 1;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin >> n >> m;

	vector<pair<int,pair<int,int>>> edges;

	for(int i=0;i<m;i++) {
		int u,v,w;
		cin >> u >> v >> w;
		if(u != 1 and v != 1) {
			edges.push_back(make_pair(w,make_pair(u,v)));
		}
		else {
			if(u == 1) {
				weights[v] = w;
			}
			else {
				weights[u] = w;
			}
		}
	}

	for(int i=2;i<=n;i++) {
		make_set(i);
	}

	vector<int> used((int)edges.size(),0);

	vector<long long> ans(n,0);
	for(int i=2;i<=n;i++) {
		ans[n-1] += weights[i];
	}
	debug() << imie(edges);

	for(int i=n-2;i>=1;i--) {
		long long delta = inf;
		pair<int,pair<int,int>> best;
		int index = 0;
		for(int j=0;j<(int)edges.size();j++) {
			int u = edges[j].second.first;
			int v = edges[j].second.second;
			if(!used[j] and (find_set(u) != find_set(v))) {
				int wu = weights[find_set(u)];
				int wv = weights[find_set(v)];
				int tmp = edges[j].first - max(wu,wv);
				if(tmp < delta) {
					index = j;
					delta = tmp;
				}
			}
		}
		ans[i] = ans[i+1] + delta;
		int u = edges[index].second.first;
		int v = edges[index].second.second;	
		int wu = weights[find_set(u)];
		int wv = weights[find_set(v)];
		if(wu > wv) {
			parent[u] = v;
		}
		else {
			parent[v] = u;
		}
		used[index] = 1;
	}
	for(int i=1;i<n;i++) {
		cout << ans[i] << " ";
	}
	cout << '\n';
	
}