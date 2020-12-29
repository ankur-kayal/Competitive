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

ll m,n;

vl cnt,t,z,y;

bool good(ll time) {
	ll sum = 0;
	for(int i=0;i<n;i++) {
		cnt[i] = min(m-sum,(time / (t[i] * z[i] + y[i]))*z[i] + min((time % (t[i]*z[i] + y[i])) / t[i], z[i]));
		sum += cnt[i];
	}
	// cout << time << " " << sum << '\n';
	return sum >= m;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif  
	
    cin >> m >> n;
    cnt.resize(n);
    t.resize(n);
    y.resize(n);
    z.resize(n);
    for(int i=0;i<n;i++) {
    	cin >> t[i] >> z[i] >> y[i];
    }

    ll l = -1;
    ll r = 1;
    while(!good(r)) r*= 2;
    // cout << "r = " << r << '\n';
    // cout << good(114200) << '\n';
    while(r > l + 1) {
    	int m = l + (r - l) / 2;
    	if(good(m)) {
    		r = m;
    	}
    	else {
    		l = m;
    	}
    }
    cout << r << '\n';
    good(r);
    trav(a,cnt) cout << a << " ";
    cout << '\n';
}
 
// read the question correctly (ll vs int)
// template by bqi343