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

    int n,q;
    cin >> n >> q;
    int h[n+1],a[n+1];
    for(int i=1;i<=n;i++) {
    	cin >> h[i];
    }
    for(int i=1;i<=n;i++) {
    	cin >> a[i];
    }
    while(q--) {
    	// cout << "jo" << ' ';
    	int ch, start,end,value;
    	cin >> ch;
    	if(ch == 1) {
    		cin >> start >> value;
    		a[start] = value;
    	}
    	else if(ch == 2) {
    		cin >> start >> end;
    		ll ans = 0;
    		if(start > end) {
    			ll prevHeight = -1;
    			for(int i=end;i<start;i++) {
    				if(prevHeight < h[i]) {
    					ans+=a[i];
    					prevHeight = h[i];
    				}
    			}
    			if(prevHeight < h[start]) {
    				cout << ans+a[start] << '\n';
    			}
    			else {
    				cout << -1 << '\n';
    			}
    		}
    		else if(start < end) {
    			ll prevHeight = -1;
    			for(int i=end;i>start;i--) {
    				if(prevHeight < h[i]) {
    					ans+=a[i];
    					prevHeight = h[i];
    				}
    			}
    			if(prevHeight < h[start]) {
    				cout << ans+a[start] << '\n';
    			}
    			else {
    				cout << -1 << '\n';
    				cout << prevHeight << " " << h[start] << " " << h[end] << '\n';
    			}
    		}
    		else {
    			cout << a[start] << '\n';
    		}
    	}
    }
}