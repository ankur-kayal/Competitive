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
    
    int k;
    cin >> k;
    if(k == 1) {
        int t;
        cin >> t;
        while(t--) {
            int n;
            cin >> n;
            if(n % 4 == 0) {
                cout << 0 << '\n';
            }
            else if(n % 4 == 1) {
                cout << 1 << '\n';
                cout << '1';
            }
            else if(n % 4 == 2) {
                cout << 1 << '\n';
                cout << "10";
            }
            else {
                cout << 0 << '\n';
                cout << "110";
            }
            for(int i=0;i<n/4;i++) {
                cout << "1001";
            }
            cout << '\n';
        }
    }
    else if(k == 2) {
        int t;
        cin >> t;
        while(t--) {
            int n;
            cin >> n;
            int N = n;
            string S="";
            if(n % 8 == 0) {
                cout << 0 << '\n';
            }
            else if(n < 8) {
                if(n % 8 == 1) {
                    cout << 1 << '\n';
                    S=+"1";
                    // cout << "1";
                    n-=1;
                }
                else if(n % 8 == 2) {
                    cout << 3 << '\n';
                    S=+"01";
                    // cout << "01";
                    n-=2;
                }
                else if(n % 8 == 3) {
                    cout << 4 << '\n';
                    // cout << "001";
                    S+="001";
                    n-=3;
                }
                else if(n % 8 == 4) {
                    cout << 2 << '\n';
                    // cout << "0001";
                    S+="0001";
                    n-=4;
                }
                else if(n % 8 == 5) {
                    cout << 3 << '\n';
                    // cout << "01001";
                    S+="01001";
                    n-=5;
                }
                else if(n % 8 == 6) {
                    cout << 1 << '\n';
                    
                    S+="101001";
                    n-=6;
                }
                else if(n % 8 == 7) {
                    cout << 0 << '\n';
                    
                    S+="1101001";
                    n-=7;
                }
            }
            else {
                if(n % 8 == 1) {
                    cout << 1 << '\n';
                    // cout << "100111010";
                    S+="100111010";
                    n-=9;
                }
                else if(n % 8 == 2) {
                    cout << 1 << '\n';
                    // cout << "1011011010";
                    S+="1011011010";
                    n-=10;
                }
                else if(n % 8 == 3) {
                    cout << 0 << '\n';
                    // cout << "10111000101";
                    S+="10111000101";
                    n-=11;
                }
                else if(n % 8 == 4) {
                    cout << 0 << '\n';
                    // cout << "111111110010";
                    S+="111111110010";
                    n-=12;
                }
                else if(n % 8 == 5) {
                    cout << 1 << '\n';
                    // cout << "1110111101100";
                    S+="1110111101100";
                    n-=13;
                }
                else if(n % 8 == 6) {
                    cout << 1 << '\n';
                    // cout << "11110011011100";
                    S+="11110011011100";
                    n-=14;
                }
                else if(n % 8 == 7) {
                    cout << 0 << '\n';
                    // cout << "110001011011100";
                    S+="110001011011100";
                    n-=15;
                }
            }
            
            for(int i=0;i<n/8;i++) {
                
                S+="01101001";
            }
            assert(S.length() == N);
            cout << S << '\n';
        }
    }
    else if(k == 3) {
        int t;
        cin >> t;
        while(t--) {
            int n;
            cin >> n;
            int N = n;
            string S="";
            if(n % 16 == 0) {
                cout << 0 << '\n';
            }
            else if(n < 16) {
                if(n % 16 == 1) {
                    cout << 1 << '\n';
                    S=+"1";
                    // cout << "1";
                    n-=1;
                }
                else if(n % 16 == 2) {
                    cout << 7 << '\n';
                    S=+"01";
                    // cout << "01";
                    n-=2;
                }
                else if(n % 16 == 3) {
                    cout << 18 << '\n';
                    // cout << "001";
                    S+="001";
                    n-=3;
                }
                else if(n % 16 == 4) {
                    cout << 28 << '\n';
                    // cout << "0001";
                    S+="0001";
                    n-=4;
                }
                else if(n % 16 == 5) {
                    cout << 25 << '\n';
                    // cout << "01001";
                    S+="11110";
                    n-=5;
                }
                else if(n % 16 == 6) {
                    cout << 7 << '\n';
                    
                    S+="101110";
                    n-=6;
                }
                else if(n % 16 == 7) {
                    cout << 26 << '\n';
                    // cout << "1101001";
                    S+="0001110";
                    n-=7;
                }
                else if(n % 16 == 8) {
                    cout << 4 << '\n';
                    // cout << "1101001";
                    S+="00110110";
                    n-=8;
                }
                else if(n % 16 == 9) {
                    cout << 5 << '\n';
                    // cout << "1101001";
                    S+="011010110";
                    n-=9;
                }
                else if(n % 16 == 10) {
                    cout << 1 << '\n';
                    // cout << "1101001";
                    S+="0111111010";
                    n-=10;
                }
                else if(n % 16 == 11) {
                    cout << 12 << '\n';
                    // cout << "1101001";
                    S+="11110010110";
                    n-=11;
                }
                else if(n % 16 == 12) {
                    cout << 0 << '\n';
                    // cout << "1101001";
                    S+="001011100110";
                    n-=12;
                }
                else if(n % 16 == 13) {
                    cout << 1 << '\n';
                    // cout << "1101001";
                    S+="1111101111100";
                    n-=13;
                }
                else if(n % 16 == 14) {
                    cout << 1 << '\n';
                    // cout << "1101001";
                    S+="10100110010110";
                    n-=14;
                }
                else if(n % 16 == 15) {
                    cout << 0 << '\n';
                    // cout << "1101001";
                    S+="001111010111100";
                    n-=15;
                }
            }
            else {
                if(n % 16 == 1) {
                    cout << 1 << '\n';
                    S=+"00010110111110010";
                    // cout << "1";
                    n-=17;
                }
                else if(n % 16 == 2) {
                    cout << 1 << '\n';
                    S=+"010011010101011010";
                    // cout << "01";
                    n-=18;
                }
                else if(n % 16 == 3) {
                    cout << 0 << '\n';
                    // cout << "001";
                    S+="1100110110100111100";
                    n-=19;
                }
                else if(n % 16 == 4) {
                    cout << 0 << '\n';
                    // cout << "0001";
                    S+="01011111110111111000";
                    n-=20;
                }
                else if(n % 16 == 5) {
                    cout << 1 << '\n';
                    // cout << "01001";
                    S+="100111111110101101100";
                    n-=21;
                }
                else if(n % 16 == 6) {
                    cout << 1 << '\n';
                    // cout << "101001";
                    S+="1111111111111110111000";
                    n-=22;
                }
                else if(n % 16 == 7) {
                    cout << 0 << '\n';
                    // cout << "1101001";
                    S+="10001111101111110111000";
                    n-=23;
                }
                else if(n % 16 == 8) {
                    cout << 0 << '\n';
                    // cout << "1101001";
                    S+="101011110110111110111000";
                    n-=24;
                }
                else if(n % 16 == 9) {
                    cout << 1 << '\n';
                    // cout << "1101001";
                    S+="0001111011111111111110000";
                    n-=25;
                }
                else if(n % 16 == 10) {
                    cout << 1 << '\n';
                    // cout << "1101001";
                    S+="10110011010111111111110000";
                    n-=26;
                }
                else if(n % 16 == 11) {
                    cout << 0 << '\n';
                    // cout << "1101001";
                    S+="011101101111111011111110000";
                    n-=27;
                }
                else if(n % 16 == 12) {
                    cout << 0 << '\n';
                    // cout << "1101001";
                    S+="0010101110110110111111110000";
                    n-=28;
                }
                else if(n % 16 == 13) {
                    cout << 1 << '\n';
                    // cout << "1101001";
                    S+="00000010010111111110111110000";
                    n-=29;
                }
                else if(n % 16 == 14) {
                    cout << 1 << '\n';
                    // cout << "1101001";
                    S+="001100100101111111111101110000";
                    n-=30;
                }
                else if(n % 16 == 15) {
                    cout << 0 << '\n';
                    
                    S+="0011110101111000110100110010110";
                    n-=31;
                }
            }
            
            for(int i=0;i<n/16;i++) {
                
                S+="0110100110010110";
            }
            assert(S.length() == N);
            cout << S << '\n';
        }
    }
    
}
 
// read the question correctly (ll vs int)
// template by bqi343