#include <bits/stdc++.h>
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

//-------------------------- CUSTOM UNORDERED MAP HASH ---------------------------

struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(a + FIXED_RANDOM);
    }
    template<class T> size_t operator()(T a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        return splitmix64(x(a) + FIXED_RANDOM);
    }
    template<class T, class H> size_t operator()(pair<T, H> a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        hash<H> y;
        return splitmix64(x(a.f) * 37 + y(a.s) + FIXED_RANDOM);
    }
};
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;

//----------------------- CUSTOM UNORDERED MAP HASH END--------------------------

int n;
int l,r,u,d;
vector<vector<char>> grid;

bool is_valid(pair<int,int> pt, char move) {
    bool possible = false;
    int x, y;
    tie(x,y) = pt;

    switch(move) {
        case 'L': 
            if(y - 1 >= 1) {
                possible = true;
            }
            break;

        case 'R':
            if(y + 1 <= n) {
                possible = true;
            }
            break;

        case 'D': 
            if(x + 1 <= n) {
                possible = true;
            }
            break;

        case 'U': 
            if(x - 1 >= 1) {
                possible = true;
            }
            break;
    }
    return possible;
}

vector<vector<bool>> marked;

void clear_mark() {
    marked = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));
}

pair<int,int> find_stop(pair<int,int> start) {
    int i,j;
    tie(i, j) = start;
    marked[i][j] = true;

    char move = grid[i][j];
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

void generate_print() {
    clear_mark();
    vector<vector<pair<int,int>>> tc = vector<vector<pair<int,int>>>(n + 1, vector<pair<int,int>>(n + 1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            tc[i][j] = find_stop(mp(i, j));
        }
    }
    cout << n << nl;
    cout << u << " " << l << " " << d << " " << r << nl;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout << tc[i][j].first << " " << tc[i][j].second << " ";
        }
        cout << nl;
    }
}

void run_cases() {
    n = uid(2, 10);

    l = r = d = u = uid(1,100);
    grid = vector<vector<char>>(n + 1, vector<char>(n + 1, '*'));

    vector<char> moves = {'L', 'R', 'U', 'D'};

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            char move = moves[uid(0,3)];
            while(!is_valid(mp(i, j), move)){
                // debug() << "inf";
                move = moves[uid(0,3)];
            }
            // debug() << imie(i) imie(j) imie(move);
            grid[i][j] = move;
        }
    }

    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         cout << grid[i][j];
    //     }
    //     cout << nl;
    // }
    generate_print();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}