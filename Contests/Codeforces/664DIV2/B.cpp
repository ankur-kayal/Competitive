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

    int t = 1;
    // cin >> t;
    while(t--) {
    	int n,m,x,y;
    	cin >> n >> m >> x >> y;
    	int vis[n+1][m+1];
    	for(int i=1;i<=n;i++) {
    		for(int j=1;j<=m;j++) {
    			vis[i][j] = 0;
    		}
    	}
    	int moves = n * m;
    	cout << x << " " << y << '\n';
    	moves--;
    	vis[x][y] = 1;
    	x = 1;
    	cout << x <<  " " << y << '\n';
    	moves--;
    	vis[x][y] = 1;
    	y = 1;
    	cout << x << " " << y << '\n';
    	vis[x][y] = 1;
    	moves--;
    	int i,j;
    	i=1;
    	j = 1;
    	while(moves > 0) {
    		for(;j<=m;j++) {
    			if(vis[i][j] == 0) {
    				vis[i][j] == 1;
    				cout << i << " " << j << '\n';
    				moves--;
    			}
    		}
    		i++;
    		if(moves > 0) {
    			j = min(m,j);
    			for(;j>=1;j--) {
    				if(vis[i][j] == 0) {
	    				vis[i][j] == 1;
	    				cout << i << " " << j << '\n';
	    				moves--;
	    			}
    			}
    		}
    		j = max(1,j);
    		i++;
    		// break;
    	}
     }
}