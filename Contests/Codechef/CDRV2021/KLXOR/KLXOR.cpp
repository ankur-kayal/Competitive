#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;

    string S;
    cin >> S;

    vector<int64_t> A(K + 10);
    vector<int> l(N), r(N);

    for(int i = N - 1, j = K; i >= 0; i--, j = max(j - 1, 1)) {
        l[i] = j;
    }
    for(int i = 0, j = 1; i < N; i++, j = min(j + 1, K)) {
        r[i] = j;
    }

    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            A[l[i]]++;
            A[r[i] + 1]--;
        }
    }

    int ans = 0;
    for(int i = 1; i <= K; i++) {
        A[i] += A[i - 1];
        if(A[i] & 1) {
            ans++;
        }
    }

    // for(int i = 1; i <= K; i++) {
    //     cout << A[i] << " ";
    // }
    // cout << '\n';

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