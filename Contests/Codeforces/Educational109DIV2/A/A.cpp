#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int k;
    cin >> k;
    int ans = 100 / gcd(k, 100);
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