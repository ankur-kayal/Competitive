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

    int n;
    cin >> n;
    int dp[4],a[4],t[4];
    cin >> dp[1] >> dp[2] >> dp[3];
    for(int i=1;i<n;i++) {
    	cin >> a[1] >> a[2] >> a[3];
    	t[1] = t[2] = t[3] = 0;
    	for(int j=1;j<=3;j++) {
    		for(int k=1;k<=3;k++) {
    			if(j == k) continue;
    			t[j] = max(t[j],dp[k] + a[j]);
    		}
    	}
    	dp[1] = t[1];
    	dp[2] = t[2];
    	dp[3] = t[3];
    	// cout << dp[1] << " " << dp[2] << " " << dp[3] << '\n';
    }
    cout << max(dp[1],max(dp[2],dp[3])) << '\n';
}