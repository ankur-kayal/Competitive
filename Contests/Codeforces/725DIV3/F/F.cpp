#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t l, r;
    cin >> l >> r;

    int64_t ans = r - l;

    int64_t to_add = r - l;

    while(to_add != 0) {
        to_add = ((l % 10) + to_add) / 10;
        ans += to_add;
        l /= 10;
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