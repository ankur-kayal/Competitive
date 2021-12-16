#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n, m;
    cin >> n >> m;

    if(n == 1 and m == 1) {
        cout << 0 << '\n';
        return;
    }

    cout << min({n, m, 2}) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}