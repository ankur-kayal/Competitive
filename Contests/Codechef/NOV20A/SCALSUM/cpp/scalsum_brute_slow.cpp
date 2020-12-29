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

const int maxN = 2e5;

long long MOD = 4294967296;
template<class T> 
class Math {

public:
    vector<T> fact,invfact,inv;

    Math( int n ) {
        fact.resize(n);
        invfact.resize(n);
        inv.resize(n);

        fact[0] = inv[0] = invfact[0] = 1;
        fact[1] = inv[1] = invfact[1] = 1;
        for(int i=2;i<n;i++) {
            fact[i] = mult( i , fact[i-1] );
            inv[i] = sub( MOD, mult( MOD/i, inv[MOD%i] ) );
            invfact[i] = mult( invfact[i-1], inv[i] );
        }
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
		score[node] = m.add(score[node], score[par]);
		level[node] = level[par] + 1;
	}
	// store[make_pair(node, node)] = score[node];

	for(auto u: adj[node]) {
		if(u != par) {
			dfs(u,node);
		}
	}
}

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
		if(store.count(make_pair(u,v))) {
			return store[make_pair(u,v)];
		}
		int depthOfQueryNode = level[u];
		vector<long long> Fu;
		vector<int> vertexSet1, vertexSet2;
		vector<long long> Fv;
		long long ans = 0;
		int par1, par2;
		while(true) {
			Fu.push_back(w[u]);
			Fv.push_back(w[v]);
			vertexSet1.push_back(u);
			vertexSet2.push_back(v);
			// ans = m.add(ans, m.mult(w[u], w[v]));
			u = p[u];
			v = p[v];
			par1 = u;
			par2 = v;
			if(par1 > par2) {
				swap(par1, par2);
			}
			if(store.count(make_pair(par1, par2)) or u == v) {
				break;
			}
		}
		// if(u > v) {
		// 	swap(u,v);
		// }
		debug() << imie(par1) imie(par2);
		debug() << imie(store[make_pair(par1, par2)]);
		if(u == v) {
			ans = m.add(ans, score[u]);
		}
		else {
			ans = m.add(ans, store[make_pair(par1, par2)]);
		}
		// reverse(Fu.begin(), Fu.end());
		// reverse(Fv.begin(), Fv.end());
		// reverse(vertexSet2.begin(), vertexSet2.end());
		// reverse(vertexSet1.begin(), vertexSet1.end());
		// debug() << imie(Fu) imie(Fv);

		// vector<long long> dotProduct = calculateDotProduct(Fu, Fv);
		// debug() << imie(dotProduct);
		int n = Fu.size();
		for(int i=0;i<n;i++) {
			ans = m.add(ans, m.mult(Fu.back(), Fv.back()));
			int u = vertexSet2.back();
			int v = vertexSet1.back();
			if(u > v) {
				swap(u,v);
			}
			if(depthOfQueryNode > 1000)
			store[make_pair(u,v)] = ans;
			Fu.pop_back();
			Fv.pop_back();
			vertexSet1.pop_back();
			vertexSet2.pop_back();
		}
		// ans = m.add(ans, calculateDotProduct(Fu, Fv));
		return ans;
	};

	level[1] = 1;
	dfs(1,-1);

	debug() << imie(adj);

	while(q--) {
		int u,v;
		cin >> u >> v;
		if(u > v) {
			swap(u,v);
		}
		if(u == v) {
			cout << score[u] << '\n';
		}
		else {
			long long tmp = calculate(u, v);
			store[make_pair(u,v)] = tmp;
			cout << tmp << '\n';
		}
	}
	debug() << imie(store);
}
