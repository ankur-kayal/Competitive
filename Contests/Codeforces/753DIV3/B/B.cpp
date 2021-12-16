#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t x, n;
    cin >> x >> n;

    int parity = n % 4;

    int64_t sum = 0;

    if(parity == 0) {
        sum = 0;
    } else if(parity == 1) {
        sum = 4 * (n / 4) + 1;
    } else if(parity == 2) {
        sum = -1;
    } else {
        sum = -(4 * (n / 4) + 4);
    }

    if(abs(x) % 2 == 1) {
        x += sum;
    } else {
        x -= sum;
    }

    cout << x << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}