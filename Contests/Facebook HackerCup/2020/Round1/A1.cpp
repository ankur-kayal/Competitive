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

void solve() {
	ll N,W,K,AL,BL,CL,DL,AH,BH,CH,DH;
	cin >> N >> K >> W;
	ll X[K],Y[K];
	F0R(i,K) cin >> X[i];
	cin >> AL >> BL >> CL >> DL;
	F0R(i,K) cin >> Y[i];
	cin >> AH >> BH >> CH >> DH;
	ll L[N], H[N], P[N];
	F0R(i,N) {
		if(i > K-1) {
			L[i] = ((AL * L[i-2]) % DL + (BL * L[i-1]) % DL + CL) % DL + 1;
			H[i] = ((AH * H[i-2]) % DH + (BH * H[i-1]) % DH + CH) % DH + 1;
		}
		else {
			L[i] = X[i];
			H[i] = Y[i];
		}
	}
	P[0] = 2 * (W + H[0]);
	pi pSW, pSE, pNW, pNE;
	pSW = {L[0],0};
	pSE = {L[0] + W, 0};
	pNW = {L[0], H[0]};
	pNE = {L[0] + W, H[0]};
	FOR(i, 1, N) {
		pi SW,SE,NW,NE;
		SW = {L[i],0};
		SE = {L[i] + W, 0};
		NW = {L[i], H[i]};
		NE = {L[i] + W, H[i]};
		ll top,left,right,down;

		if(SW.f > pSE.f) {
			P[i] = (P[i-1] + 2 * (W + H[i])) % MOD;
		}
		else {
			down = L[i] - L[i-1];
			right = max((ll)0, H[i] - H[i-1]);
			top, left;
			if(H[i-1] < H[i]) {
				top = W;
				left = H[i] - H[i-1];
			}
			else {
				top = down;
				left = 0;
			}
			P[i] = (P[i-1] + left + down + top + right) % MOD;
			// cout << left << " " << right << " " << top << " " << down << '\n';
		}
		pSW = {L[i],0};
		pSE = {L[i] + W, 0};
		pNW = {L[i], H[i]};
		pNE = {L[i] + W, H[i]};
		
	}
	ll ans = 1;
	F0R(i,N) {
		cout << P[i] << " ";
	}
	cout << '\n';
	// F0R(i,N) {
	// 	ans = (ans * P[i]) % MOD;
	// }
	// cout << ans << '\n';
	// F0R(i,N) cout << L[i] << " ";
	// cout << '\n';
	// F0R(i,N) cout << H[i] << " ";
	// cout << '\n';
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output1.txt", "w+", stdout);
#endif  
	
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) {
    	cout << "Case #" << i << ": " << nl;
    	solve();
    }
}
 
// read the question correctly (ll vs int)
// template by bqi343