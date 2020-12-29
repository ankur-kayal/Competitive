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
    	map <int,int> count;
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    		count[a[i]]++;
    	}
    	int ans = 0;
    	for(int s=1;s<=100;s++) {
    		// cout << s << '\n';
    		int tans = 0;
    		count.clear();
    		for(int i=0;i<n;i++) {
    			count[a[i]]++;
    		}
    		for(int i=0;i<n;i++) {
    			// cout << a[i] << " " << s-a[i] << " " << count[a[i]] << " " << count[s-a[i]] << '\n';
    			if(count[a[i]] > 0 and s - a[i] != a[i]  and count[s - a[i]] > 0) {
    				tans++;
    				count[a[i]]--;
    				count[s-a[i]]--;
    			}
    			else if(count[a[i]] > 0 and s - a[i] == a[i] and count[s-a[i]] > 1) {
    				tans++;
    				count[a[i]]--;
    				count[s-a[i]]--;
    			}
    		}
    		ans = max(ans,tans);
    		// cout << tans << '\n';
    	}	
    	cout << ans << '\n';
    }
}