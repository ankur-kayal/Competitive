#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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

int ans;
const int mxM = 3e5+10;
vi height(mxM), vis(mxM), adj[mxM];
set<int> height1[mxM], height2[mxM];


void dfs1(int node, int d) {
	height[node] = d;
    height1[d].ins(node);
	vis[node] = 1;
	for(auto u: adj[node]) {
		if(vis[u] == 0) {
			dfs1(u, d+1);
		}
	}
}

void dfs2(int node, int d) {
    height2[d].ins(node);
	ans = max(ans,d);
	vis[node] = 1;
	for(auto u: adj[node]) {
		if(vis[u] == 0) {
			dfs2(u, d+1);
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
	
    int n;
    cin >> n;
    if(n == 1) {
    	cout << 1;
    	return 0;
    }
    for(int i=0;i<n-1;i++) {
    	int u,v;
    	cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }
    dfs1(1,0);
    int mx = 1, node;
    for(int i=1;i<=n;i++) {
    	if(height[i] > mx) {
    		mx = height[i];
    		node = i;
    	}
    }
    FOR(i,1,n+1) vis[i] = 0;
    dfs2(node, 0);

    int h1 = height[node];
    int h2 = ans;

    for(int i=1;i<=n;i++) {
        if(height1[h1].find(i) != height1[h1].end() or height2[h2].find(i) != height2[h2].end()) {
            cout << ans + 1 << '\n';
        }
        else {
            cout << ans << '\n';
        }
    }

    // cout << 3 * ans ;
}
 
// read the question correctly (ll vs int)
// template by bqi343