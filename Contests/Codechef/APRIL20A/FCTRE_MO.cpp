#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int mxm = 1e5+10; // maximum number of queries and the number of nodes
const int mod = 1e9 + 7;
vector <int> adj[mxm], vis(mxm), par(mxm), depth(mxm), cost(mxm);
vector <unordered_map<int,int>> store(mxm); // stores all the prime factors of the cost
const int mxN = 1e6+10; // used for generating the seive upto 1e6
vector <int> fact(mxN); // seive ()
int timer;// used for timer dfs
vector <int> tin(mxm), tout(mxm), VIS(mxm), block(2*mxm), ID(2*mxm),ANS(mxm);
// vector <int> primes;
unordered_map <ll,ll> magic;

const int maxLog = ceil(log2(mxm));

int LCA[mxm][maxLog+1];

int mn;

struct query{
    int id, l, r, lc;
    bool operator < (const query& rhs){
        return (block[l] == block[rhs.l]) ? (r < rhs.r) : (block[l] < block[rhs.l]);
    }
}Q[mxm];



// used for calculating the prime factors in logN time
void seive() {
	for(int i=1;i<=mxN;i++) {
		fact[i] = -1;
	}
	for(int i=2;i<=mxN;i++) {
		if(fact[i] == -1) {
			// primes.pb(i);
			for(int j=i;j<=mxN;j+=i) {
				if(fact[j] == -1) {
					fact[j] = i;
				}
			}
		}
	}
}



void dfs(int node, int d, int parent) {
    tin[node] = ++timer;
    ID[timer] = node;
	vis[node] = 1;
	depth[node] = d;
    LCA[node][0] = parent;
	for(int child: adj[node]) {
		if(vis[child] == 0) {
			par[child] = node;
			dfs(child,d+1,node);
		}
	}
    tout[node] = ++timer;
    ID[timer] = node;
}

void countD(int num) {
	while(num != 1) {
    	magic[fact[num]]++;
    	num = num / fact[num];
    }
}

void preprocess(int n) {
    dfs(1,0,-1);

    for(int i=1;i<=mn;i++) {
        for(int j=1;j<=n;j++) {
            if(LCA[j][i-1] != -1) {
                int par = LCA[j][i-1];
                LCA[j][i] = LCA[par][i-1];
            }
        }
    }

}

int getLCA(int a, int b, int n) {
    
    if(depth[b] < depth[a]) swap(a, b);
    int d = depth[b] - depth[a];
    while(d > 0) {
        int i = log2(d);
        b = LCA[b][i];

        d-=1<<i;
    }

    if(a == b) return a;
    for(int i=mn;i>=0;i--) {
        if(LCA[a][i] != -1 and (LCA[a][i] != LCA[b][i])){
            a = LCA[a][i];
            b = LCA[b][i];
        }
    }

    return LCA[a][0];
}


void check(int x){
    // If (x) occurs twice, then don't consider it's value 
    if ( (VIS[x]) ) {
        for(auto u: store[x]) {
            int id = u.first;
            int val = u.second;
            magic[id]-=val;
        }
    }
    else if ( (!VIS[x])  ) {
        for(auto u: store[x]) {
            int id = u.first;
            int val = u.second;
            magic[id]+=val;
        }
    }
    VIS[x] ^= 1;
}

void compute(int q){
 
    // Perform standard Mo's Algorithm
    int curL = Q[0].l, curR = Q[0].l - 1, res = 0;

    for (int i = 0; i < q; i++){
        ll ans = 1;
 
        while (curL < Q[i].l) check(ID[curL++]);
        while (curL > Q[i].l) check(ID[--curL]);
        while (curR < Q[i].r) check(ID[++curR]);
        while (curR > Q[i].r) check(ID[curR--]);
 
        int u = ID[curL], v = ID[curR];
 
        // Case 2
        if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc);

        // calculate answer
        for(auto u: magic) {
            ans = (ans * (u.second + 1)) % mod;
        }
 
        ANS[Q[i].id] = ans;
 
        if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc);
    }
 
    for (int i = 0; i < q; i++) 
        cout << ANS[i] << '\n';
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
        magic.clear();
    	int n;
    	cin >> n;
        mn = ceil(log2(n));

    	for(int i=1;i<=n;i++) {
    		adj[i].clear();
            store[i].clear();
    		vis[i] = 0;
    		par[i] = i;
    		depth[i] = 0;
            tin[i] = 0;
            tout[i] = 0;
            VIS[i] = 0;
            for(int j=0;j<=mn;j++) {
                LCA[i][j] = -1;
            }
    	}
        for(int i=1;i<=2*n+10;i++) {
            block[i] = 0;
            ID[i] = 0;
        }
    	for(int i=0;i<n-1;i++) {
    		int a,b;
    		cin >> a >> b;
    		adj[b].pb(a);
    		adj[a].pb(b);
    	}
    	for(int i=1;i<=n;i++) {
            int val;
    		cin >> val;
            cost[i] = val;
            while(val!=1) {
                store[i][fact[val]]++;
                val/=fact[val];
            }
    	}
    	// do all the precompute: depth and parent
        preprocess(n);
    	// dfs(1,0);
    	// for(int i=1;i<=n;i++) {
    	// 	cout << i << " " << par[i] << " " << depth[i] << " " << cost[i] << '\n';
    	// }
        // for(int i=1;i<=n;i++) {
        //     cout << "i = " << i << '\n';
        //     cout << "par[i] = " << par[i] << '\n';
        //     cout << "depth[i] = " << depth[i] << '\n';
        //     cout << "cost[i] = " << cost[i] << '\n';
        //     cout << "factors of cost are: " << '\n';
        //     for(auto u: store[i]) {
        //         cout << u.first << " -> " << u.second << '\n';
        //     }
        // }

        
    	int q;
    	cin >> q;
    	int size = sqrtl(timer);
        for (int i = 1; i <= timer; i++) 
            block[i] = (i - 1) / size + 1;

        int u,v;
        for (int i = 0; i < q; i++){
            cin >> u >> v;
            Q[i].lc = getLCA(u,v,n);
            if (tin[u] > tin[v]) swap(u, v);
            if (Q[i].lc == u) Q[i].l = tin[u], Q[i].r = tin[v];
            else Q[i].l = tout[u], Q[i].r = tin[v];
            Q[i].id = i;
        }
 
        sort(Q, Q + q);
        compute(q);
    }
}