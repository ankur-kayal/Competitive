#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t k;
    cin >> k;

    int64_t r = sqrtl(k);
    int64_t c;

    if(r * r != k) {
        r++;
    }

    int diff = r * r - k;

    if(diff > r - 1) {
        c = r;
        r = 2 * r - diff - 1;
    } else {
        c = diff + 1;
    }

    cout << r << " " << c << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}