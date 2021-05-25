#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t A, B;
    cin >> A >> B;
    if(B == 1) {
        cout << "NO\n";
        return;
    }
    int64_t z = A * B * 2;
    int64_t y = A * (2 * B - 1);
    int64_t x = A;

    cout << "YES\n";
    cout << x << " " << y << " " << z << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}