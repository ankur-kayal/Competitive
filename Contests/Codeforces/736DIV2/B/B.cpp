#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    string enemy;
    cin >> enemy;

    string me;
    cin >> me;

    vector<bool> used(N, false);

    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(me[i] == '1') {
            if(enemy[i] == '0') {
                ans++;
            } else if(enemy[i] == '1') {
                bool ok = false;
                if(i - 1 >= 0 && enemy[i - 1] == '1' && !used[i - 1]) {
                    used[i - 1] = true;
                    ok = true;
                } else if(i + 1 < N && enemy[i + 1] == '1' && !used[i + 1]) {
                    used[i + 1] = true;
                    ok = true;
                }
                if(ok) {
                    ans++;
                }
            }
        }
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