#include <bits/stdc++.h>
using namespace std;

int64_t brute(int64_t N) {
    while(N < 6 || N & 1) {
        N++;
    }

    return N / 2 * 5;
}

const int64_t INF64 = 2e18;
vector<int64_t> dp(20000, INF64);
int64_t run_cases(int64_t N) {
    // int64_t N;
    // cin >> N;

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

    return ans;
}

int main() {    
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

    const int64_t maxN = 1e16;

    int64_t tests = 0;

    for(int64_t i = 1; i <= maxN; i++) {
        int64_t N = i;
        if(run_cases(N) != brute(N)) {
            cout << N << '\n';
            exit(1);
        }

        if(N % 10000000 == 0) {
            cout << N << " tests passed" << '\n';
        }
    }
}