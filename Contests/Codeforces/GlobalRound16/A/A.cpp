#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n, s;
    cin >> n >> s;

    int half = n / 2;
    
    int eq = s / (half + 1);

    cout << eq << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}