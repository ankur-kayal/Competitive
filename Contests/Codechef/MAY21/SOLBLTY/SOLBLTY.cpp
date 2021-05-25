#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int X, A, B;
    cin >> X >> A >> B;

    cout << (A + (100 - X) * B) * 10 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}