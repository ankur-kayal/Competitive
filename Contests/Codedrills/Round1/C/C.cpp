#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t n, x;
    cin >> n >> x;

    int64_t m = 1LL << 31;

    int k = 0;

    while(n > x && m > 0) {
        if(m <= n) {
            if(n % m <= x) {
                int times = (n - x + m - 1) / m;
                k += times;
                n -= (times) * m;
            } else {
                k += (n / m);
                n %= m;
            }
            
        }
        m = m / 4;
    }

    if(n > x) {
        cout << -1 << '\n';
    } else {
        if(n != 0) {
            k++;
        }
        cout << k << '\n';
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