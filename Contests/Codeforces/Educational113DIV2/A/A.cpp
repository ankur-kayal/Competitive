#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {

    int N;
    cin >> N;
    string s;
    cin >> s;

    for(int l = 0; l < N; l++) {
        int a = 0, b = 0;
        for(int r = l; r < N; r++) {
            if(s[r] == 'a') {
                a++;
            } else {
                b++;
            }
            if(a == b) {
                cout << l + 1 << " " << r + 1 << '\n';
                return;
            }
        }
    }
    cout << "-1 -1" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}