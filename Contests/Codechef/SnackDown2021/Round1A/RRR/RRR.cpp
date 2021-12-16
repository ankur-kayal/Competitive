#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int64_t INF64 = 2e18;

/*
0
2 0
4 2 2
6 4 4 2
8 6 6 4 4
10 8 8 6 6 4
12 10 10 8 8 6 6
*/

void run_cases() {
    int64_t N, K;
    cin >> N >> K;

    cout << 2 * (N - 1) - 2 * (K / 2) << '\n';    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}