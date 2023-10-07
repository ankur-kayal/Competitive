#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;

    if(K > (N + 1) / 2) {
        cout << -1 << '\n';
        return;
    }

    vector<vector<char>> grid(N, vector<char>(N, '.'));
    int index = 0;
    for(int i = 0; i < K; i++) {
        grid[index][index] = 'R';
        index += 2;
    }

    for(auto u: grid) {
        for(auto v: u) {
            cout << v;
        }
        cout << '\n';
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