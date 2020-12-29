#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
    #endif

    set <ll> store;
    ll maxN = 1e12;
    ll maxm = ceil(log2(maxN));
    ll upper = ceil(sqrtl(maxN));
    for(int i=2;i<=upper;i++) {
        if(store.find(i) != store.end()) {
            continue;
        }
        ll tmp = i;
        for(int j=2;j<=maxm;j++) {
            tmp = tmp * i;
            if(tmp > 0 and tmp <=maxN) {
                store.insert(tmp);
            }
            else {
                break;
            }
        }
    }
    // sort(store.begin(), store.end());
    cout << store.size() << '\n';
    // for(auto u: store) {
    //     cout << u << '\n';
    // }
    // cout << store.size() << '\n';
    /*int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans =0;
        int c = 1;
        for(auto u: store) {
            if(u > n) {
                break;
            }
            // ans = (ans + (((n / u) % mod) * u) % mod) % mod;
            ans = (ans + (n % u) % mod) % mod;
            c++;
            // cout << u << " " << n % u << '\n';

            // cout << u << " " << n/u << '\n';
        }
        // cout << c << '\n';
        ans = ( mod + (c * (n % mod))%mod - ans)%mod;
        cout << ans << '\n';
        // cout << magic(4) << '\n';
    }*/
}