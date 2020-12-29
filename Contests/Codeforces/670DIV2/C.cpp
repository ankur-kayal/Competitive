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
 
// #define sz(x) (int)(x).size()
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

set<int> adj[MX]; vi compo(MX), vis(MX);

int N;

vector<int> Centroid() {
    int n = N;
    vector<int> centroid;
    vector<int> sz(n);
    function<void (int, int)> dfs = [&](int u, int prev) {
            sz[u] = 1;
            bool is_centroid = true;
            for (auto v : adj[u]) if (v != prev) {
                    dfs(v, u);
                    sz[u] += sz[v];
                    if (sz[v] > n / 2) is_centroid = false;
            }
            if (n - sz[u] > n / 2) is_centroid = false;
            if (is_centroid) centroid.push_back(u);
    };
    dfs(0, -1);
    return centroid;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif  
	
    int T;
    cin >> T;
    while(T--) {
    	cin >> N;
    	for(int i=0;i<=N;i++) {
    		adj[i].clear();
    		vis[i] = 0;
    		compo[i] = 1;
    	}
    	for(int i=1;i<=N-1;i++) {
    		int u,v;
    		cin >> u >> v;u--;v--;
    		adj[u].ins(v);
    		adj[v].ins(u);
    	}
    	vector <int> centriod = Centroid();
    	if(centriod.size() == 1) {
    		cout << centriod[0] + 1 << " " << *adj[centriod[0]].begin() + 1 << '\n';
    		cout << centriod[0] + 1<< " " << *adj[centriod[0]].begin() + 1 << '\n';
    	}
    	else {
    		int first = centriod[0];
    		int second = centriod[1];
    		bool found1 = false;
    		bool found2 = false;
    		for(auto u: adj[first]) {
    				// adj[]
    			if(u != second) {
    				adj[u].erase(first);
					adj[first].erase(u);
					adj[second].ins(u);
					adj[u].ins(second);
					if(Centroid().size() == 1) {
						cout << first+1 << " " << u+1 << '\n';
	    				cout << second+1 << " " << u+1 << '\n';
	    				found1 = true;
	    				break;
					}
					else {
						adj[u].ins(first);
	    				adj[first].ins(u);
	    				adj[second].erase(u);
	    				adj[u].erase(second);
					}
    			}
				
    				
    				
    		}
    		if(found1 == false) {
    			for(auto u: adj[second]) {
    				if(u != first) {
    					adj[u].ins(first);
	    				adj[first].ins(u);
	    				adj[second].erase(u);
	    				adj[u].erase(second);
	    				if(Centroid().size() == 1) {
		    				cout << second+1 << " " << u+1 << '\n';
	    					cout << first+1 << " " << u+1 << '\n';
		    				found1 = true;
		    				break;
	    				}
	    				else {
	    					adj[u].erase(first);
		    				adj[first].erase(u);
		    				adj[second].ins(u);
		    				adj[u].ins(second);
	    				}
    				}
	    		}
    		}
    		
    	}
    }
}
 
// read the question correctly (ll vs int)
// template by bqi343