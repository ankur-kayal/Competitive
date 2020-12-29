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

    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	if(n < 4) {
    		cout << -1 << '\n';
    		continue;
    	}
    	else {
    		if(n % 2 == 1) {
    			for(int i=n;i>=1;i-=2) {
    				cout << i << " ";
    			}
    			cout << 4 << " ";
    			for(int i=2;i<=n;i+=2) {
    				if(i != 4) {
    					cout << i << " ";
    				}
    			}
    			cout << '\n';
    		}
    		if(n % 2 == 0) {
    			for(int i=n - 1;i>=1;i-=2) {
    				cout << i << " ";
    			}
    			cout << 4 << " ";
    			for(int i=2;i<=n;i+=2) {
    				if(i != 4) {
    					cout << i << " ";
    				}
    			}
    			cout << '\n';
    		}
    	}
    }
}