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
    	int N;
    	cin >> N;
    	vector <int> A(N);
    	for(int i=0;i<N;i++) {
    		A[i] = i + 1;
    	}
    	ll sum = N*(N+1)/2;
    	if(sum% 2 == 1) {
    		cout << 0 << '\n';
    		continue;
    	}
    	ll tmp = 0;
    	ll ans = 0;
    	vpi debug;
    	for(int i=0;i<N;i++) {
    		for(int j=0;j<i;j++) {
    			tmp = 0;
    			swap(A[i],A[j]);
    			// trav(a,A) {
    			// 	cout << a << " ";
    			// }
    			// cout << '\n';
    			for(int k=0;k<N;k++) {
    				tmp += A[k];
    				if(tmp == sum-tmp) {
    					// cout << A[i] << " " << A[j] << '\n';
    					debug.pb(mp(A[i],A[j]));
    					ans++;
    					break;
    				}
    			}
    			swap(A[i],A[j]);
    		}
    	}
    	sort(all(debug));
    	trav(a,debug) {
    		cout << a.f << " " << a.s << '\n';
    	}

    	cout << ans << '\n';
    }
}
 
// read the question correctly (ll vs int)
// template by bqi343