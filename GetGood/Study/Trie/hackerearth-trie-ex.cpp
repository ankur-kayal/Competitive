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

struct node {
	bool leaf;
	int weight;
	node* child[26];
};

node* create() {
	node* res = new node();
	for(int i=0;i<26;i++) {
		res->child[i] = NULL;
	}
	res->weight = 0;
	res->leaf = false;
	return res;
}

node* root = create();

void add(string &s, int wt) {
	node* tmp = root;
	for(int i=0;i<s.length();i++) {
		if(tmp->child[s[i] - 'a'] == NULL) {
			tmp->child[s[i] - 'a'] = create();
		}
		tmp = tmp->child[s[i]-'a'];
		tmp->weight = max(wt,tmp->weight);
	}
	tmp->leaf = true;
}

int query(string &s) {
	int ans = 0;
	node* tmp = root;
	for(int i=0;i<s.length();i++) {
		if(tmp->child[s[i]-'a'] != NULL) {
			tmp = tmp->child[s[i]-'a'];
			ans = tmp->weight;
		}
		else {
			ans = -1;
			break;
		}
	}
	return ans;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif  
	
    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++) {
    	string foo;
    	int w;
    	cin >> foo >> w;
    	add(foo,w);
    }
    while(q--) {
    	string foo;
    	cin >> foo;
    	cout << query(foo) << '\n';
    }

}
 
// read the question correctly (ll vs int)
// template by bqi343