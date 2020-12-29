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

vector <int> par;
vector <int> r,pts;

int get(int v) {
    if(par[v] != v) {
        return get(par[v]);
    }
    return par[v];

}

void merge(int u, int v) {
    u = get(u);
    v = get(v);
    if(u == v) {
        return;
    }
    if(r[u] == r[v]) {
        r[u]++;
    }
    if(r[u] > r[v]) {
        par[v] = u;
        pts[v] -= pts[u];
    }
    else {
        par[u] = v;
        pts[u] -= pts[v];
    }
}

void gift(int u, int val) {
    u = get(u);
    pts[u] += val;
}

int calculate(int v) {
    int score = pts[v];
    if(par[v] != v) {
        return score + calculate(par[v]);
    }
    return score;
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif  
    
    int n,m;
    cin >> n >> m;
    par.resize(n+1);
    r.resize(n+1);
    pts.resize(n+1);
    for(int i=1;i<=n;i++) {
        par[i] = i;
        r[i] = 0;
        pts[i] = 0;
    }
    while(m--) {
        string ch;
        int u,v;
        cin >> ch;
        if(ch == "join") {
            cin >> u >> v;
            merge(u,v);
        }
        else if(ch == "add") {
            cin >> u >> v;
            gift(u,v);
        }
        else {
            cin >> u;
            cout << calculate(u) << '\n';
            
        }
    }
    // for(int i=1;i<=n;i++) {
    //     cout << pts[i] << " ";
    // }
    // cout << '\n';
    // for(int i=1;i<=n;i++) {
    //     cout << get(i) << " ";
    // }
    // cout << '\n';
}
 
// read the question correctly (ll vs int)
// template by bqi343