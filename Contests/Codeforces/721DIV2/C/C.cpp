#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    map<int64_t, int64_t> cache;
    int64_t N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &u: A) {
        cin >> u;
    }

    int64_t ans = 0;
    for(int64_t i=1;i<=N;i++) {
        int64_t val = A[i - 1];
        ans += cache[val] * (N - i + 1);
        cache[val] += i;
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