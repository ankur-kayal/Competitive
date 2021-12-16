#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int a, b;
    cin >> a >> b;

    int A = min(a, b);
    int B = max(a, b);

    int Q = min(A, (B - A) / 2);

    int P = A - Q;

    int R = B - 3 * Q;

    int ans = Q;

    if(R != 0 && P != 0) {
        ans += (P + R) / 4;
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