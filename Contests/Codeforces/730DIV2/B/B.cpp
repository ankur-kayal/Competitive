#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    int64_t sum = accumulate(A.begin(), A.end(), 0LL);

    int64_t first = N;
    int64_t second = sum % N;
    first -= second;

    cout << first * second << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}