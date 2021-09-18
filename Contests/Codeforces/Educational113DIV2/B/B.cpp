#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    vector<vector<char>> ans(N, vector<char>(N, 'X'));

    vector<bool> won(N, false);

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(s[i] == '1' && s[j] == '1') {
                ans[i][j] = '=';
                ans[j][i] = '=';
            } else if(s[i] == '1' && s[j] == '2') {
                ans[i][j] = '+';
                ans[j][i] = '-';
            } else if(s[j] == '1' && s[i] == '2') {
                ans[i][j] = '-';
                ans[j][i] = '+';
            } else {
                if(won[i]) {
                    ans[i][j] = '-';
                    ans[j][i] = '+';
                    won[j] = true;
                } else {
                    ans[i][j] = '+';
                    ans[j][i] = '-';
                    won[i] = true;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(s[i] == '2' && !won[i]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES" << '\n';

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << ans[i][j];
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