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
    	int n,k,z;
    	cin >> n >> k >> z;
    	int a[n];
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    	}
    	int ans = 0;
    	for(int i=0;i<=z;i++) {
    		int maxPair = -1;
    		int sum = 0;
    		int adjSum = 0;
    		for(int j=0;j<=k-2*i;j++) {
    			sum+=a[j];
    			adjSum = a[j] + a[j+1];
    			maxPair = max(maxPair,adjSum);
    		}
    		// cout << sum << '\n';
    		sum += i*maxPair;
    		ans = max(ans,sum);
    	}
    	cout << ans << '\n';
    }
}