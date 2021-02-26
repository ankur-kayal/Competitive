#include <bits/stdc++.h>
#include "testlib.h";
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

void run_cases(int Q) {
    int n = (1 << 16);
    debug() << imie(n);
    vector<int> parent(n + 1);
    for(int i=1;i<(n >> 1);i++) {
        parent[2 * i] = i;
        parent[2 * i + 1] = i;
    }
    cout << n - 1 << nl;
    for(int i=2;i<n;i++) {
        cout << parent[i] << " ";
    }
    cout << nl;
    cout << Q << nl;
    for(int i=1;i<=Q;i++) {
        cout << 1 << " " << (1 << 12) << nl;
    }

}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;
    registerGen(argc, argv, 1);
    int Q = opt<int>(1);
    for(int test = 1;test <= tests;test++) {
        // run_cases(10);
        // run_cases(100);
        // run_cases(1000);
        // run_cases(10000);
        // run_cases(100000);
        run_cases(Q);
    }
}