#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define nl '\n'

const int64_t INF64 = 1e18;

void run_cases() {
    int N;
    cin >> N;

    vector<vector<int64_t>> c(2 * N, vector<int64_t>(2 * N));
    for(int i = 0; i < 2 * N; i++) {
        for(int j = 0; j < 2 * N; j++) {
            cin >> c[i][j];
        }
    }

    vector<vector<int64_t>> d(2 * N, vector<int64_t>(2 * N, INF64));
    d[0][0] = 0;

    priority_queue<vector<int64_t>, vector<vector<int64_t>>, greater<vector<int64_t>>>  pq;

    pq.push({d[0][0], 0, 0});

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while(!pq.empty()) {
        vector<int64_t> element = pq.top();
        pq.pop();
        int64_t current_cost = element[0];
        int x = element[1];
        int y = element[2];

        if(d[x][y] < current_cost) {
            continue;
        }

        for(int i = 0; i < 4; i++) {
            int nx = (x + dx[i] + 2 * N) % (2 * N);
            int ny = (y + dy[i] + 2 * N) % (2 * N);

            int64_t cost = 0;

            if(dx[i] == 1) {
                int row = (x + N + 2 * N) % (2 * N);
                int col = y;
                for(int j = 1; j <= N; j++) {
                    cost += c[row][col];
                    col++;
                    col %= (2 * N);
                }
            }
            if(dx[i] == -1) {
                int row = (x - 1 + 2 * N) % (2 * N);
                int col = y;
                for(int j = 1; j <= N; j++) {
                    cost += c[row][col];
                    col++;
                    col %= (2 * N);
                }
            }
            if(dy[i] == 1) {
                int col = (y + N + 2 * N) % (2 * N);
                int row = x;
                for(int j = 1; j <= N; j++) {
                    cost += c[row][col];
                    row++;
                    row %= (2 * N);
                }
            }
            if(dy[i] == -1) {
                int col = (y - 1 + 2 * N) % (2 * N);
                int row = x;
                for(int j = 1; j <= N; j++) {
                    cost += c[row][col];
                    row++;
                    row %= (2 * N);
                }
            }

            if(current_cost + cost < d[nx][ny]) {
                d[nx][ny] = current_cost + cost;
                pq.push({d[nx][ny], nx, ny});
            }
        }
    }

    // for(int i = 0; i < 2 * N; i++) {
    //     for(int j = 0; j < 2 * N; j++) {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << '\n';
    // }


    cout << d[N][N] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}