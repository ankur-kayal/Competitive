#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << c / a + d / b << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}