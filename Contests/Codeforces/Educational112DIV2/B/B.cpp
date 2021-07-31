#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t W, H;
    cin >> W >> H;

    int64_t x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int64_t w, h;
    cin >> w >> h;

    int64_t w1 = x2 - x1, h1 = y2 - y1;

    int64_t ans = 2e18;

    int64_t zero = 0;

    bool ok = false;

    if(h + h1 <= H) {
        ok = true;
        // we can place the block by shifting the old vertically
        // move up
        ans = min(ans, max(zero, h + h1 - y2));
        // move down
        ans = min(ans, max(zero, y1 - (H - h - h1)));
    }

    if(w + w1 <= W) {
        ok = true;
        // move left
        ans = min(ans, max(zero, x1 - (W - w - w1)));

        // move right
        ans = min(ans, max(zero, w + w1 - x2));
    }

    


    cout << (ok ? ans : -1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}