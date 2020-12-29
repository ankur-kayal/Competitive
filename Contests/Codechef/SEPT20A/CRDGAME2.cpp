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

vector <ll> ifact(500005), fact(500005), inv(500005);

void init() {
	fact[1] = 1;
    fact[0] = 1;
	ifact[1] = 1;
    ifact[0] = 1;
    inv[1] = 1;
	for(int i=2;i<=500000;i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
	}
    for(int i=2;i<=500000;i++) {
        ifact[i] = (ifact[i-1] * inv[i]) % MOD;
    }
}



ll combine(ll n, ll r) {
	ll res = 1;
	ll num = fact[n];
    ll deno = (ifact[n-r] * ifact[r]) % MOD;
    res = (num * deno) % MOD;
	return res;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif  
	
	vl pow2(1'00'001,0);
	pow2[0] = 1;
	for(int i=1;i<=1'00'000;i++) {
		pow2[i] = (pow2[i-1]*2) % MOD;
	}
	init();
    int T;
    cin >> T;
    while(T--) {
    	ll N;
    	cin >> N;
    	ll mx = 0;
    	vl C(N);
    	trav(a,C) cin >> a;
    	trav(a,C) ckmax(mx,a);
    	ll cnt = 0;
    	trav(a,C) if(a == mx) cnt++;
    	// cout << cnt << '\n';
    	ll ans;
    	if(cnt%2==1) {
    		ans = pow2[N];
    	}
    	else {
    		ll minus = ((((combine(cnt,cnt/2)))%MOD)*pow2[N-cnt]) % MOD;
    		ans = (MOD + pow2[N] -minus)%MOD;
    	}
    	cout << ans << '\n';
    }
}
 
// read the question correctly (ll vs int)
// template by bqi343