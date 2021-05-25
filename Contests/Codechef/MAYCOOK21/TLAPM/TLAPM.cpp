#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000;

vector<vector<int64_t>> vals(maxN, vector<int64_t>(maxN));

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    vector<pair<int,pair<int,int>>> order;

    for(int i=0;i<maxN;i++) {
        for(int j=0;j<maxN;j++) {
            order.push_back({i + j, {i, j}});
        }
    }
    sort(order.begin(), order.end());

    for(int64_t i=0;i<order.size();i++) {
        vals[order[i].second.first][order[i].second.second] = i + 1;
    }

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;

        int64_t ans = 0;

        for(int i=x1;i<=x2;i++) {
            ans += vals[i][y1];
            // cerr << vals[i][y1] << endl;
        }

        for(int j=y1+1;j<=y2;j++) {
            ans += vals[x2][j];
            // cerr << vals[x2][j] << endl;
        }

        cout << ans << '\n';
    }
}