#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int a, b, c;
    cin >> a >> b >> c;

    int half = abs(a - b);

    if(2 * half < max({a, b, c})) {
        cout << -1 << '\n';
        return;
    }

    if(c > 2 * half) {
        cout << -1 << '\n';
        return;
    }

    if(c + half > 2 * half) {
        cout << c - half << '\n';
    } else {
        cout << c + half << '\n';
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