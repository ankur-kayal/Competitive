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
    	int n;
    	cin >> n;
    	int arr[n];
    	for(int i=0;i<n;i++) {
    		cin >> arr[i];
    	}
    	map <int,int> count;
    	bool ok = 1;
    	for(int i=0;i<n;i++) {
    		int ele = arr[i];
    		int change = ele - 5;
    		if(change > 0) {
    			if(count[change] > 0) {
    				count[change]--;
    			}
    			else if(count[change/2] > 1) {
    				count[change/2]-=2;
    			}
    			else {
    				ok = 0;
    				break;
    			}
    		}
    		count[ele]++; 
    	}
    	cout << (ok ? "YES" : "NO") << '\n';
    }
}