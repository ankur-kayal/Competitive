#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int a, b, c;
    cin >> a >> b >> c;

    int d1 = abs(a + b - 2 * c);
    int d2 = abs(a + c - 2 * b);
    int d3 = abs(b + c - 2 * a);

    int ans = min({d1 % 3, d2 % 3, d3 % 3});

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