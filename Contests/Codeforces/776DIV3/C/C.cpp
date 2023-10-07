#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, M;
    cin >> N >> M;

    vector<vector<int64_t>> points;

    for(int i = 0; i < M; i++) {
        int x, w;
        cin >> x >> w;

        points.push_back({x, w, i});
    }

    sort(points.begin(), points.end(), [&](const auto &a, const auto &b) {
        return a[1] < b[1];
    });

    deque<vector<int64_t>> chosen;
    for(int i = 0; i < 2 * N; i++) {
        chosen.push_back(points[i]);
    }

    sort(chosen.begin(), chosen.end(), [&](const auto &a, const auto &b){
        return a[0] < b[0];
    });

    int64_t weight = 0;
    vector<pair<int, int>> answer;

    while(!chosen.empty()) {
        int l = chosen.front()[2];
        int r = chosen.back()[2];

        weight += chosen.front()[1] + chosen.back()[1];

        answer.push_back({l + 1, r + 1});

        chosen.pop_front();
        chosen.pop_back();
    }

    cout << weight << '\n';
    for(auto [l, r]: answer) {
        cout << l << " " << r << '\n';
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