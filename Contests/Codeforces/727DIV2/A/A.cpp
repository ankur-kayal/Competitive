#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t N, X, T;
    cin >> N >> X >> T;

    int64_t bad = min(N, T / X);

    int64_t bad_problem = N * bad - (bad * (bad + 1) / 2);

    cout << bad_problem << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}