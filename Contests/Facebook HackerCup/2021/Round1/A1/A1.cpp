#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<vector<int>> dp(N, vector<int>(2, N + 100));

    // 0 -> left, 1 -> right

    if(S[0] == 'F') {
        dp[0][0] = 0, dp[0][1] = 0;
    } else if(S[0] == 'O') {
        dp[0][1] = 0;
    } else {
        dp[0][0] = 0;
    }

    for(int i = 1; i < N; i++) {
        if(S[i] == 'F') {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + 1);
        } else if(S[i] == 'O') {
            dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
        } else {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
        }
    }

    cout << min(dp[N - 1][0], dp[N - 1][1]) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("a1_validation_input.txt", "r", stdin);
    // freopen("a1_validation_output.txt", "w", stdout);

    /*For final submit*/
    // freopen("a1_final_input.txt", "r", stdin);
    // freopen("a1_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}