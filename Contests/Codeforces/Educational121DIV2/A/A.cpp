#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s;
    cin >> s;

    vector<int> cnt(26);
    for(auto u: s) {
        cnt[u - 'a']++;
    }

    string two = "";
    string one = "";
    for(int i = 0; i < 26; i++) {
        if(cnt[i] == 1) {
            one += char('a' + i);
        }
        if(cnt[i] == 2) {
            two += char('a' + i);
        }
    }

    cout << one + two + two << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}