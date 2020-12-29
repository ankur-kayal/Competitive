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

struct Edge {
    long long w = inf, to = -1;
};

vector<vector<long long>> adj(10+1,vector<long long>(10+1,inf));

long long mst(int n) {
    int total_weight = 0;
    vector<bool> selected(n+1, false);
    vector<Edge> min_e(n+1);
    min_e[1].w = 0;

    for (int i=1; i<=n; ++i) {
        int v = -1;
        for (int j = 1; j <= n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }
        // if (min_e[v].to != -1)
        //     cout << v << " " << min_e[v].to << endl;
        // if (min_e[v].w == inf) {
        //     cout << "No MST!" << endl;
        //     exit(0);
        // }

        selected[v] = true;
        total_weight += min_e[v].w;

        for (int to = 1; to <= n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }

    return total_weight;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin >> n >> m;
	assert(n <= 5);
		vector<long long> weights(n+1);
	while(m--) {
		long long u,v,w;
		cin >> u >> v >> w;
		if(u == 1 or v == 1) {
			if(u == 1) {
				weights[v] = w;
			}
			else if(v == 1) {
				weights[u] = w;
			}
		}
		else {
			adj[u][v] = w;
			adj[v][u] = w;
		}
	}

	long long maxN = (1LL << n);
	long long count = 1;
	for(int i=0;i<n-1;i++) {
		// Edge tmp;
		// tmp.u = 1;
		// tmp.v = weights[i].second;
		// tmp.w = weights[i].first;
		// edges.insert(tmp);
		// debug() << imie(edges);
		// cout << mst(n) << '\n';
		long long ans = 1e18;
		{
			for(int j=0;j<maxN;j++) {
				if(j % 2 == 0) {
					vector<long long> indices;
					for(int k=1;k<n;k++) {
						if((j&(1LL<<k)) != 0) {
							indices.push_back(k+1);
						}
					}
					if(int(indices.size()) == count) {
					// debug() << imie(indices);
						long long sum = 0;
						for(auto u: indices) {
							adj[1][u] = 0;
							adj[u][1] = 0;
							sum += weights[u];
						}
						// debug() << imie(adj);
						long long tmp = mst(n);
						ans = min(ans,tmp + sum);
						// debug() << imie(tmp);
						for(auto u: indices) {
							adj[1][u] = inf;
							adj[u][1] = inf;
						}
					}
				}
				
			}
		}
		count++;
		cout << ans << ' ';
	}
}