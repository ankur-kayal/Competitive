#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    vector<int> s(4);
    for(auto &u: s) {
        cin >> u;
    }

    int w1 = max(s[0], s[1]);
    int w2 = max(s[2], s[3]);

    sort(s.rbegin(), s.rend());

    if(w1 < w2) {
        swap(w1, w2);
    }

    if(w1 == s[0] && w2 == s[1]) {
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