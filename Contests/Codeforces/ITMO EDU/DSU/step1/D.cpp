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

vector <int> par;
vector <int> r;

int get(int v) {
	return par[v] = par[v] == v ? v : get(par[v]);
}

void merge(int u, int v) {
	u = get(u);
	v = get(v);
	if(r[u] == r[v]) {
		r[u]++;
	}
	if(r[u] > r[v]) {
		par[v] = u;
	}
	else {
		par[u] = v;
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    // freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    // freopen("output.txt", "w+", stdout);
#endif  
	
    int n,m,k;
    cin >> n >> m >> k;
    par.resize(n+1);
    r.resize(n+1);
    vector<array<int,3>> queries;
    vector<string>ans;
    for(int i=1;i<=n;i++) {
    	par[i] = i;
    	r[i] = 0;
    }
    for(int i=0;i<m;i++) {
        int u,v;
        cin >> u >> v;
    }
    for(int i=0;i<k;i++) {
        string ch;
        int u,v,w;
        cin >> ch >> u >> v;
        w = (ch == "ask");
        queries.pb({w,u,v});
    }
    reverse(all(queries));
    for(int i=0;i<k;i++) {
        if(queries[i][0] == 1) {
            ans.pb(get(queries[i][1]) ==  get(queries[i][2]) ? "YES" : "NO");
        }
        else {
            merge(queries[i][1], queries[i][2]);
        }
    }
    reverse(all(ans));
    for(auto u: ans) {
        cout << u << '\n';
    }
}
 
// read the question correctly (ll vs int)
// template by bqi343