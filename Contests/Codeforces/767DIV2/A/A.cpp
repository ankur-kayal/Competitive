#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, K;
    cin >> N >> K;

    vector<int> A(N), B(N);
    for(auto &u: A)
        cin >> u;
    for(auto &u: B)
        cin >> u;

    vector<int> vis(N);
    while(true) {
        bool operated = false;
        for(int i = 0; i < N; i++) {
            if(A[i] <= K && !vis[i]) {
                vis[i] = true;
                operated = true;
                K += B[i];
            }
        }
        if(!operated) {
            break;
        }
    }

    cout << K << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}