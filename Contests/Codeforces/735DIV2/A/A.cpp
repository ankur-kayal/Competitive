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
    for(int i = 0; i < N - 1; i++) {
        ans = max(ans, A[i] * A[i + 1]);
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