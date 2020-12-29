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
 
const int MOD = 1000000007;
const char nl = '\n';
const int MX = 100001; //check the limits, dummy

struct fenwicktree {
	int size;
	vector<ll> values;

	void init(int n) {
		size = n;
		values.resize(n);
	}

	void build(vector<ll> &a) {
		for(int i=1;i<=size;i++) {
			upd(i,a[i]);
		}
	}

	void upd(int i, ll v) {
		while(i<size) {
			values[i] += v;
			i += i & -i;
		}
	}

	ll get(int i) {
		ll ans = 0;
		while(i > 0) {
			ans += values[i];
			i-=i&-i;
		}
		return ans;
	}

	ll get(int l, int r) {
		return get(r) - get(l);
	}

};
 
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

	// start your program here
	int n,m;
	cin >> n >> m;

	fenwicktree ft;
	ft.init(n+1);

	vector<ll> a(n+1);
	for(int i=1;i<=n;i++) {
		cin >> a[i];
	}

	ft.build(a);

	while(m--) {
		int op;
		cin >> op;
		if(op == 1) {
			ll i,v;
			cin >> i >> v;
			ll diff = v - a[i+1];
			ft.upd(i+1, diff);
			a[i+1] = v;
		}
		else {
			ll l,r;
			cin >> l >> r;
			cout << ft.get(l,r) << '\n';
		}
	}


#ifdef DEBUG
    end = clock();  
    ld time_taken = ld(end - start) / ld(CLOCKS_PER_SEC); 
    cerr << "\nTime taken by program is : " << fixed << time_taken << setprecision(5); 
    cerr << " sec " << '\n'; 
#endif 
	   
}
 
// read the question correctly (ll vs int)
// template by bqi343