#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
 
using namespace std;
 
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

const int mxN = 1e5 + 10;
vi A(mxN);
vpi table(mxN);
int N;

void update(int i, pi delta) {
	while(i<=N) {
		table[i].first += delta.first;
		table[i].second += delta.second;
		i += (i & -i);
	}
}

pi sum(int i) {
	pi res = {0,0};
	while(i > 0) {
		res.first += table[i].first;
		res.second += table[i].second;
		i -= (i & -i);
	}
	return res;
}

pi compute(int l, int r) {
	pi res,res1,res2;
	res1 = sum(r);
	res2 = sum(l-1);
	res.first = res1.first - res2.first;
	res.second = res1.second - res2.second;
	return res;
}

void build() {
	for(int i=1;i<=N;i++) {
		pi tmp;
		if(A[i] & 1) {
			tmp = {1,0};
		}
		else {
			tmp = {0,1};
		}
		update(i,tmp);
	}
}

void init() {
	for(int i=0;i<=N;i++) {
		table[i] = {0,0};
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
	
    cin >> N;
    for(int i=1;i<=N;i++) {
    	cin >> A[i];
    }
    init();
    build();
    int Q;
    cin >> Q;
    while(Q--) {
    	int C,X,Y;
    	cin >> C >> X >> Y;
    	if(C == 0) {
    		if(A[X] % 2 != Y % 2) {
    			if(A[X] % 2 == 1 and Y % 2 == 0) {
    				update(X, {-1,1});
    			}
    			else {
    				update(X,{1,-1});
    			}
    		}
    		A[X] = Y;
    	}
    	else {
    		pi ans = compute(X,Y);
    		cout << (C == 2?ans.first:ans.second) << '\n';
    	}
    }
}
 
// read the question correctly (ll vs int)
// template by bqi343