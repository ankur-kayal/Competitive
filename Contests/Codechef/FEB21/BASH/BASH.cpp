#include <bits/stdc++.h>
#include <ios>
using namespace std;

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define nl '\n'

//----------------------------------- END DEFINES -------------------------------- 

/*
Ideas: 

30 pts: 
DFS ?
1. Find the cycles repeatedly
2. Fill the remaining cells as required as they won't be in a cycle

100 pts:
Weighted DFS ?
deciding which direction to explore first depending on the weights of the moves? 
using sets to decide priority of the moves

*/

int n;
int64_t PU, PL, PD, PR;

vector<pair<int64_t, char>> priority;

pair<int,int> start;
pair<int,int> outside = {-1, -1};
vector<vector<char>> ans;
vector<vector<pair<int,int>>> grid;
vector<vector<bool>> marked;

pair<int,int> surround(pair<int,int> p, char direction) {
    pair<int,int> result = {-1, -1};
    int x, y;
    tie(x,y) = p;

    switch(direction) {
        case 'L': 
            if(y - 1 > 0) {
                result = mp(x, y - 1);
            }
            break;

        case 'R':
            if(y + 1 <= n) {
                result = mp(x, y + 1);
            }
            break;

        case 'D': 
            if(x + 1 <= n) {
                result = mp(x + 1, y);
            }
            break;

        case 'U': 
            if(x - 1 > 0) {
                result = mp(x - 1, y);
            }
            break;
    }
    return result;
}

void find_cycles(pair<int,int> p) {
    int x, y;
    tie(x,y) = p;
    marked[x][y] = true;
    pair<int,int> tmp1, tmp2, tmp3, tmp4;
    bool processed = false;

    tmp1 = surround(p, priority[0].second);
    int i,j;
    tie(i, j) = tmp1;
    if(tmp1 != outside and grid[i][j] == mp(i, j) and !marked[i][j]) {
        ans[x][y] = priority[0].second;
        processed = true;
        find_cycles(tmp1);
    }

    if(processed) {
        return;
    }
    tmp2 = surround(p, priority[1].second);
    tie(i, j) = tmp2;
    if(tmp2 != outside and grid[i][j] == mp(i, j) and !marked[i][j]) {
        ans[x][y] = priority[1].second;
        processed = true;
        find_cycles(tmp2);
    }

    if(processed) {
        return;
    }
    tmp3 = surround(p, priority[2].second);
    tie(i, j) = tmp3;
    if(tmp3 != outside and grid[i][j] == mp(i, j) and !marked[i][j]) {
        ans[x][y] = priority[2].second;
        processed = true;
        find_cycles(tmp3);
    }

    if(processed) {
        return;
    }
    tmp4 = surround(p, priority[3].second);
    tie(i, j) = tmp4;
    if(tmp4 != outside and grid[i][j] == mp(i, j) and !marked[i][j]) {
        ans[x][y] = priority[3].second;
        processed = true;
        find_cycles(tmp4);
    }

    if(!processed) {
        if(tmp1 == start) {
            ans[x][y] = priority[0].second;
        }
        else if(tmp2 == start) {
            ans[x][y] = priority[1].second;
        }
        else if(tmp3 == start) {
            ans[x][y] = priority[2].second;
        }
        else if(tmp4 == start) {
            ans[x][y] = priority[3].second;
        }
    }
}

