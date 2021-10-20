#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n;
    cin >> n;

    for(int times = 0; times < n; times++) {
        for(int single = 0; single < times; single++) {
            cout << "()";
        }

        for(int complete = times; complete < n; complete++) {
            cout << '(';
        }
        for(int complete = times; complete < n; complete++) {
            cout << ')';
        }
        cout << '\n';
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