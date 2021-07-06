#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N, M;
    cin >> N >> M;
    const int64_t inf = 1e18;
    vector<vector<int64_t>> dist(N, vector<int64_t>(N, inf));
    for(int i = 0; i < N; i++) {
        dist[i][i] = 0;
    }

    for(int i = 0; i < M; i++) {
        int64_t a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        dist[a][b] = c;
    }

    int64_t ans = 0;

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                ans += (dist[i][j] == inf ? 0 : dist[i][j]);
            }
        }
    }


    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}