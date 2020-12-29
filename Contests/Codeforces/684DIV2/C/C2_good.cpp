#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5555;

char saveori[maxn][maxn];
struct node {
    int x1, y1, x2, y2, x3, y3;
};
inline void fun(char& x) {
    x = '0' + (1 ^ (x - '0'));
}
vector<node>ans;
void solve() {
    int n, m;
    cin >> n >> m;
    ans.clear();
    for (int i = 1; i <= n; i++) {
        scanf("%s", saveori[i] + 1);
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (saveori[i][j] == '1') {
                ans.push_back({ i, j, i , j + 1, i + 1, j + 1 });
                fun(saveori[i][j]);
                fun(saveori[i][j + 1]);
                fun(saveori[i + 1][j + 1]);
            }
        }

        if (saveori[i][m - 1] == saveori[i][m]) {
            if (saveori[i][m] == '1') {
                ans.push_back({ i,m - 1, i , m, i + 1, m });
                fun(saveori[i][m - 1]);
                fun(saveori[i][m]);
                fun(saveori[i + 1][m]);
            }
        }
        else {
            if (saveori[i][m - 1] == '1') {
                ans.push_back({ i,m - 1, i + 1 , m - 1, i + 1, m });
                fun(saveori[i][m - 1]);
                fun(saveori[i + 1][m - 1]);
                fun(saveori[i + 1][m]);
            }
            else {
                ans.push_back({ i, m, i + 1, m - 1, i + 1, m});
                fun(saveori[i][m]);
                fun(saveori[i + 1][m - 1]);
                fun(saveori[i + 1][m]);
            }
        }
    }

    for (int j = 1; j < m; j++) {
        if (saveori[n - 1][j] == saveori[n][j]) {
            if (saveori[n][j] == '1') {
                ans.push_back({ n, j, n - 1, j, n, j + 1 });
                fun(saveori[n][j]);
                fun(saveori[n - 1][j]);
                fun(saveori[n][j + 1]);
            }
        }
        else {
            if (saveori[n][j] == '1') {
                ans.push_back({ n, j, n - 1, j + 1, n, j + 1 });
                fun(saveori[n][j]);
                fun(saveori[n - 1][j + 1]);
                fun(saveori[n][j + 1]);
            }
            else {
                ans.push_back({ n - 1, j, n - 1, j + 1, n, j + 1 });
                fun(saveori[n - 1][j]);
                fun(saveori[n - 1][j + 1]);
                fun(saveori[n][j + 1]);
            }
        }
    }
    if (saveori[n][m] == saveori[n - 1][m]) {
        if (saveori[n][m] == '1') {
            ans.push_back({ n, m, n, m - 1, n - 1, m - 1 });
            ans.push_back({ n - 1, m, n - 1, m - 1, n, m - 1 });
            fun(saveori[n][m]);
            fun(saveori[n][m - 1]);
            fun(saveori[n - 1][m - 1]);
            fun(saveori[n - 1][m]);
            fun(saveori[n - 1][m - 1]);
            fun(saveori[n][m - 1]);
        }
    }
    else {
        if (saveori[n][m] == '1') {
            ans.push_back({ n, m, n, m - 1, n - 1,m });
            ans.push_back({ n, m, n, m - 1, n - 1, m - 1 });
            ans.push_back({ n, m, n - 1, m, n - 1, m - 1 });
        }
        else {
            ans.push_back({ n - 1, m, n - 1, m - 1, n, m });
            ans.push_back({ n - 1, m, n - 1, m - 1, n ,m - 1 });
            ans.push_back({ n - 1, m, n, m, n, m - 1 });
        }
    }

    printf("%d\n", ans.size());
    for (node o : ans) {
        printf("%d %d %d %d %d %d\n", o.x1, o.y1, o.x2, o.y2, o.x3, o.y3);
    }
}

signed main() {
    //freopen("in.txt", "r", stdin);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
