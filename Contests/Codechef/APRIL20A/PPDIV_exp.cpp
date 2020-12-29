#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const ll mod = 1e9 + 7;
const ll inv6 = 166666668;

ll summation(ll n) {
    n = n % mod;
    ll sum = (((n*(n+1)) % mod)  * ((((2 * n + 1) % mod)* inv6) % mod))% mod;
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
    #endif

    const ll mxm = 1e12;
    const double lmax = 18;
    vector <bool> req(1e6+10,1);
    for(int i=2;i*i<=1000000;i++) {
        if(req[i]) {
            for(int j=i*i;j<=1000000.;j*=i){
                req[j] = false;
            }
        }
    }
    vector <ll> store,precomp;
    for(int i=2;i<=1000000;i++) {
        if(req[i]) {
            store.pb(i);
        }
    }
    for(auto u: store) {
        ll tmp = u;
        for(int j=2;j<=64;j++) {
            tmp = tmp * u;
            ll sq = sqrtl(tmp);
            if(j*log10(u) < lmax){
                if(sq*sq == tmp and tmp > mxm) {
                    continue;
                }
                precomp.pb(tmp);
            }
            else {
                break;
            }
        }
    }

    // set <ll> test(precomp.begin(), precomp.end());
    // cout << test.size() << " " << precomp.size() << '\n';
    sort(precomp.begin(), precomp.end());
    // cout << store.size() << '\n';
    // for(auto u: precomp) {
    //     cout << u << '\n';
    // }
    // cout << store.size() << '\n';
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = n % mod;
        for(auto u: precomp) {
            if(u > n) {
                break;
            }
            // ans = (ans + (((n / u) % mod) * u) % mod) % mod;
            ans = (ans + (n - (n % u)) % mod)% mod;

            // cout << u << " " << n/u << '\n';
        }
        ll start = n / mxm;
        ll prev = 1000000;
        ll curr = 0;
        for(ll i=start;i>=1;i--) {
            ll sq = n / i;
            curr = sqrtl(sq);
            ans = (ans + (i*(mod + summation(curr) - summation(prev)))%mod ) % mod;
            prev = curr;
        }
        cout << ans << '\n';
        // cout << magic(4) << '\n';
    }
}