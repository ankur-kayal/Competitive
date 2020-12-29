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
    	int n,m;
    	cin >> n >> m;
    	char grid[n+1][m+1];
    	for(int i=0;i<=n;i++) {
    		for(int j=0;j<=m;j++) {
    			grid[i][j] == '#';
    		}
    	}
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			cin >> grid[i][j];
    		}
    	}
    	int ans = 0;
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			if(j == m-1 and grid[i][j] == 'R') {
    				ans++;
    				continue;
    			}
    			if(i == n-1 and grid[i][j] == 'D') {
    				ans++;
    				continue;
    			}
    		}
    	}
    	cout << ans << '\n';
    }
}