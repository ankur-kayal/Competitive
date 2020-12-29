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
 
const ll MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

vector <ll> ifact(1000005), fact(1000005), inv(1000005);

void init() {
	fact[1] = 1;
    fact[0] = 1;
	ifact[1] = 1;
    ifact[0] = 1;
    inv[1] = 1;
	for(int i=2;i<=1000000;i++) {
		fact[i] = (fact[i-1] * i) % MOD;
		inv[i] = (MOD - (MOD/i) * inv[MOD%i] % MOD) % MOD;
	}
    for(int i=2;i<=1000000;i++) {
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

ll logpow(ll x, ll y) {
	if(x == 0) {
		return 1;
	}
	ll res = 1;
	while(y > 0) {
		if(y & 1) {
			res = (res * x) % MOD;
		}
		x = (x * x) % MOD;
		y>>=1;
	}
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
	
	init();
    int N;
    cin >> N;
    ll ans = (8*MOD + logpow(10,N) -2*(logpow(9,N)) + logpow(8,N)) % MOD;
    cout << ans << '\n';
}
 
// read the question correctly (ll vs int)
// template by bqi343