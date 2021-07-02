#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int64_t INF64 = 2e18+100;
void run_cases() {
    int N;
    cin >> N;
    vector<vector<int64_t>> points(N, vector<int64_t>(2));
    for(int i = 0; i < N; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    if(N == 1) {
        cout << 0 << '\n';
        return;
    }


    int64_t ans = INF64;

    auto area = [&](vector<int64_t> rect) -> int64_t {
        int64_t A = abs(rect[0] - rect[1]) * abs(rect[2] - rect[3]);
        return A;
    };

    auto solve = [&]() -> void {
        vector<vector<int64_t>> rectangles_up(N, vector<int64_t>{-1, INF64, -1, INF64});
        rectangles_up[0] = {points[0][0], points[0][0], points[0][1], points[0][1]};
        for(int i = 1; i < N; i++) {
            rectangles_up[i][0] = min(rectangles_up[i - 1][0], points[i][0]);
            rectangles_up[i][1] = max(rectangles_up[i - 1][1], points[i][0]);
            rectangles_up[i][2] = min(rectangles_up[i - 1][2], points[i][1]);
            rectangles_up[i][3] = max(rectangles_up[i - 1][3], points[i][1]);
        }
        vector<vector<int64_t>> rectangles_down(N, vector<int64_t>{-1, INF64, -1, INF64});
        rectangles_down[N - 1] = {points[N - 1][0], points[N - 1][0], points[N - 1][1], points[N - 1][1]};
        for(int i = N - 2; i >= 0; i--) {
            rectangles_down[i][0] = min(rectangles_down[i + 1][0], points[i][0]);
            rectangles_down[i][1] = max(rectangles_down[i + 1][1], points[i][0]);
            rectangles_down[i][2] = min(rectangles_down[i + 1][2], points[i][1]);
            rectangles_down[i][3] = max(rectangles_down[i + 1][3], points[i][1]);
        }

        for(int i = 1; i < N; i++) {
            ans = min(ans, area(rectangles_down[i]) + area(rectangles_up[i - 1]));
        }
    };

    // sweep by x
    sort(points.begin(), points.end(), [&](vector<int64_t> a, vector<int64_t> b) {
        return a[0] < b[0];
    });
    solve();

    // sweep by y
    for(int i = 0; i < N; i++) {
        swap(points[i][0], points[i][1]);
    }
    sort(points.begin(), points.end(), [&](vector<int64_t> a, vector<int64_t> b) {
        return a[0] < b[0];
    });
    solve();

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