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

vector<vector<int>> adj;
vector<long long> p, score, w, level;
map<pair<int,int>, long long> store;
map<pair<int,int>, int> query;
set<pair<int,int>> queryContains;


const int maxN = 2e5;

long long MOD = 4294967296;
template<class T> 
class Math {

public:
    vector<T> fact,invfact,inv;

    Math( int n ) {
        // fact.resize(n);
        // invfact.resize(n);
        // inv.resize(n);
        // fact[0] = inv[0] = invfact[0] = 1;
        // fact[1] = inv[1] = invfact[1] = 1;
        // for(int i=2;i<n;i++) {
        //     fact[i] = mult( i , fact[i-1] );
        //     inv[i] = sub( MOD, mult( MOD/i, inv[MOD%i] ) );
        //     invfact[i] = mult( invfact[i-1], inv[i] );
        // }
    }

    T modinv( T x, T m = MOD ) {
        return expo(x,m-2,m);
    }

    T expo( T base, T exp, T m = MOD ) {
        T res = 1;
        while( exp ) {
            if( exp & 1 )
                res = mult( res, base, m );
            base = mult( base, base, m );
            exp >>= 1;
        }
        return res;
    }

    T nCr( T n, T k ) {
        if( k < 0 || k > n ) return 0;
        T ans = fact[n];
        ans = mult( ans , invfact[n-k] );
        ans = mult( ans , invfact[k] );
        return ans;
    }

    T mult( T a, T b, T m = MOD ) {
        return ( a * b ) % m;
    }

    T add( T a, T b, T m=MOD ) {
        return ( a + b ) % m;
    }

    T sub( T a, T b, T m=MOD ) {
        return ( a - b + m ) % m;
    }

    T divide( T a, T b, T m=MOD ) {
        return ( a * modinv( b,m ) ) % m;
    }
};

Math<long long> m(maxN);

void dfs(int node, int par) {
	p[node] = par;
	score[node] = m.mult(w[node], w[node]);
	if(par != -1) {
		level[node] = level[par] + 1;
	}
	if(par != -1) {
		score[node] = m.add(score[node], score[par]);
	}
	// store[make_pair(node, node)] = score[node];

	for(auto u: adj[node]) {
		if(u != par) {
			dfs(u,node);
		}
	}
}

struct Query {
	int vertex1, vertex2, depth, index;

	Query(int _vertex1, int _vertex2, int _depth, int _index) {
		vertex1 = _vertex1;
		vertex2 = _vertex2;
		depth = _depth;
		index = _index;
	}

	bool operator<(const Query& q) const {
		return depth > q.depth;
	}
};

vector<long long> calculateDotProduct(vector<long long> &Fu, vector<long long> &Fv) {
	int n1 = Fu.size();
	int n2 = Fv.size();
	assert(n1 == n2);
	vector<long long> dotProduct(n1);
	dotProduct[0] = m.mult(Fu[0], Fv[0]);
	for(int i=1;i<n1;i++) {
		dotProduct[i] = m.add(dotProduct[i - 1], m.mult(Fu[i], Fv[i]));
	}
	return dotProduct;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,q;
	cin >> n >> q;
	w = vector<long long> (n + 1);
	for(int i=1;i<=n;i++) {
		cin >> w[i];
	}

	// vector<vector<int>> adj(n+1);
	adj = vector<vector<int>>(n + 1, vector<int>());
	// vector<long long> p(n+1), score(n+1);
	p = vector<long long>(n + 1);
	score = vector<long long>(n + 1);
	level = vector<long long>(n + 1);

	for(int i=0;i<n-1;i++) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}



	function<long long (int, int)> calculate = [&](int u, int v) {
		vector<long long> Fu;
		vector<int> vertexSet1, vertexSet2;
		vector<long long> Fv;
		long long ans = 0;
		int par1, par2;
		while(u != v) {
			Fu.push_back(w[u]);
			Fv.push_back(w[v]);
			vertexSet1.push_back(u);
			vertexSet2.push_back(v);
			// ans = m.add(ans, m.mult(w[u], w[v]));
			u = p[u];
			v = p[v];
		}

		ans = m.add(ans, score[u]);

		reverse(Fu.begin(), Fu.end());
		reverse(Fv.begin(), Fv.end());
		reverse(vertexSet2.begin(), vertexSet2.end());
		reverse(vertexSet1.begin(), vertexSet1.end());
		debug() << imie(Fu) imie(Fv);

		vector<long long> dotProduct = calculateDotProduct(Fu, Fv);
		debug() << imie(dotProduct);
		int n = Fu.size();
		for(int i=0;i<n-1;i++) {
			long long tmp = m.add(ans, dotProduct[i]);
			int u = vertexSet2[i];
			int v = vertexSet1[i];
			if(u > v) {
				swap(u,v);
			}
			if(queryContains.count(make_pair(u,v))) {
				store[make_pair(u,v)] = tmp;
				queryContains.erase(queryContains.find(make_pair(u,v)));
			}
		}
		// ans = m.add(ans, calculateDotProduct(Fu, Fv));
		ans = m.add(ans, dotProduct.back());
		return ans;
	};
	level[1] = 1;
	dfs(1,-1);

	debug() << imie(adj);
	debug() << imie(level);
	// vector<long long> ans(q + 1);
	// const int maxNodes = 3e5 + 100;
	// int maxDepth = *max_element(level.begin(), level.end());
	// vector<vector<int>> nodesInEachDepth(maxDepth + 1, vector<int>());
	// for(int i=1;i<=n;i++) {
	// 	nodesInEachDepth[level[i]].push_back(i);
	// }
	// for(int i=100;i<=n+1;i++) {
	// 	assert((int)nodesInEachDepth[i].size() <= 100);
	// }
	// vector<vector<int>> precompute(n + 1);
	// for(int i=1;i<=n;i++) {
	// 	precompute[i] = vector<int> ((int)nodesInEachDepth[level[i]].size(), -1);
	// }
	// debug() << imie(precompute);
	// debug() << imie(nodesInEachDepth);
	int cnt = 0;
	vector<Query> querySortedByDepth;
	for(int i=1;i<=q;i++) {
		int u, v;
		cin >> u >> v;
		assert(level[u] <= 500);
	}
	/*for(int i=1;i<=q;i++) {
		int u,v;
		cin >> u >> v;
		if(u > v) {
			swap(u, v);
		}
		int d = level[u];
		Query q(u, v, d, i);
		auto tmp = make_pair(u,v);
		queryContains.insert(tmp);
		querySortedByDepth.push_back(q);
	}
	sort(querySortedByDepth.begin(), querySortedByDepth.end());
	for(auto u: querySortedByDepth) {
		int vertex1 = u.vertex1;
		int vertex2 = u.vertex2;
		if(!queryContains.count(make_pair(vertex1, vertex2))) {
			ans[u.index] = store[make_pair(vertex1, vertex2)];
		}
		else {
			ans[u.index] = calculate(vertex1, vertex2);
			queryContains.erase(queryContains.find(make_pair(vertex1, vertex2)));
		}	
	}
	for(int i=1;i<=q;i++) {
		cout << ans[i] << '\n';
	}
	debug() << imie(store);*/
}
