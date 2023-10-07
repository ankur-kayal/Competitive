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


    const int maxA = *max_element(A.begin(), A.end());
    vector<bool> present(maxA + 1);

    for(auto u: A) {
        present[u] = true;
    }

    for(int64_t i = maxA; i >= 1; i--) {
        if(present[i]) {
            continue;
        }
        int hcf = 0;
        for(int64_t j = 1; j * i <= maxA; j++) {
            if(present[j * i]) {
                hcf = gcd(j, hcf);
                if(hcf == 1) {
                    present[i] = true;
                    break;
                }
            }
        }
    }

    int answer = -N;

    for(auto u: present) {
        answer += u;
    }

    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}