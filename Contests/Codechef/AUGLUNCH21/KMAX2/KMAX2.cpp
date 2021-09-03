#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    int64_t ans = 0;

    int target = *max_element(A.begin(), A.end());

    for(int i = 0; i < N; i++) {
        int l = i - K + 1;
        if(A[i] != target) 
            continue;
        if(l < 0)
            continue;

        ans += N - i;

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