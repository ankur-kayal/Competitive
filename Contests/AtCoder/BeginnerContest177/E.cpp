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

const int mxN = 1e6 + 10;

int prime[mxN];
vi cnt(mxN);

void sieve() { 
    prime[1] = 1; 
    for (int i=2; i<mxN; i++) 
        prime[i] = i; 
    for (int i=4; i<mxN; i+=2) 
        prime[i] = 2; 
  
    for (int i=3; i*i<mxN; i++) {
        if (prime[i] == i) {  
            for (int j=i*i; j<mxN; j+=i) {
            	if (prime[j]==j) {
                    prime[j] = i;
            	} 
            } 
                
        } 
    } 
} 

void factorise(int x) { 
	map <int,int> store;
    while (x != 1) 
    { 
        if(store[prime[x]] == 0) {
        	cnt[prime[x]]++;
        	store[prime[x]]++;
        }
        
        x = x / prime[x]; 
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

    sieve();
    int N;
    cin >> N;
    vi A(N);

    for(int i=0;i<N;i++) {
    	cin >> A[i];
    }

    int hcf = A[0];
    for(int i=0;i<N;i++) {
    	hcf = __gcd(A[i],hcf);
    }
    bool pc = true, sc = (hcf == 1);
    for(int i=0;i<N;i++) {
    	factorise(A[i]);
    }
    for(int i=1;i<=1000000;i++) {
    	if(cnt[i] > 1) {
    		// cout << i << '\n';
    		pc = false;
    	}
    }
    if(pc) {
    	cout << "pairwise coprime" << '\n';
    }
    else if (sc) {
    	cout << "setwise coprime" << '\n';
    }
    else {
    	cout << "not coprime";
    }
	
    
}
 
// read the question correctly (ll vs int)
// template by bqi343