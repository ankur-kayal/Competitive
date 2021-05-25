#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    vector<pair<int,int>> ranges(N);
    for(int i=0;i<N;i++) {
        cin >> ranges[i].first >> ranges[i].second;
    }
    for(int i=1;i<N;i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<array<int64_t, 2>> dp(N);

    int64_t res = 0, ans = 0;

    function<void(int,int)> dfs = [&](int node, int par) -> void {
        if(adj[node].size() == 1 && node != 0) {
            return;
        }

        for(int child: adj[node]) {
            if(child != par) {
                dfs(child, node);
                dp[node][0] += max(dp[child][0] + abs(ranges[node].first - ranges[child].first), dp[child][1] + abs(ranges[node].first - ranges[child].second));
                dp[node][1] += max(dp[child][0] + abs(ranges[node].second - ranges[child].first), dp[child][1] + abs(ranges[node].second - ranges[child].second));
            }

        }
    };

    dfs(0, -1);

    cout << max(dp[0][0], dp[0][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}