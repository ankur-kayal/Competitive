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

//----------------------------------- END DEFINES -------------------------------- 

void run_cases() {
    bool used = false;
    int n;
    cin >> n;
    vector<int64_t> a(n);
    trav(u,a) cin >> u;
    vector<int64_t> rev(a.begin(), a.end());
    reverse(all(rev));
    for(int i=0;i<n-1;i++) {
        if(a[i] > a[i+1]) {
            if(!used) {
                used = true;
                swap(a[i], a[i+1]);
                a[i+1] -= a[i];
            }
            else {
                break;
            }
        }
        else {
            a[i+1] -= a[i];
        }
        debug() << imie(a);
    }
    bool used1 = false;
    for(int i=0;i<n-1;i++) {
        if(rev[i] > rev[i+1]) {
            if(!used1) {
                used1 = true;
                swap(rev[i], rev[i+1]);
                rev[i+1] -= rev[i];
            }
            else {
                break;
            }
        }
        else {
            rev[i+1] -= rev[i];
        }
        debug() << imie(rev);
    }

    cout << (a[n-1] == 0 or rev[n-1] == 0 ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}