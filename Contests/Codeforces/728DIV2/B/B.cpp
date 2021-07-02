#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    int64_t ans = 0;
    for(int j = 1; j <= N; j++) {
        int start = A[j - 1] - (j % A[j - 1]);
        for(int i = start; i < j; i += A[j - 1]) {
            if((i + j) / A[j - 1] == A[i - 1]) {
                ans++;
            }
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