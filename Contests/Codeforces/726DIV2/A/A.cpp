#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    int sum = accumulate(A.begin(), A.end(), 0);
    if(sum < N) {
        cout << 1 << '\n';
    } else {
        cout << sum - N << '\n';
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