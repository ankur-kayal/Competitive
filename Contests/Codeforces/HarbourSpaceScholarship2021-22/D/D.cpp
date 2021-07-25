#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s, t;
    cin >> s >> t;
    while(!s.empty() && !t.empty()) {
        if(t.back() == s.back()) {
            t.pop_back();
            s.pop_back();
        } else {
            s.pop_back();
            if(!s.empty()) {
                s.pop_back();
            }
        }
    }
    if(t.empty()) {
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