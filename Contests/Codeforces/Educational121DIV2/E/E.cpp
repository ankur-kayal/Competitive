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
    int N;
    cin >> N;

    vector<int> C(N);
    for(auto &u: C) {
        cin >> u;
    }

    vector<vector<int>> adj(N);
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> subtree(N);
    vector<int> parent(N, -1);

    function<void(int,int)> dfs = [&](int node, int par) -> void {
        subtree[node] = C[node];
        for(int child: adj[node]) {
            if(child != par) {
                parent[child] = node;
                dfs(child, node);
                subtree[node] += subtree[child];
            }
        }
    };

    dfs(0, -1);

    vector<vector<int>> modified_directed_tree(N);
    for(int i = 0; i < N; i++) {
        for(int neighbour: adj[i]) {
            if(i == parent[neighbour]) {
                if(C[i] == 1 || subtree[0] - subtree[neighbour] >= 2) {
                    modified_directed_tree[i].push_back(neighbour);
                }
            } else {
                if(C[i] == 1 || subtree[i] > 1) {
                    modified_directed_tree[i].push_back(neighbour);
                }
            }
        }
    }

    vector<int> q;
    vector<int> vis = C;
    for(int i = 0; i < N; i++) {
        if(vis[i]) {
            q.push_back(i);
        }
    }

    for(int i = 0; i < q.size(); i++) {
        int x = q[i];
        for(int child: modified_directed_tree[x]) {
            if(!vis[child]) {
                vis[child] = 1;
                q.push_back(child);
            }
        }
    }

    output_vector(vis);
} 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}