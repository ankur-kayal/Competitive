#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

const int INF = 1e9 + 7;
const int64_t INF64 = 1e18;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<int64_t>> bfs(vector<vector<int64_t>> &grid, pair<int,int> source) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int64_t>> distance(n, vector<int64_t>(m, INF));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    auto is_valid = [&](int x, int y) -> bool {
        if(x < 0 || x >= n || y < 0 || y >= m) return false;
        if(grid[x][y] == -1) return false;
        return !vis[x][y];
    };

    int source_x, source_y;
    tie(source_x, source_y) = source;

    vector<pair<int,int>> q;
    q.push_back(source);
    distance[source_x][source_y] = 0;
    vis[source_x][source_y] = true;
    for(int i=0;i<q.size();i++) {
        auto [x, y] = q[i];
        
        for(int j=0;j<4;j++) {
            int new_x = x + dx[j];
            int new_y = y + dy[j];
            if(is_valid(new_x, new_y)) {
                vis[new_x][new_y] = true;
                q.push_back({new_x, new_y});
                distance[new_x][new_y] = distance[x][y] + 1;
            }
        }
    }

    return distance;
}

void run_cases() {
    int64_t n, m, w;
    cin >> n >> m >> w;
    vector<vector<int64_t>> grid(n, vector<int64_t>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int64_t>> distance_from_source = bfs(grid, {0, 0});
    vector<vector<int64_t>> distance_from_destination = bfs(grid, {n-1, m-1});

    

    int64_t ans = distance_from_source[n-1][m-1] < INF ? distance_from_source[n-1][m-1] * w : INF64;

    int64_t source_portal = INF64;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] >= 1 and distance_from_source[i][j] != INF) {
                source_portal = min(source_portal, distance_from_source[i][j] * w + grid[i][j]);
            }
        }
    }

    int64_t destination_portal = INF64;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] >= 1 and distance_from_destination[i][j] != INF) {
                destination_portal = min(destination_portal, distance_from_destination[i][j] * w + grid[i][j]);
            }
        }
    }

    ans = min(ans, destination_portal + source_portal);

    cout << (ans < INF64 ? ans : -1);

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}