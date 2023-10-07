#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;

    int ans = 1e9;

    if(rb > rd) {
        ans = min(ans, n - rb + n - rd);
    }

    if(rb <= rd) {
        ans = min(ans, rd - rb);
    }

    if(cb > cd) {
        ans = min(ans, m - cb + m - cd);
    }

    if(cb <= cd) {
        ans = min(ans, cd - cb);
    }

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