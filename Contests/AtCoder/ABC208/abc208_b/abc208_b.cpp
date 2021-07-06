#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    vector<int64_t> coins;
    int64_t fact = 1;
    for(int i = 1; i <= 10; i++) {
        fact *= i;
        coins.push_back(fact);
    }

    int64_t P;
    cin >> P;

    int64_t cnt = 0;

    while(P > 0) {
        cnt += P / coins.back();
        P = P % coins.back();
        coins.pop_back();
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}