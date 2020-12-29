#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int mxm = 1e5+10;
vector <int> adj[mxm], vis(mxm), par(mxm), depth(mxm), cost(mxm);
const int mxN = 1e6+10;
vector <int> fact(mxN);
vector <int> primes;
unordered_map <ll,ll> magic;

void seive() {
	for(int i=1;i<=mxN;i++) {
		fact[i] = -1;
	}
	for(int i=2;i<=mxN;i++) {
		if(fact[i] == -1) {
			primes.pb(i);
			for(int j=i;j<=mxN;j+=i) {
				if(fact[j] == -1) {
					fact[j] = i;
				}
			}
		}
	}
}

const int mod = 1e9 + 7;

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

void countD(int num) {
	while(num != 1) {
    	magic[fact[num]]++;
    	num = num / fact[num];
    }
}

ll calculate(int a, int b) {
	magic.clear();
	countD(cost[b]);
	int d = depth[b] - depth[a];
	ll ans = 1;
	bool ok = 1;
	while(d > 0) {
		// cout << ans << " ";
		b = par[b];
		countD(cost[b]);
		// ans = ans*cost[b];
		d--;
	}
	// cout << '\n';
	// cout << a << " " << b << '\n';
	if(a == b)  {
		ok = 0;
	}
	if(ok) {
		countD(cost[a]);
		while(par[a] != par[b]) {
			// ans = ans * cost[a];
			a = par[a];
			countD(cost[a]);
			// ans = ans * cost[b];
			b = par[b];
			countD(cost[b]);
		}
		countD(cost[par[a]]);
	}
	// ans = ans * cost[a];
	
	// return ans * cost[par[a]];
	// ll ans = 1;
	for(auto u: magic) {
		ans = (ans * (u.second + 1)) % mod;
		// cout << u.first << " " << u.second << " HI " << ans << '\n';
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
	#endif
    seive();
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	for(int i=1;i<=n;i++) {
    		adj[i].clear();
    		vis[i] = 0;
    		par[i] = i;
    		depth[i] = 0;
    	}
    	for(int i=0;i<n-1;i++) {
    		int a,b;
    		cin >> a >> b;
    		adj[b].pb(a);
    		adj[a].pb(b);
    	}
    	for(int i=1;i<=n;i++) {
    		cin >> cost[i];
    	}
    	// do all the precompute: depth and parent
    	dfs(1,0);
    	// for(int i=1;i<=n;i++) {
    	// 	cout << i << " " << par[i] << " " << depth[i] << " " << cost[i] << '\n';
    	// }
    	int q;
    	cin >> q;
    	map <pair<int,int>,ll> stored;
    	while(q--) {
    		int u,v;
    		cin >> u >> v;
    		if(depth[u] > depth[v]) {
    			swap(u,v);
    		}
    		// cout << calculate(u,v) << " HI" << ' ';
    		if(stored[mp(u,v)] == 0) {
    			ll ptmp = calculate(u,v);
    			stored[mp(u,v)] = ptmp;
    			cout << ptmp << '\n';
    		}
    		else {
    			cout << stored[mp(u,v)] << "\n";
    		}
    	}
    }
    /**int num;
    cin >> num;
    unordered_map <int,int> freq;
    while(num != 1) {
    	freq[fact[num]]++;
    	num = num / fact[num];
    }
    cout << primes.size() << '\n';
    for(auto u: primes) {
    	if(freq[u] > 0) {
    		cout << u << "->" << freq[u] << '\n'; 
    	}
    }**/

}