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
 

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 998244353;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

const int mod = 998244353;

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
	if(r < 0 or r > n) return 0;
	ll num = fact[n];
    ll deno = (ifact[n-r] * ifact[r]) % MOD;
    ll res = (num * deno) % MOD;
	return res;
}


 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifdef DEBUG
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
    // for writing external error logs to output.txt
    freopen("output.txt", "a+", stderr);
#endif  

#ifdef DEBUG
    clock_t start, end; 
    start = clock();
#endif 
    init();

	// start your program here
    ll n,k;
    cin >> n >> k;

    vector<pair<int,int>> lines(n);
    for(int i=0;i<n;i++) {
    	int x,y;
    	cin >> x >> y;
    	lines[i] = {x , y};
    }
    sort(all(lines));
    multiset<int> m;
	ll ans = 0;
	for(int i=0;i<n;i++) {
		while(!m.empty() and(*m.begin() < lines[i].first)) {
			m.erase(m.begin());
		}
		ans = (ans + combine(m.size(), k - 1))%mod;
		m.insert(lines[i].second);
	}
	cout << ans << '\n';





#ifdef DEBUG
    end = clock();  
    ld time_taken = ld(end - start) / ld(CLOCKS_PER_SEC); 
    cerr << "\nTime taken by program is : " << fixed << time_taken << setprecision(5); 
    cerr << " sec " << '\n'; 
#endif 
	   
}
 
// read the question correctly (ll vs int)
// template by bqi343