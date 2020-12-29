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

vector<vector<long long>> adj, precompute, nodesInEachDepth;
vector<long long> w, level, score, p, marker;

const int maxN = 2e5;
const int maxDepthICanPrecompute = 100;
const int maxMovesAllowed = 1e8;
int movesPerformed;

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

vector<long long> Fu;
vector<int> vertexSet1, vertexSet2;
vector<long long> Fv;

long long calculate(int u, int v) {
	if(precompute[u][marker[v]] != -1) {
		return precompute[u][marker[v]];
	}
	int depthOfQueryNode = level[u];
	Fu.clear();
	Fv.clear();
	vertexSet2.clear();
	vertexSet1.clear();
	long long ans = 0;
	int par1, par2;
	while(true) {
		movesPerformed++;
		Fu.push_back(w[u]);
		Fv.push_back(w[v]);
		vertexSet1.push_back(u);
		vertexSet2.push_back(v);
		// ans = m.add(ans, m.mult(w[u], w[v]));
		u = p[u];
		v = p[v];
		par1 = u;
		par2 = v;
		if(level[par1] <= 100) {
			break;
		}
		if(precompute[par1][marker[par2]] != -1 or u == v) {
			break;
		}
	}
	if(level[par1] <= maxDepthICanPrecompute) {
		while(u != v) {
			ans = m.add(ans, m.mult(w[u], w[v]));
			u = p[u];
			v = p[v];
		}
	}
	
	debug() << imie(par1) imie(par2);
	if(u == v) {
		ans = m.add(ans, score[u]);
	}
	else {
		ans = m.add(ans, precompute[par1][marker[par2]]);
	}
	// reverse(Fu.begin(), Fu.end());
	// reverse(Fv.begin(), Fv.end());
	// reverse(vertexSet2.begin(), vertexSet2.end());
	// reverse(vertexSet1.begin(), vertexSet1.end());
	// debug() << imie(Fu) imie(Fv);

	// vector<long long> dotProduct = calculateDotProduct(Fu, Fv);
	// debug() << imie(dotProduct);
	int n = Fu.size();
	long long tmp = 0;
	for(int i=0;i<n;i++) {
		ans = m.add(ans, m.mult(Fu.back(), Fv.back()));
		int u = vertexSet2.back();
		int v = vertexSet1.back();
		precompute[u][marker[v]] = ans;
		precompute[v][marker[u]] = ans;
		Fu.pop_back();
		Fv.pop_back();
		vertexSet1.pop_back();
		vertexSet2.pop_back();
	}
	assert(movesPerformed <= maxMovesAllowed);
	return ans;
}

long long calculateNaive(int u, int v) {
	long long ans = 0;
	while(u != v) {
		ans = m.add(ans, m.mult(w[u], w[v]));
		u = p[u];
		v = p[v];
	}

	// if(u != -1) {
	// 	ans = m.add(ans, score[u]);
	// }
	
	ans = m.add(ans, score[u]);
	return ans;
}

void solveNaive(vector<pair<int,int>>& queries) {
	for(auto x: queries) {
		cout << calculateNaive(x.first, x.second) << '\n';
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	movesPerformed = 0;
	int n,q;
	cin >> n >> q;
	adj = vector<vector<long long>>(n + 1, vector<long long>());
	level = vector<long long>(n + 1);
	score = vector<long long>(n + 1);
	p = vector<long long>(n + 1);
	w = vector<long long>(n + 1);
	marker = vector<long long>(n + 1);

	for(int i=1;i<=n;i++) {
		cin >> w[i];
	}

	for(int i=1;i<=n-1;i++) {
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	level[1] = 1;
	dfs(1, -1);

	long long maxQueriesDepth = 0;
	vector<pair<int,int>> queries;
	for(int i=1;i<=q;i++) {
		int u,v;
		cin >> u >> v;
		maxQueriesDepth = max(maxQueriesDepth, level[u]);
		queries.emplace_back(u,v);
	}

	if(maxQueriesDepth < 1000) {
		solveNaive(queries);
		exit(0);
	}
	

	long long maxDepthOfTheTree = *max_element(level.begin(), level.end());
	nodesInEachDepth = vector<vector<long long>>(maxDepthOfTheTree + 1);
	for(int i=1;i<=n;i++) {
		nodesInEachDepth[level[i]].push_back(i);
	}
	debug() << imie(nodesInEachDepth);

	precompute = vector<vector<long long>>(n + 1, vector<long long>());
	for(int i=1;i<=n;i++) {
		if((int)nodesInEachDepth[level[i]].size() <= 900)
		precompute[i] = vector<long long>((int)nodesInEachDepth[level[i]].size(), -1);
	}

	for(auto u: nodesInEachDepth) {
		int count = (int)u.size();
		for(long long i=0;i<count;i++) {
			marker[u[i]] = i;
		}
	}
	debug() << imie(marker);

	for(auto x: queries) {
		cout << calculate(x.first, x.second) << '\n';
	}

}