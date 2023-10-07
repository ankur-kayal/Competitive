#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s;
    cin >> s;

    if(s.length() & 1) {
        cout << "NO\n";
    } else {
        int half = s.length() / 2;
        cout << (s.substr(0, half) == s.substr(half) ? "YES" : "NO") << '\n';
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