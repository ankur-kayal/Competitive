#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

//HEADER FILES AND NAMESPACES
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
using namespace std;
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
 
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
 
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

multiset <int> adj[200'005];
vi vis(200'005),h(200'005),par(200'005), branch(200'005);

int b;

void dfs_compute(int node, int d) {
	vis[node] = 1;
	h[node] = d;
	if(branch[par[node]] == 0) {
		++b;
		branch[node]=b;
	}
	else {
		branch[node] = branch[par[node]];
	}
	for(auto u: adj[node]) {
		if(vis[u] == 0) {
			branch[u] = branch[node];
			dfs_compute(u,d+1);
			par[u] = node;
		}
	}
}

void dfs_check(int node) {
	vis[node] = 1;
	for(auto u: adj[node]) {
		if(vis[u] == 0) {
			dfs_check(u);
		}
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif  
	
	vl pow2(200'005), pow3(200'005);
	pow2[0] = 1;
	pow3[0] = 1;
	for(int i=1;i<=200'000;i++) {
		pow2[i] = (pow2[i-1] * 2) % MOD;
		pow3[i] = (pow3[i-1] * 3) % MOD;
	}
    int T,u,v;
    cin >> T;
    while(T--) {
    	b=-1;
    	int N;
    	cin >> N;
    	for(int i=1;i<=N;i++) {
    		adj[i].clear();
    		vis[i] = 0;
    		h[i] = 0;
    		par[i] = i;
    		branch[i] = 0;
    	}
    	for(int i=1;i<N;i++) {
    		cin >> u >> v;
    		adj[u].ins(v);
    		adj[v].ins(u);
    	}

    	// for(int i=1;i<=N;i++) {
    	// 	cout << i << " -> ";
    	// 	for(auto u: adj[i]) {
    	// 		cout << u << " ";
    	// 	}
    	// 	cout << '\n';
    	// }
    	// precompute parent, height, and the pairs of reparenting
    	dfs_compute(1,0); // precomputes parent, height
    	// for(int i=1;i<=N;i++) {
    	// 	cout << i << " " << branch[i] << '\n';
    	// }
    	// cout << "Reached here\n";
    	ordered_set <pair<int,pair<int,int>>> L;
    	for(int i=2;i<=N;i++) {
    		// i == u
    		for(int j=1;j<=N;j++) {
    			if(j == i) continue;
    			// j == v
    			// breaking old connections
    			bool exists = true;
    			// adj[par[i]].erase(adj[par[i]].find(i));
    			// adj[i].erase(adj[i].find(par[i]));
    			// // building new connections
    			// adj[i].ins(j);
    			// adj[j].ins(i);

    			// for(int i=1;i<=N;i++) {
		    	// 	cout << i << " -> ";
		    	// 	for(auto u: adj[i]) {
		    	// 		cout << u << " ";
		    	// 	}
		    	// 	cout << '\n';
		    	// }
    			if(branch[i] == branch[j] and h[i] < h[j]) {
    				exists = false;
    			}
    			// for(int k=1;k<=N;k++) {
    			// 	vis[k] = 0;
    			// }
    			// int cnt = 0;
    			// for(int k=1;k<=N;k++) {
    			// 	if(vis[k] == 0) {
    			// 		dfs_check(k);
    			// 		cnt++;
    			// 	}
    				
    			// 	if(cnt > 1) {
    			// 		exists = false;
    			// 	}
    			// }
    			// cout << i << " " << j << " " << exists << '\n';
    			if(exists) {
    				// cout << i << " " << j << '\n';
    				L.ins(mp(i,mp(h[j],j)));
    			}

    			// // break the new connection
    			// adj[i].erase(adj[i].find(j));
    			// adj[j].erase(adj[j].find(i));

    			// // rebuild new connections
    			// adj[i].ins(par[i]);
    			// adj[par[i]].ins(i);
    		}
    	}

    	int Q;
    	cin >> Q;
    	ll d = 0;
    	for(int i=1;i<=Q;i++) {
    		ll e;
    		cin >> e;
    		ll c = d ^ e;
    		pair<ll,pair<ll,ll>> ele = *L.find_by_order(c-1);
    		L.erase(L.find_by_order(c-1));
    		ll ui, vi;
    		ui = ele.f;
    		vi = ele.s.s;
    		d = (d + (pow2[i]*ui)%MOD + (pow3[i]*vi)%MOD)%MOD;
    	}
    	cout << d << '\n';
    }
}
 
// read the question correctly (ll vs int)
// template by bqi343