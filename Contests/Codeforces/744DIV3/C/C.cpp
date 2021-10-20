#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> grid(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m));


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '*') {
                vector<pair<int,int>> left_diagonal;
                int x = i, y = j;

                while(x > 0 && y > 0) {
                    --x, --y;
                    if(grid[x][y] == '*') {
                        left_diagonal.emplace_back(x, y);
                    } else {
                        break;
                    }
                }

                vector<pair<int,int>> right_diagonal;
                x = i, y = j;

                while(x > 0 && y < m - 1) {
                    --x, ++y;
                    if(grid[x][y] == '*') {
                        right_diagonal.emplace_back(x, y);
                    } else {
                        break;
                    }
                }

                int tick_length = min(right_diagonal.size(), left_diagonal.size());

                if(tick_length >= k) {
                    vis[i][j] = true;
                    for(int e = 0; e < tick_length; e++) {
                        vis[right_diagonal[e].first][right_diagonal[e].second] = true;
                        vis[left_diagonal[e].first][left_diagonal[e].second] = true;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == '*' && !vis[i][j]) {
                cout << "NO\n";
                return;
            } 
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}