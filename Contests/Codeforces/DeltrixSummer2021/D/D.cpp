#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int64_t get_sum(int i, int j) {
    cout << "and " << i + 1 << " " << j + 1 << endl;
    int A, X, R, S;
    cin >> A;

    if(A == -1) {
        exit(1);
    }

    cout << "or " << i + 1 << " " << j + 1 << endl;
    cin >> R;

    if(R == -1)
        exit(-1);

    X = A ^ R;

    S = X + 2 * A;

    return S;
}

void run_cases() {
    int N, K;
    cin >> N >> K;

    int64_t sum01 = get_sum(0, 1); // a + b
    int64_t sum12 = get_sum(1, 2); // b + c
    int64_t sum02 = get_sum(0, 2); // c + a

    vector<int64_t> A(N);
    A[0] = (sum01 - sum12 + sum02) / 2;
    A[1] = (sum01 + sum12 - sum02) / 2;
    A[2] = (sum02 + sum12 - sum01) / 2;

    for(int i = 3; i < N; i++) {
        A[i] = get_sum(i, i - 1) - A[i - 1];
    }

    sort(A.begin(), A.end());

    cout << "finish " << A[K - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}