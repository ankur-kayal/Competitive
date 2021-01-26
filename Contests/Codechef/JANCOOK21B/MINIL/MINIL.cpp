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

void run_cases() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> pat1, pat2, a;
    pat1 = vector<vector<char>>(n, vector<char>(m));
    pat2 = vector<vector<char>>(n, vector<char>(m));
    a = vector<vector<char>>(n, vector<char>(m));


    int ans1 = 0, ans2 = 0;
    int i1 = 0, i2 = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> a[i][j];
            if((i + j) % 2 == 0) {
                pat1[i][j] = '*';
                pat2[i][j] = '.';
                i1++;
            }
            else {
                pat1[i][j] = '.';
                pat2[i][j] = '*';
                i2++;
            }
            if(a[i][j] != pat1[i][j]) {
                ans1++;
            }
            if(a[i][j] != pat2[i][j]) {
                ans2++;
            }
        }
    }
    // cerr << "Pattern 1" << nl;
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << pat1[i][j];
    //     }
    //     cerr << nl;
    // }
    // cerr << "Pattern 2" << nl;
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << pat2[i][j];
    //     }
    //     cerr << nl;
    // }
    // cerr << "Actual" << nl;
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout << a[i][j];
    //     }
    //     cerr << nl;
    // }
    if(i1 == i2)
        cout << min(ans1, ans2) << '\n';
    else if(i1 < i2)
        cout << ans2 << '\n';
    else
        cout << ans1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}