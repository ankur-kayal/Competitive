#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

vector <int> adj[51];
int vis[51];
bool exists;

void init(int n) {
	for(int i=1;i<=n;i++) {
		adj[i].clear();
		vis[i] = 0;
	}
}

void dfs(int node, int target) {
	vis[node] = 1;
	for(auto u: adj[node]) {
		if(u == target) {
			exists = true;
		}
		if(!vis[u]) {
			dfs(u,target);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	init(n);
	string incoming, outgoing;
	cin >> incoming >> outgoing;
	// cout << incoming << " " << outgoing << '\n';
	char grid[n+1][n+1];
	for(int i=1;i<=n;i++) {
		if(incoming[i-1] == 'Y') {
			for(int j=1;j<=n;j++) {
				if(outgoing[j-1] == 'Y') {
					if(abs(i-j) == 1) {
						adj[j].pb(i);
					}
				}
			}
		}
		
	}
	// for(int i=1;i<=n;i++) {
	// 	cout << i << " : ";
	// 	for(auto u: adj[i]) {
	// 		cout << u << " ";
	// 	}
	// 	cout << '\n';
	// }
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			exists = false;
			for(int i=1;i<=n;i++) {
				vis[i] = 0;
			}
			dfs(i,j);
			if(exists) {
				grid[i][j] = 'Y';
			}
			else {
				grid[i][j] = 'N';
			}
		}
	}
	for(int i=1;i<=n;i++) {
		grid[i][i] = 'Y';
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			cout << grid[i][j];
		}
		cout << '\n';
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
    for(int i=1;i<=t;i++) {
    	cout << "Case #" << i << ":" << '\n';
    	solve();
    }
}