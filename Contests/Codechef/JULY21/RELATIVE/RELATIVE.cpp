#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int g, c;
    cin >> g >> c;
    cout << (c * c / (2 * g)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}