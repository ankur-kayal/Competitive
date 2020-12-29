#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

vector <vector<int>> all;

void printArray(vector<int> arr, int n) 
{ 
    all.pb(arr);
} 

void printSubsequences(vector<int> arr, int index, vector<int> subarr) 
{ 
    // Print the subsequence when reach 
    // the leaf of recursion tree 
    if (index == arr.size()) 
    { 
        int l = subarr.size(); 
  
        // Condition to avoid printing 
        // empty subsequence 
        if (l != 0) 
            printArray(subarr, l); 
    } 
    else
    { 
        // Subsequence without including 
        // the element at current index 
        printSubsequences(arr, index + 1, subarr); 
  
        subarr.push_back(arr[index]); 
  
        // Subsequence including the element 
        // at current index 
        printSubsequences(arr, index + 1, subarr); 
    } 
    return; 
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
    	int n;
    	cin >> n;
    	vector <int> a(n);
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    	}
    	vector <int> b;
    	all.clear();
    	printSubsequences(a, 0, b); 
    	vector <int> ans(n+1,0);
    	// int adj[n+1][n+1];
    	// for(int i=1;i<=n;i++) {
    	// 	for(int j=1;j<=n;j++) {
    	// 		adj[i][j] = 0;
    	// 	}
    	// }
    	map<int,int> c;
    	for(int i=0;i<n;i++) {
    		c[a[i]]++;
    	}
    	for(auto u: all) {
    		map <int,int> cnt;
    		int mx=0;
    		for(auto v : u) {
    			cnt[v]++;
    			mx = max(mx, cnt[v]);
    		}
    		int maxc = 1e9;
    		for(auto v: u) {
    			if(cnt[v] == mx) {
    				maxc = min(maxc, v);
    			}
    		}
    		ans[maxc]++;
    		// adj[maxc][mx]++;

    	}
	    for(int i=1;i<=n;i++) {
	    	// for(int j=1;j<=c[i];j++) {
	    	// 	cout << adj[i][j] << " ";
	    	// }
	    	// cout << " = ";
	    	cout << ans[i] << " ";
	    }
	    cout << '\n';
    }
}