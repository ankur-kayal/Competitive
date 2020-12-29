#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

void solve() {
	int n;
	cin >> n;
	int a[n];
	map <int,int> cnt;
	int mx = 0;
	int maxc = 0;
	for(int i=0;i<n;i++) {
		cin >> a[i];
		cnt[a[i]]++;
		mx = max(cnt[a[i]],mx);
	}
	for(int i=1;i<=n;i++) {
		if(mx == cnt[i]) maxc++;
	}
	ll rest = n - maxc * mx;
	// cout << rest << '\n';
	ll fill = rest / (mx - 1);
	cout << (maxc - 1) + fill << '\n';
}

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
    	solve();
    }
}