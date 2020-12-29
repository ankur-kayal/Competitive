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
    	string p;
    	cin >> p;	
    	int d;
    	cin >> d;
    	vector <int> iso(d);
    	for(int i=0;i<d;i++) {
    		cin >> iso[i];
    	}
    	// 1 for isolated, 2 for infected, 0 for neutral
    	vector <int> vis(n+1,0);
    	vector <int> left;
    	vector <int> right;
    	int ans = 0;
    	for(int i=1;i<=n;i++) {
    		if(p[i-1] == '1') {
    			left.pb(i);
    			right.pb(i);
	    		vis[i] = 2;
	    		++ans;
    		}
    	}
    	int l = ans;
    	for(int i=0;i<d;i++) {
    		// for(auto u: right) {
    		// 	cout << u << " ";
    		// }
    		// cout << '\n';
    		// for(auto u: left) {
    		// 	cout << u << " ";
    		// }
    		// cout << '\n';
    		int ele = iso[i];
    		vis[ele] = 1;
    		for(int j=0;j<l;j++) {
    			if(left[j] == 1 or vis[left[j]] == 1) {
    				continue;
    			}
    			--left[j];
    			if(vis[left[j]] != 2) {
    				if(vis[left[j]] != 1)
    				vis[left[j]] = 2;
    				ans++;
    				// cout << left[j] << '\n';
    			}
    		}
    		for(int j=0;j<l;j++) {
    			if(right[j] == n or vis[min(n,right[j] + 1)] == 1) {
    				continue;
    			}
    			++right[j];
    			if(vis[right[j]] == 0) {
    				if(vis[right[j]] != 1)
    				vis[right[j]] = 2;
    				ans++;
    				// cout << right[j] << '\n';
    			}
    		}
    		// for(auto u: vis) {
    		// 	cout << u << " ";
    		// }
    		// cout << ans ;
    		// cout << '\n';
    		

    	}
    	cout <<  ans << '\n';
    }

}