#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    int Q;
    cin >> Q;

    const int THRESHOLD = int(sqrt(Q));

    int maxA = 0;
    vector<pair<int,int>> pairs;
    for(int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        pairs.emplace_back(x, y);
        maxA = max({maxA, x, y});
    }

    vector<int> cnt(maxA + 1);
    vector<vector<int>> adj(maxA + 1);
    vector<vector<int>> adjBig(maxA + 1);
    for(auto [x, y] : pairs) {
        cnt[y]++;
        adj[y].push_back(x);
    }

    vector<int> dpBig(maxA + 1);
    for(int i = 1; i <= maxA; i++) {
        if(cnt[i] > THRESHOLD) {
            dpBig[i] = 1;
        }
    }

    for(auto [x, y] : pairs) {
        if(cnt[y] > THRESHOLD) {
            adjBig[x].push_back(y);
        }
    }

    vector<int> dp(N);
    vector<int> last(N);
    vector<int> recent(maxA + 1, -1);

    for(int i = 0; i < N; i++) {
        dp[i] = 1;
        if(cnt[A[i]] <= THRESHOLD) {
            last[i] = i;
            for(auto u: adj[A[i]]) {
                if(recent[u] == -1) {
                    continue;
                }
                if(dp[i] < dp[recent[u]] + 1) {
                    dp[i] = dp[recent[u]] + 1;
                    last[i] = recent[u];
                }
            }
        } else {
            dp[i] = dpBig[A[i]];
        }


        recent[A[i]] = i;

        for(auto u: adjBig[A[i]]) {
            if(dpBig[i] < dp[i] + 1) {
                
            }
        }
    }


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}