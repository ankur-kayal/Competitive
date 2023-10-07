#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> bits(31);

    for(auto &u: A)
        cin >> u;

    for(int i = 0; i < N; i++) {
        for(int bit = 0; bit < 31; bit++) {
            if(A[i] >> bit & 1) {
                bits[bit]++;
            }
        }
    }

    int ans = 0;
    for(int bit = 0; bit < 31; bit++) {
        if(bits[bit] > 1) {
            ans += (1 << bit);
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