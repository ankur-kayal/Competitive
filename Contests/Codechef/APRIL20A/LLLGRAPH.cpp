#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

struct edge {
	int a,b;
};

vector <int> adj[2001];

int adjM[2001][2001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
	#endif

    int n,m,k;
    cin >> n >> m >> k;
    assert(k == 1);
    edge arr[m];
    for(int i=0;i<m;i++) {
    	cin >> arr[i].a >> arr[i].b;
    }
    for(int i=0;i<m;i++) {
    	for(int j=i+1;j<m;j++) {
    		set <int> tmp = {arr[i].a,arr[i].b,arr[j].a,arr[j].b};
    		if(tmp.size() < 4) {
    			adj[i+1].pb(j+1);
    			adj[j+1].pb(i+1);
    		}
    	}
    }
    // for(int i=1;i<=m;i++) {
    // 	cout << i << " -> ";
    // 	for(auto u: adj[i]) {
    // 		cout << u << " ";
    // 	}
    // 	cout << '\n';
    // }

    // set <int> ans;
    // set <int,greater<int>> G;
    // for(int i=1;i<=m;i++) {
    // 	G.insert(i);
    // }
    // while(G.size() != 0) {
    // 	int u = *G.begin();
    // 	int deg = 4000;
    // 	for(auto node: G) {
    // 		if(adj[node].size() < deg) {
    // 			deg = adj[node].size();
    // 			u = node;
    // 		}
    // 	}
    // 	ans.insert(u);
    // 	for(auto v: adj[u]) {
    // 		G.erase(v);
    // 	}
    // 	G.erase(u);
    // }
    // cout << ans.size() << '\n';
    int ans = 0;
    for(int i=1;i<=m;i++) {
        ans = max(ans,m-(int)adj[i].size());
    }
    cout << ans << '\n';
}