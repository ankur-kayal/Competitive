#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &u: A) {
        cin >> u;
    }

    int times = 0;

    sort(A.begin(), A.end());

    int64_t sum = 0;

    for(int i = 0; i < N; i++) {
        int64_t current_sum = A[i];
        int64_t odd = 0;
        for(int j = 0; j < N; j++) {
            if(j != i) {
                int times = A[j];
                while(times % 2 == 0) {
                    current_sum *= 2;
                    times /= 2;
                }
                odd += times;
            }
        }

        sum = max(current_sum + odd, sum);
    }

    cout << sum << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}