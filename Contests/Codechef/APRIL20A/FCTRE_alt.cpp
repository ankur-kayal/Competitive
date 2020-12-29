#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int mxm = 1e5+10;
vector <int> adj[mxm], vis(mxm), par(mxm), depth(mxm), cost(mxm);
vector <unordered_map<int,int>> store(mxm);
const int mxN = 1e6+10;
vector <int> fact(mxN);
vector <int> primes;
unordered_map <ll,ll> magic;

const int maxLog = ceil(log2(mxm));

int LCA[mxm][maxLog+1];



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

void dfs(int node, int d, int parent) {
    vis[node] = 1;
    depth[node] = d;
    LCA[node][0] = parent;
    for(int child: adj[node]) {
        if(vis[child] == 0) {
            par[child] = node;
            for(auto u: store[node]) {
                int id = u.first;
                int val = u.second;
                store[child][id]+=val;
            }
            dfs(child,d+1,node);
        }
    }
}

void countD(int num) {
    while(num != 1) {
        magic[fact[num]]++;
        num = num / fact[num];
    }
}

void preprocess(int n) {
    dfs(1,0,-1);

    int mn = ceil(log2(n));
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
    int mn = ceil(log2(n));
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

ll evaluate(int a, int b, int n) {
    ll ans = 1;
    magic.clear();
    for(auto u: store[a]) {
        int id = u.first;
        int val = u.second;
        magic[id]+=val;
    }
    for(auto u: store[b]) {
        int id = u.first;
        int val = u.second;
        magic[id]+=val;
    }

    int lc = getLCA(a,b,n);
    for(auto u: store[lc]) {
        int id = u.first;
        int val = u.second;
        magic[id]-=2*val;
    }
    countD(cost[lc]);
    for(auto u: magic) {
        ans = (ans * (u.second + 1)) % mod;
        // cout << u.first << " " << u.second << " HI " << ans << '\n';
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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

        int nl = ceil(log2(n));

        for(int i=1;i<=n;i++) {
            adj[i].clear();
            store[i].clear();
            vis[i] = 0;
            par[i] = i;
            depth[i] = 0;
            for(int j=0;j<=nl;j++) {
                LCA[i][j] = -1;
            }
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
        //  cout << i << " " << par[i] << " " << depth[i] << " " << cost[i] << '\n';
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
        // map <pair<int,int>,ll> stored;
        while(q--) {
            int u,v;
            cin >> u >> v;
            cout << evaluate(u,v,n) << '\n';
            /*if(depth[u] > depth[v]) {
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
            }*/
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