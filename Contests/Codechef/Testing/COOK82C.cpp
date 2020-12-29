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

    int n,m;
    cin >> n >> m;
    ll a[n];
    for(int i=0;i<n;i++) {
    	cin >> a[i];
    }
    sort(a,a+n);
    queue <ll> q1,q2;
    for(int i=n-1;i>=0;i--) {
    	q1.push(a[i]);
    }
    ll index = 0;
    for(int i=0;i<m;i++) {
    	ll query;
    	cin >> query;
    	ll ans;
    	while(index != query) {
    		if(q2.empty()) {
    			ans = q1.front();
    			q1.pop();
    			q2.push(ans/2);
    		}
    		else if(q1.empty()) {
    			ans = q2.front();
    			q2.pop();
    			q1.push(ans/2);
    		}
    		else {
    			ll x = q1.front();
    			ll y = q2.front();
    			if(x > y) {
    				ans = x;
    				q2.push(x / 2);
    				q1.pop();
    			}
    			else {
    				ans = y;
    				q2.push(y / 2);
    				q2.pop();
    			}
    		}
    		index++;
    	}
    	cout << ans << '\n';
    }
}