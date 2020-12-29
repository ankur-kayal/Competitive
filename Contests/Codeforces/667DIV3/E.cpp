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
#define ub lower_bound
#define all(x) x.begin(), x.end()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy
 
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
    	int N,K,tmp;
    	cin >> N >> K;
    	map <int,int> coor;
    	for(int i=0;i<N;i++) {
    		cin >> tmp;
    		coor[tmp]++;
    	}
    	vpi pts;
    	for(auto u: coor) {
    		pts.pb(mp(u.f,u.s));
    	}
    	for(int i=0;i<N;i++) {
    		cin >> tmp;
    	}
    	if(pts[0].f + 2*K >= pts.back().f) {
    		cout << N << '\n';
    		continue;
    	}
    	// trav(a,pts) {
    	// 	cout << a.f << " " << a.s << '\n';
    	// }
    	int ans = 0;
    	int ans1 = 0;
    	for(int i=0;i<pts.size();i++) {
    		int index = lower_bound(pts.begin()+i,pts.end(), mp(pts[i].f + K, -1)) - (pts.begin());
    		// cout << index << '\n';
    		int tmp = 0;
    		index = min(index,((int) pts.size()));
    		for(int j=i;j<=index;j++) {
    			if(pts[i].f + K >= pts[j].s) {
    				tmp += pts[j].s;
    			}
    		}
    		ans = max(ans,tmp);
    		if(index == (int)(pts.size())) {
    			break;
    		}
    	}
    	for(int i=0;i<pts.size();i++) {
    		int index = lower_bound(pts.begin()+i,pts.end(), mp(pts[i].f + K, -1)) - (pts.begin());
    		// cout << index << '\n';
    		int tmp = 0;
    		index = min(index,((int) pts.size()));
    		for(int j=i;j<index;j++) {
    			if(pts[i].f + K >= pts[j].s) {
    				tmp += pts[j].s;
    			}
    		}
    		if(tmp == ans) {
    			for(int j=i;j<=index;j++) {
    				if(pts[i].f + K >= pts[j].s) {
	    				pts[j].s = 0;
	    			}
    			}
    			break;
    		}
    		if(index == (int)(pts.size())) {
    			break;
    		}
    	}
    	// trav(a,pts) {
    	// 	cout << a.f << " " << a.s << '\n';
    	// }
    	for(int i=0;i<pts.size();i++) {
    		int index = lower_bound(pts.begin()+i,pts.end(), mp(pts[i].f + K, -1)) - (pts.begin());
    		// cout << index << '\n';
    		int tmp = 0;
    		index = min(index,((int) pts.size()));
    		for(int j=i;j<=index;j++) {
    			if(pts[i].f + K >= pts[j].s) {
    				tmp += pts[j].s;
    			}
    		}
    		ans1 = max(ans1,tmp);
    		if(index == (int)(pts.size())) {
    			break;
    		}
    	}
    	ans = ans + ans1;
    	cout << ans << '\n';
    	// trav(a,pts) {
    	// 	cout << a.f << " " << a.s << '\n';
    	// }

    }
}
 
// read the question correctly (ll vs int)
// template by bqi343