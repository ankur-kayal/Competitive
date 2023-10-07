#include <bits/stdc++.h>
#include <string>
using namespace std;

#define nl '\n'

void run_cases() {
    string s;
    cin >> s;

    string fallback = to_string((s[0] - '0') + (s[1] - '0')) + s.substr(2);

    int N = s.length();


    for(int i = N - 2; i >= 0; i--) {
        int d1 = s[i] - '0';
        int d2 = s[i + 1] - '0';
        if(d1 + d2 > 9) {
            cout << s.substr(0, i) + to_string(d1 + d2) + s.substr(i + 2) << '\n';
            return;
        }
    }

    cout << fallback << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}