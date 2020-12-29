#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array

const int mxM = 1e5 + 10;

const int maxN = 20;

vector <int> adj[mxM];

int val[100001] , tree[200002] , S[100001] , T[100001] , nodeF[100001] , eleF[1000001];
int LCA[100001][maxN] , level[100001] , ans[100001];

int timer;

void dfs(int node ,int par , int lvl)
{
	level[node] = lvl;
	LCA[node][0] = par;
	tree[timer] = node;
	S[node] = timer++;
	
	for(int child : adj[node])
	if(child != par)
	dfs(child , node , lvl+1);
	
	tree[timer] = node;
	T[node] = timer++;
}

void initLCA(int n)
{
	for(int j=1;j<maxN;j++)
	{
		for(int i=1;i<=n;i++)
		if(LCA[i][j-1] != -1)
		{
			LCA[i][j] = LCA[LCA[i][j-1]][j-1];
		}
	}
}

int getLCA(int b, int d)
{
	if(level[b] < d) {
		// cout << level[b] << " " << d << '\n';
		return -1;
	}
	int f = 0;
	while(d)
	{
		if(d & 1)
		b = LCA[b][f];
		
		d >>= 1;
		f++;
	}
	
	return b;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    int n,q;
    cin >> n >> q;
    for(int i=0;i<n-1;i++) {
    	int a,b;
    	cin >> a >> b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }
    dfs(1 , -1 , 0);
    initLCA(n);
    while(q--) {
    	// cout << "q " << q << '\n';
    	int u,d;
    	cin >> u >> d;
    	cout << getLCA(u,d) << '\n';
    }

}