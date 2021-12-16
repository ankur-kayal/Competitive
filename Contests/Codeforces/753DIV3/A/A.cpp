#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string pattern, s;
    cin >> pattern >> s;

    map<char, int> id;

    for(char i = 'a'; i <= 'z'; i++) {
        id[i] = pattern.find(i);
    }

    int ans = 0;
    int prev = -1;

    for(auto u: s) {
        int position = id[u];
        if(prev != -1) {
            ans += abs(prev - position);
        }

        prev = position;
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