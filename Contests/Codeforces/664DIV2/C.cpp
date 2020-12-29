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

    int n,m;
    cin >> n >> m;
    int a[n],b[m];
    for(int i=0;i<n;i++) {
    	cin >> a[i];
    }
    for(int i=0;i<m;i++) {
    	cin >> b[i];
    }
    set <int> available;
    int ans = 0;
    for(int i=0;i<n;i++) {
    	int mv=1000000000;
    	for(int j=0;j<m;j++) {
    		int ele = a[i] & b[j];
    		// if(available.find(ele) != available.end()) {
    		// 	mv = ele;
    		// 	break;
    		// }
    		mv = min(mv,a[i] & b[j]);
    		cout << ele << " ";
    	}
    	// cout << mv << '\n';
    	cout << '\n';
    	ans = ans | mv;
    	available.insert(mv);
    }
    cout << ans << '\n';
}