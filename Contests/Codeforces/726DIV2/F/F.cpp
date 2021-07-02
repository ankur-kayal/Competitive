#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, M;
    cin >> N >> M;
    vector<int64_t> initial(N), target(N);

    for(auto &u: initial) {
        cin >> u;
    }

    for(auto &u: target) {
        cin >> u;
    }

    vector<vector<int>> adj(N);

    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int64_t parity1 = accumulate(initial.begin(), initial.end(), 0LL);
    int64_t parity2 = accumulate(target.begin(), target.end(), 0LL);

   int64_t parity = abs(parity2 - parity1);

    if(parity & 1) {
        cout << "NO\n";
        return;
    }

    // check if bipartite

    vector<int> color(N);
    bool bipartite = true;
    vector<bool> vis(N, false);

    function<void(int, int)> dfs = [&](int node, int c) -> void {
        color[node] = c;
        vis[node] = true;
        for(int child: adj[node]) {
            if(vis[child]) {
                if(color[child] == color[node]) {
                    bipartite = false;
                }
            }
            else {
                dfs(child, c ^ 1);
            }
        }
    };

    dfs(0, 0);

    if(!bipartite) {
        cout << "YES\n";
        return;
    }

    vector<int64_t> need(2);
    for(int i = 0; i < N; i++) {
        need[color[i]] += (target[i] - initial[i]);
    }

    cout << (need[0] == need[1] ? "YES" : "NO") << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}