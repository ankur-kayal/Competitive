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

vector <int> vis(mxN), p(mxN), a(mxN), b(mxN), ans(mxN), par(mxN), lazy[mxN];

void dfs(int node) {
	vis[node] = 1;
	for(auto u: adj[node]) {
		if(vis[u] == 0) {
			par[u] = node;
			dfs(u);
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

    	// taking all inputs
    	int n;
    	cin >> n;
    	for(int i=1;i<=n;i++) {
    		vis[i] = 0;
    		adj[i].clear();
    		p[i] = 0;
    		a[i] = 0;
    		b[i] = 0;
    		ans[i] = 0;
    		par[i] = i;
    		lazy[i].clear();
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

    	// precomputing the direct parents of each city
    	par[1] = 1;
    	dfs(1);

    	// printing the answer
    	for(int i=1;i<=n;i++) {
    		cout << ans[i] << " ";
    	}
    	cout << '\n';
    }
}	