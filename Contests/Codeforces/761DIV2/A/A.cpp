#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s, t;
    cin >> s >> t;

    int ca = count(s.begin(), s.end(), 'a');
    int cb = count(s.begin(), s.end(), 'b');
    int cc = count(s.begin(), s.end(), 'c');

    if(ca == 0 || cb == 0 || cc == 0) {
        sort(s.begin(), s.end());
        cout << s << '\n';
        return;
    }

    map<char, int> weight;

    for(char c = 'a'; c <= 'z'; c++) {
        weight[c] = c - 'a';
    }

    if(t == "abc") {
        weight['b'] = 2;
        weight['c'] = 1;
    }

    sort(s.begin(), s.end(), [&](auto a, auto b) {
        return weight[a] < weight[b];
    });

    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}