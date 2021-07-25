#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    auto good = [&](int len) -> bool {

        vector<vector<int>> nxt(K, vector<int>(N + 1, N + 1));
        for(int i = 0; i < K; i++) {
            int last = N;
            for(int j = N - 1; j >= 0; j--) {
                if(S[j] != '?' && S[j] != 'a' + i) {
                    last = j;
                }
                nxt[i][j] = nxt[i][j + 1];
                if(last - j >= len) {
                    nxt[i][j] = j;
                }
            }
        }

        vector<int> dp(1 << K, N + 1);
        dp[0] = 0;
        for(int mask = 0; mask < (1 << K); mask++) {
            if(dp[mask] >= N) continue;

            for(int bit = 0; bit < K; bit++) {
                if((mask & (1 << bit)) == 0) {
                    dp[mask + (1 << bit)] = min(dp[mask + (1 << bit)], nxt[bit][dp[mask]] + len);
                }
            }
        }

        return dp[(1 << K) - 1] <= N;
    };


    int l = 0, r = N + 1;
    while(r > l + 1) {
        int m = (l + r) / 2;
        if(good(m)) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}