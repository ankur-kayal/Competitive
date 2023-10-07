#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N),B(N);
    for(auto &u: A)
        cin >> u;
    for(auto &u: B)
        cin >> u;

    for(int i = 0; i < N; i++) {
        if(A[i] > B[i]) {
            swap(A[i], B[i]);
        }
    }

    cout << *max_element(A.begin(), A.end()) * *max_element(B.begin(), B.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}