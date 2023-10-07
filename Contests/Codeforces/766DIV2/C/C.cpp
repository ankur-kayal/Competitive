#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<array<int, 2>> edges;
    vector<vector<int>> adj(N);

    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 0;

    map<array<int, 2>, int> value;
    vector<int> children(N);

    function<void(int,int,int)> dfs = [&](int node, int par, int v) -> void {
        for(int child: adj[node]) {
            if(child != par) {
                value[{child, node}] = v;
                value[{node, child}] = v;
                children[node]++;
                if(v == 2) {
                    v = 5;
                } else {
                    v = 2;
                }
                dfs(child, node, v);
            }
        }
    };

    dfs(0, -1, 5);

    for(int i = 0; i < N; i++) {
        if(i == root) {
            if(children[i] > 2) {
                cout << -1 << '\n';
                return;
            }
        }
        else {
            if(children[i] > 1) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    for(auto u: edges) {
        cout << value[u] << " ";
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}