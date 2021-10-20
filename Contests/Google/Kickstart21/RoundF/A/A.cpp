#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int INF = 1e9 + 7;
    int N;
    cin >> N;
    string s;
    cin >> s;

    vector<int> left(N, -INF), right(N, INF);
    vector<int> pos;
    right[N - 1] = 1e9;
    left[0] = -1e9;

    for(int i = 0; i < N; i++) {
        if(s[i] == '1') {
            left[i] = i;
            right[i] = i;
        }
    }

    for(int i = 1; i < N; i++) {
        left[i] = max(left[i], left[i - 1]);
    }
    for(int i = N - 2; i >= 0; i--) {
        right[i] = min(right[i + 1], right[i]);
    }



    int64_t ans = 0;
    for(int i = 0; i < N; i++) {
        int l = abs(left[i] - i);
        int r = abs(right[i] - i);

        ans += min(l, r);
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}