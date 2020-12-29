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
	
	int t;
	// int cas = 0;
	cin >> t;
	while(t--) {
		// cas++;
		// cout << "Case: " << cas << '\n';
		string S;
		cin >> S;
		ll A = -200000, B = -200000, C = -200000;
		vector <ll> dp(sz(S),200001);
		F0R(i,sz(S)) {
			if(S[i] == '1') {
				A = i;
				if(A>=0 and B>=0 and C>=0)
				dp[i] = min(dp[i-1],max(A-B + 1,A-C + 1));
			}
			if(S[i] == '2'){
				B = i;
				if(A>=0 and B>=0 and C>=0)
				dp[i] = min(dp[i-1], max(B-A + 1,B-C + 1));
			} 
			if(S[i] == '3'){
				C = i;
				if(A>=0 and B>=0 and C>=0)
				dp[i]=min(dp[i-1], max(C-A + 1,C-B + 1));
			} 
		}
		// for(int i=0;i<sz(S);i++) {
		// 	cout << dp[i] << " ";
		// }
		// cout << nl;
		cout  << (dp[sz(S)-1] <= 200000  ? dp[sz(S)-1] : 0) << '\n';
	}
    
}
 
// read the question correctly (ll vs int)
// template by bqi343