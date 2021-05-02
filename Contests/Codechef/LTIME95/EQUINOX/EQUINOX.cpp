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
    int64_t n, a, b;
    cin >> n >> a >> b;
    string t = "EQUINOX";
    int64_t p1 = 0, p2 = 0;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        bool ok = false;
        for(auto u: t) {
            if(s[0] == u) {
                p1 += a;
                ok = true;
                break;
            }
        }
        if(!ok) {
            p2 += b;
        }
    }

    if(p1 == p2) {
        cout << "DRAW" << '\n';
    } else if(p1 > p2) {
        cout << "SARTHAK\n";
    } else {
        cout << "ANURADHA\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    for(int _=0;_<t;_++) {
        solve();
    }
}