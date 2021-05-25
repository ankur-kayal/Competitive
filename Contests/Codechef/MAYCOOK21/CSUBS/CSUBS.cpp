#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    map<int64_t, int64_t> cnt;
    int N, K;
    cin >> N >> K;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    int l = 0;
    int64_t sum = 0;
    for(int r = 0; r < N; r++) {
        sum += A[r];
        if(r - l + 1 > K) {
            sum -= A[l];
            l++;
        }
        if(r - l + 1 == K) {
            cnt[sum]++;
        }
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