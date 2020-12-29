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
    	int a[n];
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    	}
    	sort(a,a+n);
    	bool exists = true;
    	for(int i=0;i<n-1;i++) {
    		if(abs(a[i] - a[i+1]) > 1) {
    			exists = false;
    			break;
    		}
    	}
    	cout << (exists ? "YES" : "NO") << '\n';
    }
}	