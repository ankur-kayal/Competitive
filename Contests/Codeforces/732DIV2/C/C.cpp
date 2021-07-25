#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {

    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    vector<vector<int>> pos(*max_element(A.begin(), A.end())+1, vector<int>(2, 0));
    vector<int64_t> B = A;
    sort(B.begin(), B.end());
    for(int i = 0; i < N; i++) {
        pos[B[i]][i % 2]++;
        pos[A[i]][i % 2]--;
    }

    for(auto u: pos) {
        if(u != vector<int>{0, 0}) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}