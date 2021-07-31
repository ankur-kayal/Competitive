#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;
    if(n <= 26) {
        for(int i = 0; i < n; i++) {
            cout << char(i + 'a');
        }
    } else {
        string ans = "";
        if(n & 1) {
            ans = "k";
            n--;
        }
        
        int m = n / 2;
        ans += string(m, 'a');
        ans += 'z';
        ans += string(m - 1, 'a');
        cout << ans;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}