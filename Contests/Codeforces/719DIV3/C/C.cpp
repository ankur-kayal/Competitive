#include <bits/stdc++.h>
using namespace std;


#define nl '\n'

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void run_cases() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> cells(2 * n);
    vector<int> cell_count(2 * n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cells[i + j].push_back(make_pair(i, j));
            cell_count[i + j]++;
        }
    }
    vector<vector<int>> ans(n, vector<int>(n));
    int val = 1;
    while(val <= n * n) {
        int ind = -1;
        int cnt = 0;
        for(int i=0;i<2 * n;i++) {
            if(cell_count[i] >= cnt) {
                ind = i;
                cnt = cell_count[i];
            }
        }
        cell_count[ind] = 0;
        for(auto u: cells[ind]) {
            ans[u.first][u.second] = val;
            val++;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i - 1 >= 0) {
                if(abs(ans[i-1][j] - ans[i][j]) == 1) {
                    cout << -1 << '\n';
                    return;
                }
            }
            if(i + 1 < n) {
                if(abs(ans[i+1][j] - ans[i][j]) == 1) {
                    cout << -1 << '\n';
                    return;
                }
            }
            if(j - 1 >= 0) {
                if(abs(ans[i][j-1] - ans[i][j]) == 1) {
                    cout << -1 << '\n';
                    return;
                }
            }
            if(j + 1 < n) {
                if(abs(ans[i][j+1] - ans[i][j]) == 1) {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }

    for(auto u: ans) {
        output_vector(u);
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