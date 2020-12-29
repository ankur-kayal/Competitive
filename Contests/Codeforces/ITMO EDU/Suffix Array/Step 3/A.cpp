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

void count_sort(vector<int> &p, vector<int> &c) {
	int n = p.size();
	vector<int> cnt(n), pos(n);
	for(auto u: c) {
		cnt[u]++;
	}
	pos[0] = 0;
	for(int i=1;i<n;i++) {
		pos[i] = pos[i-1] + cnt[i-1];
	}
	vector<int> p_new(n);
	for(auto u: p) {
		int i = c[u];
		p_new[pos[i]] = u;
		pos[i]++;
	}
	p = p_new;
}

bool good(vector<int> &p, string &s, string &pat, int m) {
	int n = p.size();
	int np = pat.size();
	return (pat <= s.substr(p[m], np));
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif  
	
    string s;
    cin >> s;
    s+='$';

    int n = s.length();
    vector<int> p(n), c(n);

    {
    	// k = 0
    	vector<pair<char,int>> a(n);
    	for(int i=0;i<n;i++) a[i] = {s[i],i};
		sort(all(a));

		for(int i=0;i<n;i++) p[i] = a[i].second;
		c[p[0]] = 0;
		for(int i=1;i<n;i++) {
			if(a[i].first == a[i-1].first) {
				c[p[i]] = c[p[i-1]];
			}
			else {
				c[p[i]] = c[p[i-1]] + 1;
			}
		}
    }

    int k = 0;
    while((1LL<<k) < n) {
    	// k -> k + 1
    	for(int i=0;i<n;i++) {
    		p[i] = (p[i] - (1<<k) + n) % n;
    	}

    	count_sort(p,c);

    	vector<int> c_new(n);
		c_new[p[0]] = 0;
		for(int i=1;i<n;i++) {
			pair<int,int> prev = {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};
			pair<int,int> curr = {c[p[i]], c[(p[i] + (1<<k))%n]};
			if(curr == prev) {
				c_new[p[i]] = c_new[p[i-1]];
			}
			else {
				c_new[p[i]] = c_new[p[i-1]] + 1;
			}
		}
		c = c_new;
		k++;
    }

    int q;
    cin >> q;
    while(q--) {
    	string pat;
    	cin >> pat;
    	int np = pat.length();
    	int l = -1, r = n;
    	while(r > l + 1) {
    		int m = l + (r - l) / 2;
    		if(good(p,s,pat,m)) {
    			r = m;
    		}
    		else {
    			l = m;
    		}
    	}
    	if(r < n and s.substr(p[r],np) == pat) {
    		cout << "Yes" << '\n';
    	}
    	else {
    		cout << "No" << '\n';
    	}
    }
    
}
 
// read the question correctly (ll vs int)
// template by bqi343