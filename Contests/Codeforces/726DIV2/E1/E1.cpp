#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    string ans = string(K, s[0]);
    for(int i = 1; i <= N; i++) {
        string pattern = s.substr(0, i);
        string test = "";
        while(test.length() < K) {
            test += pattern;
        }
        ans = min(ans, test.substr(0, K));
    }
    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}