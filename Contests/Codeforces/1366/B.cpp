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
    	int n,x,m;
    	cin >> n >> x >> m;
    	int small = x;
    	int large = x;
    	bool ok = 0;
    	for(int i=0;i<m;i++) {
    		int l,r;
    		cin >> l >> r;
    		if(max(l,small) <= min(large,r)) {
    			small = min(small,l);
    			large = max(large,r);
    		}
    		
    	}
    	// cout << small << " " << large << '\n';
    	cout << (large - small + 1) << '\n';
    }
}