#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	// #ifndef ONLINE_JUDGE
 //    // for getting input from input.txt
 //    freopen("input.txt", "r+", stdin);
 //    // for writing output to output.txt
 //    freopen("output.txt", "w+", stdout);
	// #endif

    string a,b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++) {
    	dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++) {
    	dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++) {
    	for(int j=1;j<=m;j++) {
    		if(a[i-1] == b[j-1]) {
    			dp[i][j] = dp[i-1][j-1] + 1;
    		}
    		else {
    			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    		}
    	}
    }

    // for(int i=0;i<=n;i++) {
    // 	for(int j=0;j<=m;j++) {
    // 		cout << dp[i][j] << " ";
    // 	}
    // 	cout << '\n';
    // }

    // cout << dp[n][m] << '\n';

    string c = "";
    while(n > 0 and m > 0) {
    	// cout << n << " " << m << '\n';
    	if(a[n-1] == b[m-1]) {
    		c = a[n-1] + c;
    		m--;
    		n--;
    		// continue;
    	}
    	else if(dp[n-1][m] > dp[n][m-1]) {
    		n--;
    		// continue;
    	}
    	else {
    		m--;
    		// continue;
    	}
    }
    cout << c;
}