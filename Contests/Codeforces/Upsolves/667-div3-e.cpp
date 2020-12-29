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
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif  
	
    int T;
    cin >> T;
    while(T--) {
    	int N,K;
    	cin>>N>>K;
    	vi A(N);
    	trav(a,A) cin >> a;
    	for(int i=0;i<N;i++) {
    		int tmp;
    		cin >> tmp;
    	}
    	sort(all(A));
    	vi L(N),R(N);
    	int left = 0;
    	L[0] = 1;
    	for(int i=1;i<N;i++) {
    		while(A[i]-A[left] > K) {
    			left++;
    		}
    		L[i] = max(L[i-1], i-left+1);
    	}
    	int right = N-1;
    	R[right] = 1;
    	for(int i=N-2;i>=1;i--) {
    		while(A[right] - A[i] > K) right--;
    		R[i] = max(R[i+1], right-i+1);
    	}
    	int ans = 1;
    	for(int i=0;i<N-1;i++) {
    		// cout << L[i]+R[i+1] << '\n';
    		ans = max(ans,L[i] + R[i+1]);
    	}
    	cout << ans << '\n';
    }
}
 
// read the question correctly (ll vs int)
// template by bqi343