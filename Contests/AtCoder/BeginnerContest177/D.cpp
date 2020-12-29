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

const int mxN = 2e5+10;

vi adj[mxN], vis(mxN);

int cnt = 0;

void dfs(int node) {
	vis[node] = 1;
	cnt++;
	for(auto u: adj[node]) {
		if(vis[u] == 0) {
			dfs(u);
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
	
    int N,M;
    cin >> N>>M;
    map<pi,int> store;
    vi grps(N+1);
    int ans = 0;
    for(int i=0;i<M;i++) {
    	int X,Y;
    	cin >> X >> Y;
    	if(X > Y) {
    		swap(X,Y);
    	}
    	if(store[mp(X,Y)] == 0) {
    		store[mp(X,Y)] = 1;
    		adj[X].pb(Y);
    		adj[Y].pb(X);
    	}
    }

    for(int i=1;i<=N;i++) {
    	if(vis[i] == 0) {
    		cnt = 0;
    		dfs(i);
    	}
    	ans = max(ans, cnt);
    }
    cout << ans << '\n';
}
 
// read the question correctly (ll vs int)
// template by bqi343