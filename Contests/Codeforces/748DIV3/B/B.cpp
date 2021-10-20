#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int solve(int64_t n, string target) {
    string N = to_string(n);

    int cnt = 0;
    int rem = 0;

    int index = 1;

    for(int i = int(N.length()) - 1; i >= 0; i--) {
        if(N[i] == target[index]) {
            index--;
        }
        else {
            rem++;
        }
        if(index == -1) {
            break;
        }
    }

    if(index != -1) {
        return 100000;
    }

    return rem;
}

void run_cases() {
    int64_t n;
    cin >> n;

    vector<string> targets = {"00", "25", "50", "75"};

    int ans = 100000;

    for(auto u: targets) {
        ans = min(ans, solve(n, u));
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