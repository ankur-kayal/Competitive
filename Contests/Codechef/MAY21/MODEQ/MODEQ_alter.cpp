#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t N, M;
    cin >> N >> M;

    int64_t ans = N-1;
    vector<int64_t> cnt(N + 1, 0);
    for(int i=N;i>=2;i--) {
        int64_t rem = M % i;
        for(int j=rem;j<=min(N, M);j+=i) {
            ans += cnt[j];
        }
        cnt[rem]++;
    }


    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}