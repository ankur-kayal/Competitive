#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array

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
    	int arr[n];
    	unordered_map <int,int> c;
    	set <int> unique;
    	for(int i=0;i<n;i++) {
    		cin >> arr[i];
    		unique.insert(arr[i]);
    		c[arr[i]]++;
    	}
    	int maxFreq = 1;
    	for(auto u: unique) {
    		maxFreq = max(maxFreq,c[u]);
    	}
    	int part = n / 2;
    	int cu = unique.size();
    	int ans = 1;
    	if(maxFreq <= part) {
    		cu--;
    	}
    	if(cu > part) {
    		cu = part;
    	}
    	ans = min(cu,maxFreq);
    	cout << ans << '\n';
    }
}