void place_others(pair<int,int> p) {
    int x, y;
    tie(x,y) = p;
    marked[x][y] = true;
    pair<int,int> tmp1, tmp2, tmp3, tmp4;
    bool processed = false;

    tmp1 = surround(p, priority[0].second);
    int i,j;
    tie(i, j) = tmp1;
    if(tmp1 != outside and grid[i][j] == start and !marked[i][j]) {
        ans[x][y] = priority[0].second;
        processed = true;
        // if(tmp1 != start)
            place_others(tmp1);
    }

    if(processed) {
        return;
    }
    tmp2 = surround(p, priority[1].second);
    tie(i, j) = tmp2;
    if(tmp2 != outside and grid[i][j] == start and !marked[i][j]) {
        ans[x][y] = priority[1].second;
        processed = true;
        // if(tmp2 != start)
            place_others(tmp2);
    }

    if(processed) {
        return;
    }
    tmp3 = surround(p, priority[2].second);
    tie(i, j) = tmp3;
    if(tmp3 != outside and grid[i][j] == start and !marked[i][j]) {
        ans[x][y] = priority[2].second;
        processed = true;
        // if(tmp3 != start)
            place_others(tmp3);
    }

    if(processed) {
        return;
    }
    tmp4 = surround(p, priority[3].second);
    tie(i, j) = tmp4;
    if(tmp4 != outside and grid[i][j] == start and !marked[i][j]) {
        ans[x][y] = priority[3].second;
        processed = true;
        // if(tmp4 != start)
            place_others(tmp4);
    }

    // debug() << imie(p) imie(tmp1) imie(tmp2) imie(tmp3) imie(tmp4) imie(start);
    if(!processed) {
        if(tmp1 == start) {
            ans[x][y] = priority[0].second;
        }
        else if(tmp2 == start) {
            ans[x][y] = priority[1].second;
        }
        else if(tmp3 == start) {
            ans[x][y] = priority[2].second;
        }
        else if(tmp4 == start) {
            ans[x][y] = priority[3].second;
        }
    }
}

// vector<vector<bool>> marked;

void clear_mark() {
    marked = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
}

pair<int,int> find_stop(pair<int,int> start) {
    int i,j;
    tie(i, j) = start;
    marked[i][j] = true;

    char move = ans[i][j];
    if(move == 'L') {
        if(marked[i][j-1]) {
            return mp(i, j - 1);
        }
        else {
            return find_stop(mp(i, j - 1));
        }
    }
    if(move == 'R') {
        if(marked[i][j+1]) {
            return mp(i, j + 1);
        }
        else {
            return find_stop(mp(i, j + 1));
        }
    }
    if(move == 'U') {
        if(marked[i - 1][j]) {
            return mp(i - 1, j);
        }
        else {
            return find_stop(mp(i - 1, j));
        }
    }
    if(move == 'D') {
        if(marked[i + 1][j]) {
            return mp(i + 1, j);
        }
        else {
            return find_stop(mp(i + 1, j));
        }
    }
}

void validate() {
    clear_mark();
    vector<vector<pair<int,int>>> tc = vector<vector<pair<int,int>>>(n + 1, vector<pair<int,int>>(n + 1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            clear_mark();
            tc[i][j] = find_stop(mp(i, j));
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            debug() << imie(tc[i][j]) imie(grid[i][j]);
            assert(tc[i][j] == grid[i][j]);
        }
    }
}

void calculate_print() {
    int64_t cost = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(ans[i][j] == 'L') cost += PL;
            if(ans[i][j] == 'R') cost += PR;
            if(ans[i][j] == 'U') cost += PU;
            if(ans[i][j] == 'D') cost += PD;
            if(ans[i][j] == '*') {
                cout << -1 << nl;
                exit(0);
            }
        }
    }

    validate();
    // assert(cost == n * n * PU);

    cout << cost << nl;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout << ans[i][j];
        }
        cout << nl;
    }
}


void run_cases() {

    cin >> n;
    ans = vector<vector<char>>(n + 1, vector<char>(n + 1, '*'));

    cin >> PU >> PL >> PD >> PR;
    priority = {{PU, 'U'}, {PL, 'L'}, {PD, 'D'}, {PR, 'R'}};
    sort(all(priority));
    // debug() << imie(priority);

    grid = vector<vector<pair<int,int>>>(n + 1, vector<pair<int,int>>(n + 1));
    marked = vector<vector<bool>>(n + 1, vector<bool>(n + 1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int x,y;
            cin >> x >> y;
            grid[i][j] = {x, y};
        }
    }
    // debug() << imie(grid);

    // First find all cycles 

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(!marked[i][j] and grid[i][j] == mp(i, j)) {
                start = mp(i, j);
                find_cycles(start);
            }
        }
    }
    // cout << boolalpha;
    // calculate_print();
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout << marked[i][j] << " ";
    //     }
    //     cout << nl;
    // }
    // place the remaining characters accordingly

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(!marked[i][j]) {
                // debug();
                start = grid[i][j];
                place_others({i, j});
            }
        }
    }

    calculate_print();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}