#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

const int mxN = 1e6 + 10;

vector <int> adj[mxN];

int vis[mxN], par[mxN], height[mxN], b[mxN], countForRoot[mxN];

vector <unordered_map<int,int>> countForBranch(mxN);

int branch;

void dfs(int node, int d) {
	vis[node] = 1;
	height[node] = d;
	if(b[par[node]] == 0) {
		// cout << "hola = " << node << " " << par[node]  << " " << b[par[node]] << '\n';
		++branch;
		b[node] = branch;
	}
	else {
		b[node] = b[par[node]];
	}
	countForRoot[d]++;
	countForBranch[b[node]][d]++;
	for(auto u: adj[node]) {
		if(vis[u] == 0) {
			par[u] = node;
			dfs(u, d+1);
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
    	int n,q,u,v;
    	cin >> n >> q;
    	for(int i=1;i<=n;i++) {
    		height[i] = 0;
    		vis[i] = 0;
    		par[i] = 0;
    		b[i] = 0;
    	}
    	for(int i=1;i<n;i++) {
    		cin >> u >> v;
    		adj[u].pb(v);
    		adj[v].pb(u);
    	}
    	// d = 0;
    	branch = -1;
    	par[1] = 1;
    	b[1] = 0;
    	dfs(1, 0);
    	for(int i=1;i<n;i++) {
    		cout << i << " " << height[i] << " " << vis[i] << " " << par[i] << " " << b[i] << '\n';
    	}
    	for(int i=0;i<n;i++) {
    		cout << countForRoot[i] << '\n';
    	}
    	cout << "branch = " << branch << '\n';
    	for(int i=1;i<=branch;i++) {
    		for(int j=0;j<=10;j++) {
    			cout << countForBranch[i][j] << " ";
    		}
    		cout << '\n';
    	}
    	while(q--) {
    		int type, node, node1, node2, dist;
    		cin >> type;
    		if(type == 1) {
    			int ans = 0;
    			cin >> node >> dist;
    			if(node != 1) {
    				// calculating the remaining height left 
	    			int remainingHeight = dist - height[node];
	    			// if(remainingHeight == height[node]) {
	    			// 	ans--;
	    			// }
	    			if(remainingHeight >= 0) {
	    				// adding the count of all nodes at a distance dist from the root for all branches from the root
	    				ans += countForRoot[remainingHeight];
	    				// subtracting the count of all nodes at a distance dist from the root for the branch b[node]
	    				ans -= countForBranch[b[node]][remainingHeight];
	    				cout << ans << '\n';
	    			}
	    			// now adding the nodes that are at a distance dist below the node
	    			ans += countForBranch[b[node]][dist + height[node]];
	    			if(remainingHeight < 0) {
	    				ans+=countForBranch[b[node]][abs(remainingHeight)];
	    			}
    			}
    			else {
    				ans = countForRoot[dist];
    			}
    			if(ans > 0) {
    				cout << ans << '\n';
    			}   
    			else {
    				cout << -1 << '\n';
    			}			
    		}
    		else if(type == 2) {
    			cin >> node1 >> node2;
    			if(vis[node1] == 1) {
    				height[node2] = height[node1] + 1;
    				b[node2] = b[node1];
    				countForRoot[height[node2]]++;
    				countForBranch[b[node2]][height[node2]]++;
    			}
    			else if(vis[node2] == 1) {
    				height[node1] = height[node2] + 1;
    				b[node1] = b[node2];
    				countForRoot[height[node1]]++;
    				countForBranch[b[node1]][height[node1]]++;
    			}
    		}
    	}
    }
}