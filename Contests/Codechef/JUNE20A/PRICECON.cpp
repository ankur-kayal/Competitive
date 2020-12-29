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
    	int n,k;
    	cin >> n >> k;
    	int ans = 0;
    	for(int i=0;i<n;i++) {
    		int ele;
    		cin >> ele;
    		ans += (ele > k ? (ele - k) : 0 );
    	}
    	cout << ans << '\n';
    }
}