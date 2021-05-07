#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int64_t n;
    cin >> n;

    int ans = 0;
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            string s(j, '1');
            if(stoll(s) * i <= n) {
                ans++;
            }
        }
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