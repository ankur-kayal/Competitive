#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> adj(N);
    vector<int> degree(N);

    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    queue<int> leafs;

    for(int i = 0; i < N; i++) {
        if(degree[i] == 1 || degree[i] == 0) {
            leafs.push(i);
        }
    }

    vector<int> removed(N);

    while(!leafs.empty() && K > 0) {
        int sz = leafs.size();
        for(int i = 0; i < sz; i++) {
            int node = leafs.front();
            removed[node] = 1;
            leafs.pop();
            for(auto u: adj[node]) {
                degree[u]--;
                if(degree[u] == 1 || degree[u] == 0) {
                    if(!removed[u])
                        leafs.push(u);
                }
            }
        }
        K--;
    }


    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(!removed[i]) {
            ans++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}