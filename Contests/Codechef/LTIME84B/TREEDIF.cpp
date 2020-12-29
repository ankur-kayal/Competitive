#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

const int mxN = 2e5 + 10;
vector <int> adj[mxN];

int vis[mxN], par[mxN], depth[mxN], arr[mxN];
vector <int> ans;

void dfs(int node, int d) {
	vis[node] = 1;
	depth[node] = d;
	for(int child: adj[node]) {
		if(vis[child] == 0) {
			par[child] = node;
			dfs(child,d+1);
		}
	}
}

int calculate(int a, int b) {
	ans.clear();
	ans.pb(b);
	int d = depth[b] - depth[a];
	bool ok = 1;
	while(d > 0) {
		// cout << ans << " ";
		b = par[b];
		ans.pb(b);
		// ans = ans*cost[b];
		d--;
	}
	// cout << '\n';
	// cout << a << " " << b << '\n';
	if(a == b)  {
		ok = 0;
	}
	if(ok) {
	    ans.pb(a);
// 		countD(cost[a]);
		while(par[a] != par[b]) {
			// ans = ans * cost[a];
			a = par[a];
			ans.pb(a);
// 			countD(cost[a]);
			// ans = ans * cost[b];
			b = par[b];
			ans.pb(b);
// 			countD(cost[b]);
		}
		ans.pb(par[a]);
// 		countD(cost[par[a]]);
	}
	// for(auto u: ans) {
	// 	cout << u << " ";
	// }
	// cout << '\n';
	// return 0;
	// ans = ans * cost[a];
	
	// return ans * cost[par[a]];
	// ll ans = 1;
	int tot = 10000;
	for(int i=0;i<ans.size();i++) {
	    for(int j=0;j<ans.size();j++) {
	    	if(i != j)
	        tot = min(tot,abs(arr[ans[i]] - arr[ans[j]]));
	    }
	}
	return tot;
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
        int n,q;
        cin >> n >> q;
        for(int i=1;i<=n;i++) {
            adj[i].clear();
            vis[i] = 0;
            par[i] = i;
            depth[i] = 0;
        }
        for(int i=1;i<=n;i++) {
            cin >> arr[i];
        }
        for(int i=1;i<n;i++) {
            int a,b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(1,0);
        // int q;
        // cin >> q;
        while(q--) {
            int a,b;
            cin >> a >> b;
            if(depth[a] > depth[b]) {
            	swap(a,b);
            }
            cout  << calculate(a,b) << '\n';
        }
    }
}