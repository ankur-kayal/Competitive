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

struct item {
	ll sum;
};

struct segtree {
	int size;

	item NEUTRAL_ELEMENT = {0};

	vector<item> values;

	void init(int n) {
		size = 1;
		while(size < n) {
			size *= 2;
		}
		values.resize(2 * size);
	}

	item single(ll v) {
		return {v};
	}

	item merge(item &a, item &b) {
		return  {max({a.sum , b.sum})};
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < a.size()) {
				values[x] = single(a[lx]);
			}
			return;
		}
		int m = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}

	void build(vector<int> &a) {
		build(a,0,0,size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			values[x] = single(v);
			return;
		}

		int m = (rx + lx) / 2;
		if(i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}

		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	item calc(int l, int r, int x, int lx, int rx) {
		if(lx >= r or l >= rx) {
			return NEUTRAL_ELEMENT;
		}

		else if(lx >= l and rx <= r) return values[x];

		int m = (rx + lx) / 2;

		item s1 = calc(l, r, 2 * x + 1, lx, m);
		item s2 = calc(l, r, 2 * x + 2, m, rx);
		return merge(s1, s2);
	}

	item calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}

	int find(int val, int l, int x, int lx, int rx) {
		if(values[x].sum < val) {
			return -1;
		}

		if(rx <= l) return -1;

		if(rx - lx == 1) {
			return lx;
		}
		int m = (lx + rx) / 2;;
		int res = find(val, l, 2 * x + 1, lx, m);
		if(res == -1) {
			res = find(val, l, 2 * x + 2, m , rx);
		}
		return res;
	}

	int find(int k, int l) {
		return find(k, l, 0,0,size);
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
	segtree st;
	int n,m;
	cin >> n >> m;
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
			a[i] = v;
			st.set(i, a[i]);
		}
		else {
			int k,l;
			cin >> k >> l;
			cout << st.find(k,l) << '\n';
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