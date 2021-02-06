#include <bits/stdc++.h>
using namespace std;

//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define nl '\n'

//----------------------------------- END DEFINES -------------------------------- 

void print_output(vector<int>& seq, int m) {
    cout << "YES" << nl;
    for(int i=0;i<=m;i++) {
        cout << seq[i % seq.size()] + 1 << ' ';
    }
    cout << nl;
}

void run_cases() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> adj(n, vector<char>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> adj[i][j];
        }
    }
    vector<int> seq;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(adj[i][j] == adj[j][i]) {
                seq = {i, j};
                print_output(seq, m);
                return;
            }
        }
    }

    if(m & 1) {
        seq = {0, 1};
        print_output(seq, m);
        return;
    }

    if(n == 2) {
        cout << "NO" << nl;
        return;
    }
    
    int a = 0, b = 1, c = 2;
    while(adj[a][b] != adj[b][c]) {
        a = (a + 1) % 3;
        b = (b + 1) % 3;
        c = (c + 1) % 3;
    }
    if((m / 2) & 1) {
        seq = {a, b, c, b};
    }
    else {
        seq = {b, c, b, a};
    }
    print_output(seq, m);
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}