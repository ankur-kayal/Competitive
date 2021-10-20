#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int get_votes(int a, int b, int c) {
    return max(0, max(b, c) + 1 - a);
}

void run_cases() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << get_votes(a, b, c) << " " << get_votes(b, a, c) << " " << get_votes(c, a, b) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}