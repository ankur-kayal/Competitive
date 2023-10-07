#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int64_t sum(int64_t N) {
    return N * (N + 1) / 2LL;
}

void run_cases() {
    int N;
    cin >> N;

    vector<int64_t> K(N), H(N);
    for(auto &u: K)
        cin >> u;

    for(auto &u: H)
        cin >> u;

    vector<vector<int64_t>> segments;
    for(int i = 0; i < N; i++) {
        vector<int64_t> segment = {K[i] - H[i] + 1, K[i]};
        if(segments.empty()) {
            segments.push_back(segment);
        } else {
            int64_t l = segment[0];
            while(!segments.empty()) {
                vector<int64_t> last = segments.back();
                if(last[1] >= segment[0]) {
                    segments.pop_back();
                    l = min(last[0], segment[0]);
                } else {
                    break;
                }
            }
            segments.push_back({l, K[i]});
        }
    }

    int64_t ans = 0;

    for(auto u: segments) {
        int64_t length = u[1] - u[0] + 1;
        ans += sum(length);
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