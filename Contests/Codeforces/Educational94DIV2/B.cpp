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
    	int P,F,CNTS, CNTW,S,W;
    	cin >> P>>F>>CNTS >> CNTW>>S>>W;
    	int a = P / S,b;
    	a = min(CNTS, a);
    	int mx = a;
    	int amax = 0, bmax = 0, cmax = 0, dmax = 0;
    	for(int i=a;i>=0;i--) {
    		b = (P - i*S) / W;
    		b = min(CNTW, b);
    		if(i + b >= mx) {
    			amax = i;
    			bmax = b ;
    			mx = i + b;
    		}
    	}
    	CNTS-=amax;
    	CNTW-=bmax;
    	int c = F / S,d;
    	c = min(CNTS,c);
    	mx = c;
    	// cout << amax << " " << bmax << '\n';
    	for(int i=c;i>=0;i--) {
    		d = (F - i*S) / W;
    		d = min(CNTW,d);
    		// cout << d << '\n';
    		if(i + d >= mx) {
    			cmax = i;
    			dmax = d;
    			mx = i + d;
    		}
    	}
    	// cout << cmax << " " << dmax << '\n';
    	cout << (amax + bmax + cmax + dmax) << '\n';

    }
}
 
// read the question correctly (ll vs int)
// template by bqi343