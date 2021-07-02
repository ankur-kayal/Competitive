#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;
    cout << n << " ";
    for(int i = 1; i < n; i++) {
        cout << i << " ";
    }
    cout << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}