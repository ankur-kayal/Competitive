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
void simulate(vector<int> & a) {
    vector<int> d;
    for(int i=0;i<a.size();i++) {
        int sum = 0;
        for(auto u: a) {
            sum += abs(a[i] - u);
        }
        d.pb(sum);
    }
    debug() << imie(d);
}

void run_cases() {
    int64_t n;
    cin >> n;
    vector<int64_t> d(2 * n);
    trav(u, d) cin >> u;
    sort(all(d));
    vector<int64_t> reduced;
    for(int i=0;i<2*n;i+=2) {
        reduced.pb(d[i]);
        if(d[i] != d[i + 1] or (d[i] % 2 == 1 or d[i+1] % 2 == 1)) {
            cout << "NO" << '\n';  
            return;
        }
    }
    reverse(all(reduced));
    debug() << imie(reduced);
    vector<int64_t> a(n);
    if(reduced[0] % (2 * n) == 0) {
        a[0] = reduced[0] / 2 / n;
        int64_t sum = a[0];
        for(int i=1;i<n;i++) {
            if((reduced[i] - 2 * sum) % (2 * (n - i)) == 0) {
                a[i] = (reduced[i] - 2 * sum) / (2 * (n - i));
                sum += a[i];
            }
            else {
                cout << "NO" << nl;
                return;
            }
            if(a[i] <= 0 or a[i] >= a[i - 1]) {
                cout << "NO" << nl;
                return;
            }
            
        }

        cout << "YES" << nl;
    }
    else {
        cout << "NO" << nl;
    }
    debug() << imie(a);

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}