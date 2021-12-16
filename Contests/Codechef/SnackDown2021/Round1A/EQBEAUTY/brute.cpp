#include <bits/stdc++.h>
#include <iterator>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int64_t> A(N);

    for(auto &u: A) 
        cin >> u;

    sort(A.begin(), A.end());

    int l = 1, r = N - 2;

    if(N == 2) {
        cout << 0 << '\n';
        return;
    }

    if(N == 3) {
        cout << min(A[1] - A[0], A[2] - A[1]) << '\n';
        return;
    }

    int64_t ans1 = 0, ans2 = 0;

    for(int i = 0; i < N - 1; i++) {
        ans1 += abs(A[i] - A[(N - 1) / 2]);
    }

    for(int i = 1; i < N; i++) {
        ans2 += abs(A[i] - A[1 + (N - 1) / 2]);
    }

    int64_t ans = min(ans1, ans2);

    while(l < r) {
        int64_t d2 = A[N - 1] - A[l];
        int64_t d1 = A[r] - A[0];

        ans = min(ans, abs(d1 - d2));

        if(d1 < d2) {
            l++;
        } else {
            r--;
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