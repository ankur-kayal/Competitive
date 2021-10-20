#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int ans = 0;
    for(auto u: s) {
        int c = u - '0';
        if(c != 0) {
            ans += c + 1;
        }
    }

    if(s.back() != '0') {
        ans--;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}