#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

struct DSU {
    vector<int> parent, nodes;
    int N;

    DSU(int _n = 0) {
        N = _n;
        parent.resize(N, 0);
        iota(parent.begin(), parent.end(), 0);
        nodes.assign(N, 1);
    }

    int find(int node) {
        return parent[node] == node ? node : parent[node] = find(parent[node]);
    }

    int find_size(int a) {
        return nodes[find(a)];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if(nodes[a] > nodes[b]) {
            swap(a, b);
        }
        parent[a] = b;
        nodes[b] += nodes[a];
    }
};

void run_cases() {
    int N;
    cin >> N;
    vector<array<int64_t, 3>> edges;
    DSU dsu(N);
    for(int i = 0; i < N - 1; i++) {
        int64_t u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    int64_t ans = 0;
    
    for(auto [weight, u, v] : edges) {
        int64_t left = dsu.find_size(u);
        int right = dsu.find_size(v);
        ans += weight * left * right;
        dsu.unite(u, v);
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}