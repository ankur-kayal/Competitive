#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int> A(N);

    for(auto &u: A)
        cin >> u;

    vector<int> odd, even;
    for(auto u: A) {
        if(u & 1) {
            odd.push_back(u);
        } else {
            even.push_back(u);
        }
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    vector<int> B;
    for(auto u: even) {
        B.push_back(u);
    }
    for(auto u: odd) {
        B.push_back(u);
    }

    int64_t ans = 0;

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(gcd(B[i], 2 * B[j]) > 1) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}