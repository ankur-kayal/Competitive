#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int64_t cost(vector<int64_t> &a, vector<int64_t> &target) {
    int x_diff = a[0] - target[0];
    int y_diff = a[1] - target[1];

    if(x_diff == 0 && y_diff == 0) {
        return 0;
    }
    else if(x_diff == 0 || y_diff == 0) {
        return 1;
    }
    else if((x_diff + y_diff) % 2 == 0) {
        return 1;
    }
    else {
        return 2;
    }
}

void run_cases() {
    int N;
    cin >> N;
    vector<vector<int64_t>> points(N, vector<int64_t>(2));
    for(int i = 0; i < N; i++) {
        cin >> points[i][0];
    }
    for(int i = 0; i < N; i++) {
        cin >> points[i][1];
    }

    int64_t best = 1e18;
    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        for(int j = 0; j < N; j++) {
            sum += cost(points[j], points[i]);
        }
        best = min(best, sum);
    }
    cout << best << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}