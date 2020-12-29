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
	
    int R,G,B;
    cin>>R>>G>>B;
    vector <int> X(R),Y(G),Z(B);
    for(int i=0;i<R;i++) {
    	cin >> X[i];
    }
    for(int i=0;i<G;i++) {
    	cin >> Y[i];
    } 
    for(int i=0;i<B;i++) {
    	cin >> Z[i];
    }
    sort(all(X)); reverse(all(X));
    sort(all(Y)); reverse(all(Y));
    sort(all(Z)); reverse(all(Z));
    int dp[R+1][G+1][B+1];
    for(int i=0;i<=R;i++) {
    	for(int j=0;j<=G;j++) {
    		for(int k=0;k<=B;k++) {
    			dp[i][j][k] = 0;
    		}
    	}
    }

    int ans = 0;
    for(int i=0;i<=R;i++) {
    	for(int j=0;j<=G;j++) {
    		for(int k=0;k<=B;k++) {
    			if(i < R and j < G) {
    				dp[i+1][j+1][k] = max(dp[i+1][j+1][k], (dp[i][j][k] + X[i]*Y[j]));
    			}
    			if(j < G and k < B) {
    				dp[i][j+1][k+1] = max(dp[i][j+1][k+1], (dp[i][j][k] + Y[j]*Z[k]));
    			}
    			if(k < B and i < R) {
    				dp[i+1][j][k+1] = max(dp[i+1][j][k+1], (dp[i][j][k] + Z[k]*X[i]));
    			}
    			ans = max(ans,dp[i][j][k]);
    		}
    	}
    }
    cout << ans << '\n';
}
 
// read the question correctly (ll vs int)
// template by bqi343