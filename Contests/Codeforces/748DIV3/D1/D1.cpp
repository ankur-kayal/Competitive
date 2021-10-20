#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    int ans = 0;

    int hcf = 0;

    int target = *min_element(A.begin(), A.end());

    if(count(A.begin(), A.end(), target) == N) {
        cout << -1 << '\n';
        return;
    }

    for(auto u: A) {
        hcf = gcd(hcf, u - target);
    }

    cout << hcf << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}