#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int mod = 1e9+7;

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
    	ll ans = 0;
    	int a[n];
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    	}
    	sort(a,a+n,greater <int> ());
    	for(int i=0;i<n;i++) {
    		ans = (ans + max(0,a[i] - i))%mod;
    	}
    	cout << ans << '\n';
    }
}