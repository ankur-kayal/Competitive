#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N = 5e5;
    int64_t iterations = 0;
    for(int i=N;i>=1;i--) {
        iterations += (N + i - 1) / i;
    }
    cout << iterations;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}