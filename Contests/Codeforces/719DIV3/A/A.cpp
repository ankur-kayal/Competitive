#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s.resize(unique(s.begin(), s.end()) - s.begin());
    for(char c = 'A'; c <= 'Z';c++) {
        if(count(s.begin(), s.end(), c) > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}