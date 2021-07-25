#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(auto &u: A)
        cin >> u;
    for(auto &u: B)
        cin >> u;

    if(accumulate(A.begin(), A.end(), 0) != accumulate(B.begin(), B.end(), 0)) {
        cout << -1 << '\n';
        return;
    }
    vector<pair<int,int>> ops;
    for(int i = 0 ; i < N; i++) {
        while(A[i] < B[i]) {
            for(int j = 0; j < N; j++) {
                if(A[j] > B[j]) {
                    ops.emplace_back(j + 1, i + 1);
                    A[j]--;
                    A[i]++;
                    break;
                }
            }
        }
        while(A[i] > B[i]) {
            for(int j = 0; j < N; j++) {
                if(A[j] < B[j]) {
                    ops.emplace_back(i + 1, j + 1);
                    A[j]++;
                    A[i]--;
                    break;
                }
            }
        }
    }

    cout << ops.size() << '\n';
    for(auto [i, j]: ops) {
        cout << i << " " << j << '\n';
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