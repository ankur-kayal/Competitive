#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t D, d, P, Q;
    cin >> D >> d >> P >> Q;

    int64_t money = 0;
    int64_t times = (D + d - 1) / d;
    money += (P * times + Q * (times * (times - 1) / 2)) * d;
    int64_t extra = times * d - D;
    money -= extra * (P + (times - 1) * Q);

    cout << money << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}