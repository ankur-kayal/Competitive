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
	
    string s;
    cin >> s;
    int l = s.length();
    string s1 = "",ps1="",s2="",ps2="",s3="",ps3="", ts3, tps3;
    for(int i=0;i<l;i++) {
    	s3 = s3 + s[i];
    	ps3 = s[i] + ps3;
    }
    bool exists = false;

    for(int i=0;i<l-2;i++) {
    	s1 = s1 + s[i];
    	ps1 = s[i] + ps1;
    	ps3.pop_back();
    	s3.erase(0,1);
    	if(s1 == ps1) {
    		ts3 = s3;
    		tps3 = ps3;
    		s2 = "";
    		ps2 = "";
    		for(int j=i+1;j<l-1;j++) {
    			s2 = s2 + s[j];
    			ps2 = s[j] + ps2;
    			ts3.erase(0,1);
    			tps3.pop_back();
    			if(s2 == ps2 and ts3 == tps3) {
    				exists = true;
    				break;
    			}
    		}
    	}
    	if(exists == true) {
    		break;
    	}
    }
    if(exists) {
    	cout << s1 << '\n';
    	cout << s2 << '\n';
    	cout << ts3 << '\n';
    }
    else {
    	cout << "Impossible" << '\n';
    }
}
 
// read the question correctly (ll vs int)
// template by bqi343