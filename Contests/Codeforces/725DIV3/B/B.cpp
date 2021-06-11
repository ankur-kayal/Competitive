#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;
    int64_t sum = accumulate(A.begin(), A.end(), 0LL);

    if(sum % N != 0) {
        cout << -1 << '\n';
        return;
    }

    int64_t eq = sum / N;

    int ans = 0;
    for(auto u: A)
        if(u > eq)
            ans++;

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