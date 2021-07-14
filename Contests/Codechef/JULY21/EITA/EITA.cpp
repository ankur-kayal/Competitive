#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int d, x, y, z;
    cin >> d >> x >> y >> z;
    cout << max(x * 7, y * d + (7 - d) * z) << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}