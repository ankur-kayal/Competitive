#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string N;
    cin >> N;

    if((N.back() - '0') % 2 == 0) {
        cout << 0 << '\n';
    } else if((N[0] - '0') % 2 == 0) {
        cout << 1 << '\n';
    } else {
        int even = 0;
        for(auto u: N) {
            if((u - '0') % 2 == 0) {
                even++;
            }
        }

        cout << (even > 0 ? 2 : -1) << '\n';
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