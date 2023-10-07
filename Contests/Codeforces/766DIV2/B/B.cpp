#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int md(array<int, 2> a, array<int, 2> b) {
    return abs(a[0]-b[0]) + abs(a[1] - b[1]);
}

void run_cases() {
    int N, M;
    cin >> N >> M;

    vector<int> distances;

    vector<vector<int>> vis(N, vector<int>(M, 0));
    array<int, 2> tl = {0, 0};
    array<int, 2> tr = {0, M - 1};
    array<int, 2> bl = {N - 1, 0};
    array<int, 2> br = {N - 1, M - 1};


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            array<int, 2> pt = {i, j};
            int d = md(pt, tl);
            d = max(d, md(pt, tr));
            d = max(d, md(pt, br));
            d = max(d, md(pt, bl));
            distances.push_back(d);
        }
    }

    sort(distances.begin(), distances.end());
    for(auto u: distances) {
        cout << u << ' ';
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