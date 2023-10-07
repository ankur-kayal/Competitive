#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, L;
    cin >> N >> L;

    vector<int> X(N);
    for(auto &u: X)
        cin >> u;

    vector<int> bits(L);
    for(int i = 0; i < N; i++) {
        for(int bit = 0; bit < L; bit++) {
            if(X[i] >> bit & 1) {
                bits[bit]++;
            }
        }
    }

    int Y = 0;
    for(int bit = 0; bit < L; bit++) {
        if(bits[bit] > N / 2) {
            Y += (1 << bit);
        }
    }

    cout << Y << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}