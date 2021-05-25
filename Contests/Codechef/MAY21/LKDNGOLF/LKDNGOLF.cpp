#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t N, x, k;
    cin >> N >> x >> k;

    cout << ((x % k == 0 || (N + 1 - x) % k == 0) ? "YES\n" : "NO\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}