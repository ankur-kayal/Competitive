// A Recursive C program to solve minimum sum partition 
// problem. 
#include <bits/stdc++.h> 
using namespace std; 

#define ll long long

// Returns the minimum value of the difference of the two sets. 
ll findMin(ll arr[], ll n) 
{ 
	// Calculate sum of all elements 
	ll sum = 0; 
	for (ll i = 0; i < n; i++) 
		sum += arr[i]; 

	// cout << sum << '\n';
	// return 0;
	// Create an array to store results of subproblems 
	bool dp[n+1][sum+1]; 


	// Initialize first column as true. 0 sum is possible 
	// with all elements. 
	for (ll i = 0; i <= n; i++) 
		dp[i][0] = true; 

	// Initialize top row, except dp[0][0], as false. With 
	// 0 elements, no other sum except 0 is possible 
	for (ll i = 1; i <= sum; i++) 
		dp[0][i] = false; 
	

	// Fill the partition table in bottom up manner 
	for (ll i=1; i<=n; i++) 
	{ 
		for (ll j=1; j<=sum; j++) 
		{ 
			// If i'th element is excluded 
			dp[i][j] = dp[i-1][j]; 

			// If i'th element is included 
			if (arr[i-1] <= j) 
				dp[i][j] |= dp[i-1][j-arr[i-1]]; 
		} 
	} 

	// Initialize difference of two sums. 
	ll diff = 1e18; 
	
	// Find the largest j such that dp[n][j] 
	// is true where j loops from sum/2 t0 0 
	for (ll j=sum/2; j>=0; j--) 
	{ 
		// Find the 
		if (dp[n][j] == true) 
		{ 
			diff = sum-2*j; 
			break; 
		} 
	} 
	return diff; 
} 

// Driver program to test above function 
int main() 
{

	ios_base::sync_with_stdio(0); cin.tie(0);  

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif
	
	ll k;
	cin >> k;
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		ll arr[n];
		for(ll i=0;i<n;i++) {
			int ele = 1;
			for(int j=0;j<k;j++) {
				ele *= (i+1);
			}
			arr[i] = ele;
		}
		// for(ll i=0;i<n;i++) {
		// 	cout << arr[i] << '\n';
		// }
		cout << n << " " << findMin(arr,n) << '\n';
		// cout << "The minimum difference between 2 sets is " << findMin(arr, n) << '\n'; 
	}   
	// ll arr[] = {1,4,9,16,25,36,49}; 
	// ll n = sizeof(arr)/sizeof(arr[0]); 
	
	return 0; 
} 
