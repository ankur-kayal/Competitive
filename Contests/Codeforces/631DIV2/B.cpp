#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

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
    	unordered_map <ll,ll> count;
    	ll n;
    	cin >> n;
    	vector <pair<ll,ll>> ans;
    	vector <ll> a(n);
    	ll mxm = 0;
    	for(ll i=0;i<n;i++) {
    		cin >> a[i];
    		count[a[i]]++;
    		mxm = max(mxm,a[i]);
    	}

    	ll l1=0;
    	ll l2=0;
    	for(ll i=1;i<=mxm;i++) {
    		if(count[i] == 2) {
    			if(i-l1 == 1) {
    				l1++;
    			}
    		}
    		if(count[i] >= 1) {
    			if(i - l2 == 1) {
    				l2++;
    			}
    		}
    	}
    	if(l1 + l2 != n) {
    		cout << 0 << '\n';
    		continue;
    	}
    	vector <ll> pre(n);
    	pre[0] = a[0];
    	vector <ll> suf(n);
    	suf[n-1] = a[n-1];
    	for(ll i=1;i<n;i++) {
    		pre[i] = pre[i-1] + a[i];
    	}
    	// for(auto u: pre) {
    	// 	cout << u << " ";
    	// }
    	// cout << '\n';
    	for(ll i=n-2;i>=0;i--) {
    		suf[i] = suf[i+1] + a[i];
    	}
    	// for(auto u: suf) {
    	// 	cout << u << " ";
    	// }
    	// cout << '\n';
    	for(ll i=1;i<n;i++) {
    		if(pre[i-1] == (i*(i+1) / 2) and suf[i] == ((n-i+1) * (n-i) / 2)) {
    			ans.pb(mp(i,n-i));
    		}
    	}
    	cout << ans.size() << '\n';
    	for(auto u: ans) {
    		cout << u.first << " " << u.second << '\n'; 
    	}
    	// cout << '\n';
    }
}