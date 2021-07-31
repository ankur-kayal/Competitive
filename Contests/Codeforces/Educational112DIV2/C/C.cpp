#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int M;
    cin >> M;


    vector<vector<int64_t>> A(2, vector<int64_t>(M));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    int64_t ans = 2e18;

    for(int i = M - 2; i >= 0; i--) {
        A[0][i] += A[0][i + 1];
    }

    for(int i = 1; i < M; i++) {
        A[1][i] += A[1][i - 1];
    }

    for(int i = 0; i < M; i++) {
        int64_t top = (i + 1 < M ? A[0][i + 1] : 0);
        int64_t bottom = (i - 1 >= 0 ? A[1][i - 1] : 0);
        ans = min(ans, max(top, bottom));
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