#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

bool verify(vector<int> A, vector<int> B) {
    vector<int> sums;
    for(int mask = 0; mask < (1 << 3); mask++) {
        int sum = 0;
        for(int bit = 0; bit < 3; bit++) {
            if(mask >> bit & 1) {
                sum += A[bit];
            }
        }
        if(sum > 0) {
            sums.push_back(sum);
        }
    }

    sort(sums.begin(), sums.end());
    return sums == B;
}

void run_cases() {
    vector<int> B(7);
    for(auto &u: B)
        cin >> u;

    vector<int> ans;
    while(true) {
        ans = {B[0], B[1], B[2]};
        if(verify(ans, B)) {
            break;
        }
        ans = {B[0], B[1], B[3]};
        break;
    }

    assert(verify(ans, B));
    for(auto u: ans) {
        cout << u << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}