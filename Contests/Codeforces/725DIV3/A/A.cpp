#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &u: A)
        cin >> u;
    int p1 = find(A.begin(), A.end(), 1) - A.begin();
    int p2 = find(A.begin(), A.end(), N) - A.begin();

    cout << min({max(p1, p2) + 1, min(p1, p2) + 1 + N - max(p1, p2), N - min(p1, p2)}) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}