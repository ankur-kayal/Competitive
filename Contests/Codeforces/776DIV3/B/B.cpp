#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int l, r, a;
    cin >> l >> r >> a;

    int ans = r/a + (r % a);

    r -= (r % a);
    r--;
    if(l <= r) {
        ans = max(ans, r / a + (r % a));
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