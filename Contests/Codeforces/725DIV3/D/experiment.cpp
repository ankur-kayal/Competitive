#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int maxN = 1e9;
void run_cases() {
    int64_t p = 1;
    while(p * 2 <= maxN) {
        p *= 2;
    }
    cout << p;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}