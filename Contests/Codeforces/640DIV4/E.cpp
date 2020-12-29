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
    	int a[n];
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    	}
    	int ans = 0;
    	for(int i=0;i<n;i++) {
    		int ele = a[i];
    		int sum = 0;
    		int p1 = 0;
    		int p2 = 0;
    		int cnt = 0;
    		bool exists = false;
    		while(sum != ele and p1 < n and p2 < n) {
    			while(sum < ele and p1 < n) {
    				if(p1 == i) {
    					p1+=1;
    					p2 = p1;
    					sum = 0;
    				}
    				if(p1 >= n) break;
    				sum+=a[p1];
    				cnt++;
    				p1++;
    			}
    			while(sum > ele and p2 < n) {
    				sum-=a[p2];
    				cnt--;
    				p2++;
    			}
    			if(sum == ele) {
    				exists = true;
    				break;
    			}
    			// cout << sum << " " << ele << '\n';
    		}
    		if(exists and cnt > 1) {
    			// cout  << ele << '\n';
    			ans++;
    		}
    	}
    	cout << ans << '\n';
    }
}