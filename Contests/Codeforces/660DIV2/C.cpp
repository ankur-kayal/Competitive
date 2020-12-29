#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

const int mxN = 2e5 + 10;
int n,m;

vector <int> adj[mxN];
vector <int> p(mxN,0);
vector <int> h(mxN,0);
vector <int> dp(mxN,0);
vector <int> parent(mxN,0);
vector <bool> visited(mxN);
void dfs(int u){
   for(int v:adj[u]){
       if(visited[v]==false){
           visited[v]=true;
           parent[v]=u;
           dfs(v);
           p[u]+=p[v];
       }
   } 
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        adj[i].clear();
        visited[i]=false;
        parent[i]=0;
        cin>>p[i];
    }
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited[1]=true;
    dfs(1);
    int check=1;
    for(int i=2;i<=n;i++){
        dp[parent[i]]+=(h[i]+p[i]) / 2;
    }
    for(int i=1;i<=n;i++){
        if((h[i]+p[i])%2!=0 or h[i]+p[i]<0 or p[i]-h[i]<0)
            check=0;
        if((h[i]+p[i])/2 < dp[i])
            check=0;
    }
 	cout << (check ? "YES" : "NO") << '\n';
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
    	solve();
	}
}