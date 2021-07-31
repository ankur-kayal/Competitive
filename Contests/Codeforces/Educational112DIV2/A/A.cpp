#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int64_t INF64 = 2e18;
vector<int64_t> dp(20000, INF64);
void run_cases() {
    int64_t N;
    cin >> N;

    // lcm = 120

    // 15 * 20, 20 * 15, 25 * 12

    int64_t ori = N;

    int64_t mins = (N / 120) * (15 * 20);


    int64_t ans = INF64;

    if(N <= 10000) {
        ans = dp[N];
    } else {
        N %= 120;    
        ans = min({dp[N] + mins, dp[N + 6] + mins - 15, dp[N + 8] + mins - 20, dp[N + 10] + mins - 25});
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    dp[0] = 0;
    for(int i = 1; i <= 6; i++) {
        dp[i] = min(dp[i], int64_t(15));
    }

    for(int i = 1; i <= 8; i++) {
        dp[i] = min(dp[i], int64_t(20));
    }

    for(int i = 1; i <= 10; i++) {
        dp[i] = min(dp[i], int64_t(25));
    }


    for(int i = 0; i <= 10000; i++) {
        dp[i + 6] = min(dp[i + 6], dp[i] + 15);
        dp[i + 8] = min(dp[i + 8], dp[i] + 20);
        dp[i + 10] = min(dp[i + 10], dp[i] + 25);
    }

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}