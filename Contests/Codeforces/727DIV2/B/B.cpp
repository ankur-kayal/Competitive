#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<vector<int>> store(N + 1, vector<int>(26, 0));
    for(int i = 0; i < N; i++) {
        store[i + 1] = store[i];
        store[i + 1][s[i] - 'a']++;
    }
    while(Q--) {
        int l, r;
        cin >> l >> r;
        --l;
        int64_t ans = 0;
        for(int64_t i = 0; i < 26; i++) {
            ans += (i + 1) * (store[r][i] - store[l][i]);
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}