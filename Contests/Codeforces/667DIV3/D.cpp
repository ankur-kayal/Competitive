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
    	string S;
    	int K;
    	cin >> S >> K;
    	reverse(all(S));
    	vector <int> digits(19);
    	vector <int> ans(19,0);
    	int sum = 0;
    	for(int i=0;i<S.length();i++) {
    		digits[19-1-i] = S[i] - '0';
    		sum += S[i] - '0';
    	}
    	int start = 19 - S.length();
    	// for(int i=)
    	int tmp = 0;
    	for(int i=start;i<19;i++) {
    		ans[i] = digits[i];
    		tmp = tmp + digits[i];
    		// cout << tmp << '\n';
    		if(tmp > K or(tmp == K and sum > K)) {
    			ans[i] = 0;
    			int index = i - 1;
    			// cout << i << '\n';
    			while(true) {
    				ans[index] += 1;
    				if(ans[index] == 10) {
    					ans[index] = 0;
    					index--;
    				}
    				else {
    					goto calc;
    				}
    			}
    		}
    	}

    	calc:
    	ll num1 = 0;
    	reverse(all(digits));
    	reverse(all(ans));
    	ll mul = 1;
    	for(int i=0;i<19;i++) {
    		num1 += digits[i] * mul;
    		mul*=10;
    	}
    	ll num2 = 0;
    	mul = 1;
    	for(int i=0;i<19;i++) {
    		num2 += ans[i] * mul;
    		mul*=10;
    	}
    	cout << (num2 - num1) << '\n';
    	// cout << start << '\n';
    	// for(auto u: ans) {
    	// 	cout << u << " ";
    	// }
    	// cout << '\n';
    }
}
 
// read the question correctly (ll vs int)
// template by bqi343