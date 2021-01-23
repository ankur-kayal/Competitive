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
    int n;
    cin >> n;
    vector<int> a(n);
    trav(u, a) cin >> u;

    int power = 0;

    int waste = 0;
    for(int i=1;i+1<n;i++) {
        if(a[i] > a[i+1] and a[i] > a[i - 1]) {
            power++;
            waste = 1;
        }
        if(a[i] < a[i + 1] and a[i] < a[i - 1]) {
            power++;
            waste = 1;
        }
    }

    debug() << imie(power);

    for(int i=0;i<n;i++) {
        if(i + 4 < n) {
            // 2 5 3 6 1
            if(a[i] < a[i + 1] and a[i + 1] > a[i + 2] and a[i + 2] < a[i + 3] and a[i + 3] > a[i + 4]) {
                waste = max(waste, 3);
            }
            // 5 3 6 1 4
            if(a[i] > a[i + 1] and a[i + 1] < a[i + 2] and a[i + 2] > a[i + 3] and a[i + 3] < a[i + 4]) {
                waste = max(waste, 3);
            }
            // // 5 6 5 4 5
            // if(a[i] < a[i + 1] and a[i + 1] > a[i + 2] and a[i + 2] > a[i + 3] and a[i + 3] < a[i + 4]) {
            //     waste = max(waste, 2);
            // }

            // // 5 4 5 6 5
            // if(a[i] > a[i + 1] and a[i + 1] < a[i + 2] and a[i + 2] < a[i + 3] and a[i + 3] > a[i + 4]) {
            //     waste = max(waste, 2);
            // }
        }

        if(i + 3 < n) {
            // 5 2 5 2
            if(a[i] > a[i + 1] and a[i + 1] < a[i + 2] and a[i + 2] > a[i + 3]) {
                waste = max(waste, 2);
            }
            // 2 5 2 5
            if(a[i] < a[i + 1] and a[i + 1] > a[i + 2] and a[i + 2] < a[i + 3]) {
                waste = max(waste, 2);
            }
        }
    }

    cout << power - waste << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}