#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s;
    cin >> s;

    int a = count(s.begin(), s.end(), 'A');
    int b = count(s.begin(), s.end(), 'B');
    int c = count(s.begin(), s.end(), 'C');

    if(a + c == b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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