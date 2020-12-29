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
const int MX = 100010; //check the limits, dummy

int n,m,d,x,y,w;

vector<pair<int,int>> adj[MX];
vector<int> path;
bool found = false;

void dfs(int node, int par, ll m) {
	// cout << node << " " << par << " " << m << " " << path.size() <<  '\n';
	if(found or path.size() > d+1) {
		return;
	}
	if(node == n) {
		found = true;
		// for(auto u: path) {
		// 	cout << u << " ";
		// }
		// cout << '\n';
		return;
	}

	for(auto u: adj[node]) {
		if(u.first != par and u.second <= m) {
			path.pb(u.first);
			dfs(u.first,node,m);
			if(found) {
				break;
			}
			path.pop_back();
		}
	}
	if(found) {
		return;
	}
}



bool good(ll m) {
	path.clear();
	found = false;
	path.pb(1);
	dfs(1,-1, m);
	return found;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif  
	
    cin >> n >> m >> d;
    for(int i=0;i<m;i++) {
    	cin >> x >> y >> w;
    	adj[x].pb(mp(y,w));
    }
    // for(int i=1;i<=n;i++) {
    // 	cout << "For node i= "<< i  << '\n';
    // 	for(auto u: adj[i]) {
    // 		cout << u.first << " " << u.second << '\n';
    // 	}
    // }
    ll l = 0;
    ll r = 1e10;
    // cout << good(6) << '\n';
    // for(auto u: path) {
    // 	cout << u << " ";
    // }
    // cout << '\n';
    while(r > l + 1) {
    	ll m = l + (r - l) / 2;
    	if(good(m)) {
    		r = m;
    	}
    	else {
    		l = m;
    	}
    }
    good(r);
    if(path.size() <= 1) {
    	cout << -1 << '\n';
    }
    else {
    	cout << path.size() - 1 << '\n';
    	for(auto u : path) {
    		cout << u << " ";
    	}
    	cout << '\n';
    }

    
}
 
// read the question correctly (ll vs int)
// template by bqi343