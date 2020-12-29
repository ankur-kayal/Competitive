#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

const int mxN = 1e6 + 10;

vector <int> adj[mxN], vis(mxN);

int polygon;

void dfs(int node) {
	vis[node] = 1;
	for(auto child: adj[node]) {
		if(vis[child] == 0) {
			polygon++;
			dfs(child);
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
    	multiset <int> ans;
    	int n,k;
    	cin >> n >> k;
    	for(int i=1;i<=n;i++) {
    		adj[i].clear();
    		vis[i] = 0;
    	}
    	for(int i=1;i<=k;i++) {
    		int a,b;
    		cin >> a >> b;
    		++a,++b;
    		adj[a].pb(b);
    		adj[b].pb(a);
    	}
    	for(int i=1;i<=n;i++) {
    		polygon = 1;
    		if(vis[i] == 0) {
    			dfs(i);
    			ans.insert(polygon);
    		}

    	}
    	cout << ans.size() << '\n';
    	for(auto u: ans) {
    		cout << u << " ";
    	}
    	cout << '\n';
    }
}