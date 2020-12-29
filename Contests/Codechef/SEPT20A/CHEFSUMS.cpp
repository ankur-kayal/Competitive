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

vl nums,prime(1'000'005),A,calculateX, calculateM;
ll N,K,M,X;
ll ans;

void init() {
	for(int i=2;i<=1'000'000;i++) {
		prime[i] = i;
	}
	for(int i=2;i*i<=1'000'000;i++) {
		if(prime[i] == i) {
			for(int j=i*i;j<=1'000'000;j+=i) {
				if(prime[j] == j)
					prime[j] = i;
			}
		}
	}
}

ll logpow(ll x, ll y) {
	x = x % MOD;
	ll res = 1;
	while(y > 0) {
		if(y & 1) {
			res = (res * x) % MOD;
		}
		x = (x * x) % MOD;
		y >>=1;
	}
	return res;
}

void solve() {
	ll G,S,P,W;
	// calculate GCD
	G = W = A[nums[0]];
	P = 1;
	S = 0;
	for(int i=0;i<K;i++) {
		int index = nums[i];
		G = __gcd(G,A[index]);
		S = (S + calculateX[index]) % MOD;
		P = (P * calculateM[index]) % MOD;
		W = min(prime[A[index]], W);
	}
	// cout << G*S*P*W << '\n';
	ans = (ans + (((G * S) % MOD) * ((P * W) % MOD))%MOD)%MOD;
}

void generate(int k) {
	for(int i=0;i<N;i++) {
		nums.pb(i);
		if(k == 1) {
			solve();
		}
		else {
			generate(k-1);
		}
		nums.pop_back();
	}
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif  
	
    cin >> N >> K >> M >> X;
    A.assign(N,0);
	trav(a,A) {
		cin >> a;
	}
	init();
	for(int i=2;i<=1'000'000;i++) {
		cout << i << " " << prime[i] << '\n';
	}
	calculateX.assign(N,0);
	calculateM.assign(N,0);
	for(int i=0;i<N;i++) {
		calculateX[i] = logpow(A[i],X);
		calculateM[i] = logpow(A[i],M);
	}
    generate(K);
    assert(ans > 0);
    cout << ans << '\n';
}
 
// read the question correctly (ll vs int)
// template by bqi343