#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void run_cases() {
    int64_t N;
    cin >> N;
    vector<vector<int>> adj(N);
    vector<int64_t> subtree(N, 1);
    vector<bool> vis(N, false);
    vector<int> parent(N);

    for(int i=1;i<N;i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parent[0] = -1;

    function<void(int,int)> dfs = [&](int node, int par) -> void {
        for(int child: adj[node]) {
            if(child != par) {
                parent[child] = node;
                dfs(child, node);
                subtree[node] += subtree[child];
            }
        }
    };

    dfs(0, -1);

    vis[0] = 1;


    vector<int64_t> ans(N + 1, 0);

    for(int child: adj[0]) {
        ans[0] += subtree[child] * (subtree[child] - 1) / 2;
    }
    int64_t P = N * (N - 1) / 2 - ans[0];

    int l = 0, r = 0;

    for(int i=1;i<=N;i++) {
        if(P == 0 || i == N) {
            ans[i] = P;
            continue;
        }
        if(vis[i] && i != l && i != r) {
            ans[i] = 0;
            continue;
        }
        int u = i;
        while(!vis[u]) {
            vis[u] = 1;
            if(vis[parent[u]]) {
                subtree[parent[u]] -= subtree[u];
            }
            u = parent[u];
        }

        if(u == l || u == r) {
            if(u == l) {
                l = i;
            } else {
                r = i;
            }

            ans[i] = P - subtree[l] * subtree[r];
            P = subtree[l] * subtree[r];
        } else {
            ans[i] = P;
            P = 0;
        }
    }

    output_vector(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}