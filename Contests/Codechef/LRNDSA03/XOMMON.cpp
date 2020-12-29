#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    int n;
    cin >> n;
    ll arr[n];
    for(int i=0;i<n;i++) {
    	cin >> arr[i];
    }
    vector <ar<ll,3>> store;
    for(int i=0;i<n;i++) {
    	for(int j=i+1;j<n;j++) {
    		store.pb({arr[i]^arr[j],i,j});
    	}
    }

    sort(store.begin(),store.end());

    vector <ll> dp(n,1);

    for(auto u: store) {
    	dp[u[2]] = max(dp[u[2]],dp[u[1]] + 1);
    }

    ll ans = *max_element(dp.begin(),dp.end());
    assert(ans != 0);
    cout << ans << '\n';
}