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
    	vector <int> a(n);
    	for(int i=0;i<n;i++) {
    		int tmp;
    		cin >> tmp;
    		a[i] = abs(tmp);
    	}
    	ll ans = 0;
    	int prev = -1;
    	int even = -1;
    	for(int i=0;i<n;i++) {
    		if(a[i] % 4 == 0) {
    			ans = ans + i + 1;
    			even = i;
    		}
    		else if(a[i] % 2 == 0) {
    			even = max(even,prev);
    			ans = ans + even + 1;
    			prev = i;
    		}
    		else if(a[i] % 2 == 1) {
    			if(even >= prev) {
    				ans = ans + i + 1;
    			}
    			else {
    				ans = ans + (i - (prev + 1) + 1);
    				ans = ans + even + 1;
    			}
    		}
    		// cout << ans << '\n';
    	}
    	cout << ans << '\n';
    }
}