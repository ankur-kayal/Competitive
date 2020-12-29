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

    int t = 1;
    while(t--) {
    	ll x,y,l,r;
    	x = 400;
    	y = 963;
    	l = 0;
    	r = (x|y);
    	for(int i=r;i>=0;i--) {
    		ll val = -1;
    		ll ans = 0;
    		for(int j=l;j<=i;j++) {
    			ll tmp = (x & j) * (y & j);
    			if(tmp > val) {
    				val = tmp;
    				ans = j;
    			}
    		}
    		ll ans2 = (x|y) & i;
    		if(ans2 != ans) {
    			cout << i << endl;
    		}
    	}
    }
}