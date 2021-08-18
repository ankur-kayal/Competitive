#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int S, T;
    cin >> S >> T;

    int ans = 0;

    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100; j++) {
            for(int k = 0; k <= 100; k++) {
                if(i + j + k <= S && i * j * k <= T) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}