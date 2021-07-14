#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s;
    cin >> s;
    int n = s.length();
    char start = 'a' + n - 1;

    while(!s.empty()) {
        if(*s.begin() == start) {
            s.erase(s.begin());
            start--;
        } else if(s.back() == start) {
            s.erase(prev(s.end()));
            start--;
        } else {
            break;
        }
    }

    cout << (s.empty() ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}