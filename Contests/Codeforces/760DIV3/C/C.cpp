#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    bool possible = true;
    // first try to color all odd

    int64_t hcf = A[0];
    for(int i = 0; i < N; i += 2) {
        hcf = gcd(hcf, A[i]);
    }

    for(int i = 1; i < N; i += 2) {
        if(A[i] % hcf == 0) {
            possible = false;
            break;
        }
    }

    if(possible) {
        cout << hcf << '\n';
        return;
    }

    possible = true;

    hcf = A[1];
    for(int i = 1; i < N; i += 2) {
        hcf = gcd(hcf, A[i]);
    }

    for(int i = 0; i < N; i += 2) {
        if(A[i] % hcf == 0) {
            possible = false;
            break;
        }
    }

    if(possible) {
        cout << hcf << '\n';
        return;
    }

    cout << 0 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}