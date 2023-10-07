#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    string C;
    cin >> C;

    vector<vector<int>> edges(N - 1), adj(N);
    vector<int> value(N);

    bool ok = true;

    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;

        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(C[u] == 'B' && C[v] == 'B') {
            ok = false;
        }

        if(C[u] == 'B' && C[v] != 'B') {
            value[v]++;
        }
        if(C[v] == 'B' && C[u] != 'B') {
            value[u]++;
        }
    }

    if(!ok) {
        cout << "NO" << '\n';
        return;
    }

    char target = '#';
    vector<int> components;
    vector<bool> processed(N);

    function<void(int)> dfs = [&](int node) -> void {
        processed[node] = true;
        if(C[node] != target) {
            return;
        }
        components.push_back(node);
        for(int child: adj[node]) {
            if(!processed[child]) {
                dfs(child);
            }
        }
    };

    target = 'R';
    for(int i = 0; i < N; i++) {
        if(!processed[i]) {
            components.clear();
            dfs(i);
            int64_t sum = 0;
            for(auto u: components) {
                sum += value[u];
            }
            if(sum > 1) {
                cout << "NO\n";
                return;
            }
        }
    }

    target = 'G';
    processed = vector<bool>(N);
    for(int i = 0; i < N; i++) {
        if(!processed[i]) {
            components.clear();
            dfs(i);
            int64_t sum = 0;
            for(auto u: components) {
                sum += value[u];
            }
            if(sum > 1) {
                cout << "NO\n";
                return;
            }
        }
    }


    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}