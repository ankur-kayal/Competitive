#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int64_t> A(N);

    for(auto &u: A)
        cin >> u;

    sort(A.begin(), A.end());

    if(N == 1) {
        if(A[0] > 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    } else {
        if(A[N - 1] - A[N - 2] <= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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