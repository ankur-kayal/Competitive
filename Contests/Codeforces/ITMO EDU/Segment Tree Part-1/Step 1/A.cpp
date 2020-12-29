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

struct segtree {
	int size;

	vector<ll> sums;

	void init(int n) {
		size = 1;
		while(size < n) {
			size *= 2;
		}
		sums.assign(2 * size, 0);
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < a.size()) {
				sums[x] = a[lx];
			}
			return;
		}
		int m = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void build(vector<int> &a) {
		build(a,0,0,size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			sums[x] = v;
			return;
		}

		int m = (rx + lx) / 2;
		if(i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}

		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	ll sum(int l, int r, int x, int lx, int rx) {
		if(lx >= r or l >= rx) {
			return 0;
		}

		else if(lx >= l and rx <= r) return sums[x];

		int m = (rx + lx) / 2;

		ll s1 = sum(l, r, 2 * x + 1, lx, m);
		ll s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}

	ll sum(int l, int r) {
		return sum(l, r, 0, 0, size);
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

	segtree st;
	st.init(n);

	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}

	st.build(a);

	while(m--) {
		int op;
		cin >> op;
		if(op == 1) {
			int i,v;
			cin >> i >> v;
			st.set(i,v);
		}
		else {
			int l, r;
			cin >> l >> r;
			cout << st.sum(l,r) << '\n';
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