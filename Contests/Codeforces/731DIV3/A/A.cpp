#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int xa, ya, xb, yb, xf, yf;
    cin >> xa >> ya >> xb >> yb >> xf >> yf;
    int ans = abs(xb - xa) + abs(ya - yb);

    if(xa == xb && xb == xf) {
        if(ya < yf && yf < yb) {
            ans += 2;
        }
        if(yb < yf && yf < ya) {
            ans += 2;
        }
    }

    if(ya == yb && yb == yf) {
        if(xa < xf && xf < xb) {
            ans += 2;
        }
        if(xb < xf && xf < xa) {
            ans += 2;
        }
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