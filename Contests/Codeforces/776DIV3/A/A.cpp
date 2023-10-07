#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s;
    cin >> s;
    char c;
    cin >> c;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] == c) {
            bool usedOdd = false;

            if(i & 1) {
                usedOdd = true;
            }

            int right = int(s.length()) - 1 - i;

            if(right % 2 == 0) {
                cout << "YES\n";
                return;
            }
            if((right & 1) && !usedOdd) {
                cout << "YES\n";
                return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}