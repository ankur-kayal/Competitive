#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    string ans = "";;
    ans += s[0];
    for(int i = 1; i < N; i++) {
        if(s[i] < s[i - 1]) {
            ans += s[i];
        } else if(s[i] > s[i - 1]) {
            break;
        } else {
            if(s[0] == s[i]) {
                break;
            }
            ans += s[i];
        }
    }

    cout << ans;
    reverse(ans.begin(), ans.end());
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