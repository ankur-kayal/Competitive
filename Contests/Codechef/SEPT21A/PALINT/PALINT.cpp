#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    map<int,int> cnt;
    for(auto u: A)
        cnt[u]++;

    pair<int,int> best = {0, 0};

    for(auto u: A) {
        int max_cnt = cnt[u] + (X == 0 ? 0 : cnt[u ^ X]);
        int moves = (X == 0 ? 0 : cnt[u ^ X]);

        best = max(best, make_pair(max_cnt, -moves));
    }

    cout << best.first << " " << -best.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}