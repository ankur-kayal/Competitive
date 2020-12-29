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
    	int col[n] ={0};
    	for(int i=0;i<n;i++) {
    		cin >> a[i];
    	}
    	vector <int> ch[12];
    	int m = 0;
    	for(int i=0;i<n;i++) {
    		if(col[i] == 0) {
    			++m;
    			col[i] = m;
    			ch[m].pb(a[i]);
    			for(int j=i+1;j<n;j++) {
    				bool ok = 1;
    				for(int u: ch[m]) {
    					if(__gcd(u,a[j]) > 1) {
    						// cout << u << " " << a[j] << " " <<__gcd(u,a[j]) <<  '\n';
    						// ch[m].pb(a[j]);
    						// col[j] = m;
    						continue;
    					}
    					else {
    						ok = 0;
    						break;
    					}
    				}
    				if(ok) {
    					ch[m].pb(a[j]);
    					col[j] = m;
    				}
    				// if(__gcd(a[i],a[j]) > 1) {
    				// 	// cout << a[i] << " " << a[j] << " " << __gcd(a[i],a[j]) << '\n';
    				// 	col[j] = m;
    				// }
    			}
    			// m++;
    		}
    	}
    	cout << m << '\n';
    	for(int i=0;i<n;i++) {
    		cout << col[i] << " ";
    	}
    	cout << '\n';
    }

}