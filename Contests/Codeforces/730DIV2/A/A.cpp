#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t a, b;
    cin >> a >> b;
    int64_t ans = abs(a - b);

    if(ans == 0) {
        cout << "0 0\n";
        return;
    }

    int64_t moves = a % ans;

    moves = min(moves, ans - moves);

    cout << ans << " " << moves << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}