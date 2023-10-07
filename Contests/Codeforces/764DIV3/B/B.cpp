#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int a, b, c;
    cin >> a >> b >> c;

    bool ok = false;

    {
        int d = c - b;
        int ra = b - d;

        if(ra % a == 0 && ra / a > 0) {
            ok = true;
        }
    }

    {
        int d = b - a;
        int rc = b + d;

        if(rc % c == 0 && rc / c > 0) {
            ok = true;
        }
    }

    {
        int d = c - a;

        if(d % 2 == 0) {
            d = d / 2;
            int rb = a + d;
            if(rb % b == 0 && rb / b > 0) {
                ok = true;
            }
        }
        
    }


    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}