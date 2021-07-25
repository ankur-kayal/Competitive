#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;
    int c = n / 3;
    if(n % 3 == 0) {
        cout << c << " " << c << '\n';
    } else if(n % 3 == 1) {
        cout << c + 1 << " " << c << '\n';
    } else {
        cout << c << " " << c + 1 << '\n';
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