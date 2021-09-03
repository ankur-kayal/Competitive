#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define nl '\n'

map<int, double> cache;

vector<double> A(1000100);


void run_cases() {
    int64_t N;
    cin >> N;

    if(N <= 1000000) {
        cout << A[N] << '\n';
    } else {
        cout << A[1000000] + log(N) - log(1000001) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    A[1] = 1;

    for(double i = 2; i < 1000100; i++) {
        A[i] = A[i - 1] + 1 / i;
    }

    cout << setprecision(10) << fixed;

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}