#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    for(int i=0;;i++) {
        int64_t K = (1LL << i) - 1;
        if(K >= N) {
            cout << (K >> 1) << '\n';
            return;
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