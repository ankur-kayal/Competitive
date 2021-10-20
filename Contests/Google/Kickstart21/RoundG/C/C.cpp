#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int INF = 1e9 + 7;

void run_cases() {
    int N, K;
    cin >> N >> K;

    vector<int> B(N);
    for(auto &u: B) {
        cin >> u;
    }

    if(accumulate(B.begin(), B.end(), 0LL) < K) {
        cout << -1 << '\n';
        return;
    }

    vector<vector<pair<int,int>>> segments(K + 1);

    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        for(int j = i; j < N; j++) {
            sum += B[j];
            if(sum <= K) {
                segments[sum].emplace_back(i, j - i + 1);
            } else {
                break;
            }
        }
    }

    

    for(int i = 0; i <= K; i++) {
        for(int j = int(segments[i].size()) - 2; j >= 0; j--) {
            segments[i][j].second = min(segments[i][j].second, segments[i][j + 1].second);
        }
    }

    int cost = INF;
    for(auto segment: segments[K]) {
        cost = min(cost, segment.second);
        break;
    }

    if(cost == 1) {
        cout << 1 << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        int64_t sum = 0;
        for(int j = i; j < N; j++) {
            sum += B[j];
            int need = K - sum;
            if(need < 0) {
                break;
            }


            int l = -1, r = segments[need].size();

            while(r > l + 1) {
                int m = (l + r) / 2;
                if(segments[need][m].first <= j) {
                    l = m;
                } else {
                    r = m;
                }
            }

            if(r < segments[need].size()) {
                cost = min(cost, j - i + 1 + segments[need][r].second);
            }
        }
        if(cost == 2) {
            break;
        }
    }

    if(cost == INF) {
        cost = -1;
    }

    cout << cost << '\n';
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