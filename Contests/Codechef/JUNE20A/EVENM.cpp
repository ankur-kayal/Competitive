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
    	int n;
    	cin >> n;
    	int arr[n+1][n+1];
    	int ok = 1;
    	int ele = 1;
    	for(int i=1;i<=n;i++) {
    		if(i % 2 == 0) {
    			for(int j = 1; j <= n; j++) {
    				arr[i][j] = ele;
    				ele++;
    			}
    		}
    		else {
    			for(int j = n; j>= 1;j--) {
    				arr[i][j] = ele;
    				ele++;
    			}
    		}
    	}

    	for(int i = 1; i <= n; i++) {
    		for(int j = 1; j <= n; j++) {
    			cout << arr[i][j] << " ";
    		}
    		cout << '\n';
    	}
    }
}