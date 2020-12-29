#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

bool comp(pair<int,int> a, pair<int,int> b) {
	return (a.first < b.first);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
	#endif

	int n;
	int w;
	cin >> n >> w;
	vector <pair<int,int>> ele(n);
	for(int i=0,a,b;i<n;i++) {
		cin >> a >> b;
		ele[i] = mp(a,b);
	}
	sort(ele.begin(),ele.end(),comp);
	// for(int i=0;i<n;i++) {
	// 	cout << ele[i].first << " " << ele[i].second << '\n';
	// }

	ll dp[n+1][w+1];
	for(int i=0;i<=n;i++) {
		dp[i][0] = 0;
	}
	for(int i = 0;i<=w;i++) {
		dp[0][i] = 0;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=w;j++) {
			pair<int,int> obj = ele[i-1];
			int wt = obj.first;
			int val = obj.second;
			if(j >= wt) {
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt] + val);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	// for(int i=0;i<=n;i++) {
	// 	for(int j=0;j<=w;j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << '\n';
	// }
	cout << dp[n][w] << '\n';

}