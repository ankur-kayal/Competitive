#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    int t;
    cin >> t;
    while(t--) {
    	ll n,x;
    	cin >> n >> x;
    	ll a[n];
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    	}
    	sort(a,a+n);
    	vector <ll> store;
    	ll prev = 0;
    	ll curr = 0;
    	ll ans = 0;
    	ll rotation = 0;
    	while(curr < n) {
    		// cout << x << '\n';
    		rotation++;
    		while(2 * a[curr] <= x and curr < n) {
    			store.pb(a[curr]);
    			curr++;
    			prev++;
    		}
    		while(x >= a[curr] and x < 2 * a[curr] and curr < n) {
    			store.pb(a[curr]);
    			curr++;
    		}
    		
    		// cout << curr << " " << prev << " " << x << '\n';

    		if(curr == prev and curr != n) {
    			x = x * 2;
    		}
    		else {
    			assert(store.size() > 0);
    			ll ele = store.back();
    			store.pop_back();
    			x = ele * 2;
    			prev = curr;
    		}
    		// for(auto u: store) {
    		// 	cout << u << '\n';
    		// }
    		ans++;
    		if(store.size() > 0) {
	    		ll ele = store.back();
	    		if(ele * 2 <= x and curr == n) {
	    			// cout << ans << '\n';
	    			ans+= store.size();
	    			break;
	    		}
    		}
    		// if(rotation > 5000) {
    		// 	break;
    		// }
    	}
    	cout << ans << '\n';
    }
}