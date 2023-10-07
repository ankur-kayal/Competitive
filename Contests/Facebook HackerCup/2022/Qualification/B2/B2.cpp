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


void run_cases() {
    int R, C;
    cin >> R >> C;

    vector<vector<char>> grid(R, vector<char>(C));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> grid[i][j];
        }
    }

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    auto calculate_neighbours = [&](int r, int c) {
        int neighbours = 0;
        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(min(nr, nc) >= 0 && nr < R && nc < C && grid[nr][nc] == '^') {
                neighbours++;
            }
        }
        return neighbours;
    };

    auto valid = [&]() {
        int min_neighbours = 4;

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(grid[i][j] == '^')
                    min_neighbours = min(min_neighbours, calculate_neighbours(i, j));
            }
        }

        return min_neighbours >= 2;
    };

    if(valid()) {
        cout << "Possible" << '\n';

        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
        return;
    }

    // all correct upto this
    vector<vector<int>> marked(R, vector<int>(C));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] == '^') {
                marked[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(grid[i][j] == '.')
                grid[i][j] = '^';
        }
    }

    // remove all invalid trees incrementally

    queue<pair<int,int>> trees;
    vector<vector<int>> neighbours(R, vector<int>(C));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            neighbours[i][j] = calculate_neighbours(i, j);
        }
    }

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(neighbours[i][j] < 2 && grid[i][j] == '^' && !marked[i][j]) {
                trees.emplace(i, j);
            }
        }
    }

    while(!trees.empty()) {
        auto [r, c] = trees.front();
        trees.pop();

        if(calculate_neighbours(r, c) != neighbours[r][c]) {
            continue;
        }

        grid[r][c] = '.';

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(min(nr, nc) >= 0 && nr < R && nc < C && grid[nr][nc] == '^') {
                neighbours[nr][nc]--;
                if(neighbours[nr][nc] < 2 && !marked[nr][nc]) {
                    trees.push({nr, nc});
                }
            }
        }
    }



    if(!valid()) {
        cout << "Impossible" << '\n';
        return;
    }

    cout << "Possible" << '\n';

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("b2_validation_input.txt", "r", stdin);
    // freopen("b2_validation_output.txt", "w", stdout);

    /*For final submit*/
    freopen("b2_final_input.txt", "r", stdin);
    freopen("b2_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}