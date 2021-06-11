#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int Q;
    cin >> Q;

    const int maxN = 3e5+10;
    const int logN = 19;

    int up[maxN][logN];
    for(int i = 0; i < maxN; i++) {
        for(int j = 0; j < logN; j++) {
            up[i][j] = -1;
        }
    }

    vector<int64_t> gold(maxN), cost(maxN);
    vector<int> parent(maxN, -1);

    cin >> gold[0] >> cost[0];

    // k is 1 indexed!!
    auto find_kth_ancestor = [&](int n, int k) -> int {
        for(int i = logN - 1; i >= 0; i--) {
            if((1 << i) <= k) {
                n = up[n][i];
                k -= (1 << i);
            }
        }
        return n;
    };

    auto process = [&](int n) -> void {
        up[n][0] = parent[n];
        for(int i = 1; i < logN; i++) {
            if(up[n][i - 1] != -1) {
                up[n][i] = up[up[n][i - 1]][i - 1];
            } else {
                break;
            }
        }
    };

    for(int i = 1; i <= Q; i++) {
        int ch;
        cin >> ch;
        if(ch == 1) {
            int p, a, c;
            cin >> p >> a >> c;
            parent[i] = p;
            cost[i] = c;
            gold[i] = a;

            process(i);

        } else {
            int64_t v, w;
            cin >> v >> w;

            int start = v;
            int dist = 0;
            int64_t money = 0, got_gold = 0;


            for(int i = logN - 1; i >= 0; i--) {
                if(up[start][i] != -1 && gold[up[start][i]] != 0) {
                    start = up[start][i];
                    dist += 1 << i;
                }
            }

            for(int i = dist; i >= 0; i--) {
                int ancestor = find_kth_ancestor(v, i);
                int64_t can_have = min(w, gold[ancestor]);
                got_gold += can_have;
                money += can_have * cost[ancestor];
                w -= can_have;
                gold[ancestor] -= can_have;
                if(w == 0) {
                    break;
                }
            }

            cout << got_gold << " " << money << '\n' << flush;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}