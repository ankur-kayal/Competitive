#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int s;
    cin >> s;
    int ans = 0;
    for(int i = 1; i < 100100; i += 2) {
        s -= i;
        ans++;
        if(s <= 0) {
            break;
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