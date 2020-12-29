#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

void solve() {
	int n,m;
	cin >> n >> m;
	int a[n],b[m];
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	for(int i=0;i<m;i++) {
		cin >> b[i];
	}
	int ans = 512;
	for(int i=0;i<=512;i++) {
		bool pos = 1;
		for(int j = 0;j<n;j++) {
			bool ok = 0;
			for(int k=0;k<m;k++) {
				int ab = a[j] & b[k];
				if((ab | i) == i) {
					ok  = 1;
					break;
				}
			}
			pos = pos & ok;
		}
		if(pos) {
			ans = min(ans,i);
		}
	}
	cout << ans << '\n';
}

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
		solve();
	}
}