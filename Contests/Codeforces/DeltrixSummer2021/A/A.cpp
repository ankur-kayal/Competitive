#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int c, d;
    cin >> c >> d;

    if(abs(c - d) & 1) {
        cout << -1 << '\n';
    } else if(c == d) {
        if(c == 0) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
    } else{
        cout << 2 << '\n';
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