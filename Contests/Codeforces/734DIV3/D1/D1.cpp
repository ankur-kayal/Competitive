#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, M, K;
    cin >> N >> M >> K;

    if(M == 1 && K > 0) {
        cout << "NO\n";
        return;
    }

    int horizontal = K;
    int vertical = N * M  / 2 - K;

    if(N % 2 == 1) {
        horizontal -= M / 2;
    } else if(M % 2 == 1) {
        vertical -= N / 2;
    }

    if(horizontal >= 0 && vertical >= 0 && horizontal % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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