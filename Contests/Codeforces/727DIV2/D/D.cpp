#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int64_t zero = 0;

void run_cases() {
    int N;
    cin >> N;
    vector<vector<int64_t>> items(N, vector<int64_t>(2));
    for(int i = 0; i < N; i++) {
        cin >> items[i][0] >> items[i][1];
    }

    sort(items.begin(), items.end(), [&](auto &a, auto &b) {
        return a[1] < b[1];
    });

    int64_t discounted = 0, current = 0;
    int64_t total = 0;
    for(auto u: items) {
        total += u[0];
    }

    int l = 0, r = N - 1;

    while(l <= r) {
        int64_t req = max(zero, items[l][1] - current);

        if(req > 0) {
            int64_t got = min(req, items[r][0]);
            current += got;
            items[r][0] -= got;
            if(items[r][0] == 0) {
                r--;
            }
        } else {
            discounted += items[l][0];
            current += items[l][0];
            l++;
        }
    }

    cout << 2 * total - discounted << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}