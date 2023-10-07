#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    int ans = 0;

    auto valid = [&](int plus, int minus, int groups) {
        if(minus == plus) {
            return true;
        }
        if(minus < plus) {
            return false;
        }

        int rem = minus - plus;

        if(rem % 3 == 0) {
            if(rem / 3 <= groups) {
                return true;
            }
        }

        return false;
    };

    for(int i = 0; i < N; i++) {
        int minus = 0, plus = 0;
        int minusLength = 0;
        int groups = 0;
        for(int j = i; j < N; j++) {
            if(s[j] == '-') {
                minus++;
                minusLength++;
            } else {
                minusLength = 0;
                plus++;
            }
            if(minusLength > 1) {
                groups++;
                minusLength = 0;
            }

            if(valid(plus, minus, groups)) {
                ans++;
            }
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