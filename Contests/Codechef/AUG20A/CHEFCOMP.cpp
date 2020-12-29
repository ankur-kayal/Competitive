#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second


const int mxN = 2e5+10;

set <int> adj[mxN];

vector <int> vis(mxN), p(mxN), a(mxN), b(mxN), ans(mxN), used;

void update(int node, int val, int day) {
	vis[node] = 1;
	for(auto u: adj[node]) {
		if(vis[u] == 0) {
			used.pb(u);
			if(b[u] > 0) {
				b[u] = b[u] - min(b[u],val);
				if(b[u] == 0) {
					ans[u] = day;
				}
			}
			
			update(u, val, day);
		}
	}
}

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
    	for(int i=1;i<=n;i++) {
    		vis[i] = 0;
    		adj[i].clear();
    		p[i] = 0;
    		a[i] = 0;
    		b[i] = 0;
    		ans[i] = 0;
    	}
    	for(int i=1;i<=n-1;i++) {
    		int u,v;
    		cin >> u >> v;
    		adj[u].insert(v);
    		adj[v].insert(u);
    	}
    	for(int i=1;i<=n;i++) {
    		cin >> p[i];
    	}
    	for(int i=1;i<=n;i++) {
    		cin >> a[i];
    	}
    	for(int i=1;i<=n;i++) {
    		cin >> b[i];
    	}
    	for(int i=1;i<=n;i++) {
    		int city = p[i];
    		if(b[city] != 0) {
    			if(a[city] >= b[city]) {
	    			ans[city] = i;
	    			b[city] = 0;
	    		}
	    		else {
	    			ans[city] = -1;
	    		}
    		}
    		update(city,a[city],i);
    		used.pb(city);
    		for(auto u: used) {
    			vis[u] = 0;
    		}
    		used.clear();
    		for(auto u: adj[city]) {
    			adj[u].erase(city);
    		}
    		// for(int i=1;i<=n;i++) {
    		// 	cout << vis[i] << " ";
    		// }
    		// cout << '\n';
    	}
    	// for(int i=1;i<=n;i++) {
    	// 	cout << b[i] << " ";
    	// }
    	// cout << '\n';
    	for(int i=1;i<=n;i++) {
    		cout << ans[i] << " ";
    	}
    	cout << '\n';
    }
}	