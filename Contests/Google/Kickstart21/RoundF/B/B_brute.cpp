#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int D, N, K;
    cin >> D >> N >> K;

    vector<vector<int64_t>> attractions(N, vector<int64_t>(3));

    for(int i = 0; i < N; i++) {
        int64_t h, s, e;
        cin >> h >> s >> e;
        attractions[i] = {h, s, e};
    }

    sort(attractions.rbegin(), attractions.rend());

    vector<int64_t> cnt(D + 1), values(D + 1);

    for(int i = 0; i < N; i++) {
        int64_t h = attractions[i][0], s = attractions[i][1], e = attractions[i][2];

        for(int j = s; j <= e; j++) {
            if(cnt[j] == K) {
                continue;
            }
            cnt[j]++;
            values[j] += h;
        }
    }

    cout << *max_element(values.begin(), values.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}