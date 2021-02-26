#include <algorithm>
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

//----------------------------------- END DEFINES --------------------------------void


int find_element_less_than_equal(vector<int>& a, int target) {
    int l = -1;
    int r = (int)a.size();
    while(r > l + 1) {
        int m = (l + r) / 2;
        if(a[m] <= target) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return l;
} 

void run_cases() {
    int n,m,q;
    cin >> n >> q >> m;
    vector<int> a(n);
    trav(u, a) cin >> u;
    vector<int> ans(m + 1);

    // int Q;
    // cin >> Q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        debug() << imie(l) imie(r);
        vector<int> moves;
        int max_moves = -1;
        int min_moves = 1000000000;
        for(int i=l;i<=r;i++) {
            if(a[i] <= m) {
                moves.pb(a[i]);
                max_moves = max(max_moves, a[i]);
                min_moves = min(min_moves, a[i]);
            }
        }
        sort(all(moves));
        debug() << imie(moves);
        int cnt = 0;
        vector<vector<int>> dp(m + 1, {0, 0});
        for(int i=0;i<min(min_moves, m);i++) {
            dp[i] = {0, 1};
        }
        for(int i=1;i<=m;i++) {
            // int G = i;
            // cnt = 0;
            // while(true) {
            //     int index = find_element_less_than_equal(moves, G);
            //     debug() << imie(index);
            //     if(index == -1) {
            //         if(cnt & 1) {
            //             ans[i]++;
            //         }
            //         break;
            //     }
            //     else {
            //         G -= moves[index];
            //         cnt++;
            //     }
            // }
            for(auto u: moves) {
                if(i - u >= 0) {
                    dp[i][0] = max(dp[i - u][1], dp[i][0]);
                    dp[i][1] = max(dp[i - u][0], dp[i][1]);
                }
                else {
                    break;
                }
            }
            debug() << imie(dp);

        }
        for(auto i=1;i<=m;i++) {
            if(dp[i][0]) ans[i]++;
        }
    }

    debug() << imie(ans);

    cout << *max_element(all(ans)) << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}