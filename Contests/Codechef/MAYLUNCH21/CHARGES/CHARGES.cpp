#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    string s;
    cin >> s;

    int64_t ans = 0;
    for(int i=0;i+1<N;i++) {
        ans += (s[i] == s[i + 1] ? 2 : 1);
    }

    for(int i=0;i<K;i++) {
        int q;
        cin >> q;
        --q;
        if(q - 1 >= 0) {
            if(s[q] == s[q - 1]) {
                ans -= 2;
            } else {
                ans -= 1;
            }
        }

        if(q + 1 < N) {
            if(s[q] == s[q + 1]) {
                ans -= 2;
            } else {
                ans -= 1;
            }
        }

        s[q] = (s[q] == '1' ? '0' : '1');

        if(q - 1 >= 0) {
            if(s[q] == s[q - 1]) {
                ans += 2;
            } else {
                ans += 1;
            }
        }

        if(q + 1 < N) {
            if(s[q] == s[q + 1]) {
                ans += 2;
            } else {
                ans += 1;
            }
        }

        cout << ans << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        solve();
    }
}