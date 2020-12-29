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
    	int a[n][m];
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			cin >> a[i][j];
    		}
    	}
    	int cnt[n+m-1][2];
    	for(int i=0;i<n+m-1;i++) {
    		cnt[i][0] = 0;
    		cnt[i][1] = 0;
    	}
    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			cnt[i+j][a[i][j]]++;
    		}
    	}
    	int ans = 0;
    	for(int i=0;i<n+m-1;i++) {
    		// cout << cnt[i][0] << " " << cnt[i][1] << '\n';
    		int j = n + m - 2 - i;
    		// cout << cnt[j][0] << " " << cnt[j][1] << '\n';
    		if(i <= j) continue;
    		ans+=min(cnt[i][0]+cnt[j][0], cnt[i][1] + cnt[j][1]);
    	}
    	cout << ans << '\n';
    }
}