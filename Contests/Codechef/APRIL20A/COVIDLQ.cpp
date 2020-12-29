#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

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
    	int prev = -10;
    	bool ok = 1;
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    	}
    	for(int i=0;i<n;i++) {
    		if(a[i] == 1) {
    			if(i - prev < 6) {
    				ok = 0;
    				break;
    			}
    			prev = i;
    		}
    	}
    	cout << (ok ? "YES" : "NO") << '\n';
    }
}