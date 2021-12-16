#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t X, K;
    cin >> X >> K;

    int64_t min_lcm = X * 2;

    int64_t max_lcm = (X * K) * (X * K - 1);

    cout << min_lcm << " " << max_lcm << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}