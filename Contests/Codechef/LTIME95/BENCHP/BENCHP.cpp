#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
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

void solve() {
    int64_t N, W, WR;
    cin >> N >> W >> WR;
    map<int64_t, int64_t> w;
    for(int i=0;i<N;i++) {
        int foo;
        cin >> foo;
        w[foo]++;
    }
    for(auto u: w) {
        int64_t times = u.second;
        if(times & 1) {
            times--;
        }
        WR += u.first * times;
    }

    cout << (WR >= W ? "YES\n" : "NO\n");

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for(int _=0;_<t;_++) {
        solve();
    }
}