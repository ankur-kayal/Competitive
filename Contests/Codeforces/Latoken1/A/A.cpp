#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    for(auto &u: A)
        cin >> u;

    bool ok = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i + j) % 2 == 0 && A[i][j] == 'W') {
                ok = false;
            }
            if((i + j) % 2 == 1 && A[i][j] == 'R') {
                ok = false;
            }
        }
    }

    if(ok) {
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i + j) % 2 == 0) {
                    cout << 'R';
                }
                if((i + j) % 2 == 1) {
                    cout << 'W';
                }
            }
            cout << '\n';
        }
        return;
    }

    ok = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i + j) % 2 == 1 && A[i][j] == 'W') {
                ok = false;
            }
            if((i + j) % 2 == 0 && A[i][j] == 'R') {
                ok = false;
            }
        }
    }

    if(ok) {
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if((i + j) % 2 == 1) {
                    cout << 'R';
                }
                if((i + j) % 2 == 0) {
                    cout << 'W';
                }
            }
            cout << '\n';
        }
        return;
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}