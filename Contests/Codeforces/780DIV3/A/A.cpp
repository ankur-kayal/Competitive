#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int a, b;
    cin >> a >> b;

    if(a == 0) {
        cout << 1 << '\n';
    } else {
        cout << a + 2 * b + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}