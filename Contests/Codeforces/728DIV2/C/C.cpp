#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int64_t> D(N);
    for(auto &u: D)
        cin >> u;
    sort(D.begin(), D.end());

    int64_t plus = 0, minus = 0;

    int64_t sum = 0;

    for(int64_t i = 0; i < N; i++) {
        if(i + 1 < N) {
            plus += D[i + 1] - D[i];
        }
        minus += (i * D[i] - sum);
        sum += D[i];
    }

    cout << plus - minus << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}