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
#define Stringize( L )     #L 
#define MakeString( M, L ) M(L)
#define Reminder __FILE__ "("  ") : Warning: "

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
        return splitmix64(x(a.first) * 37 + y(a.second) + FIXED_RANDOM);
    }
};
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;

//----------------------- CUSTOM UNORDERED MAP HASH END--------------------------

int64_t compute(int64_t a, int64_t b) {
    // debug() << imie(a) imie(b);
    int64_t mini = min(a, b);
    int64_t maxi = max(a, b);

    int64_t ans = min(a, b / 2) + min(b, a / 2);
    if(a >= 2) {
        ans--;
    }
    if(b >= 2) {
        ans--;
    }
    return ans;
}

void run_cases() {
    int r,c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            cin >> grid[i][j];
        }
    }

    int64_t ans = 0;

    vector<vector<int>> forward_row(r, vector<int>(c));

    for(int i=r-1;i>=0;i--) {
        for(int j=c-1;j>=0;j--) {
            if(j == c-1) {
                forward_row[i][j] = grid[i][j];
            }
            else {
                if(grid[i][j] == 0) {
                    forward_row[i][j] = 0;
                }
                else {
                    forward_row[i][j] = 1 + forward_row[i][j + 1];
                }
            }
        }
    }

    vector<vector<int>> backward_row(r, vector<int>(c));

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(j == 0) {
                backward_row[i][j] = grid[i][j];
            }
            else {
                if(grid[i][j] == 0) {
                    backward_row[i][j] = 0;
                }
                else {
                    backward_row[i][j] = 1 + backward_row[i][j - 1];
                }
            }
        }
    }

    vector<vector<int>> upward_col(r, vector<int>(c));

    for(int j=0;j<c;j++) {
        for(int i=0;i<r;i++) {
            if(i == 0) {
                upward_col[i][j] = grid[i][j];
            }
            else {
                if(grid[i][j] == 0) {
                    upward_col[i][j] = 0;
                }
                else {
                    upward_col[i][j] = 1 + upward_col[i-1][j];
                }
            }
        }
    }

    vector<vector<int>> downward_col(r, vector<int>(c));

    for(int j=0;j<c;j++) {
        for(int i=r-1;i>=0;i--) {
            if(i == r-1) {
                downward_col[i][j] = grid[i][j];
            }
            else {
                if(grid[i][j] == 0) {
                    downward_col[i][j] = 0;
                }
                else {
                    downward_col[i][j] = 1 + downward_col[i+1][j];
                }
            }
        }
    }
    // debug() << nl;
    // debug() << imie(forward_row);
    // debug() << imie(backward_row);
    // debug() << imie(upward_col);
    // debug() << imie(downward_col);

    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(forward_row[i][j] != 1) {
                if(upward_col[i][j] != 1)
                    ans += compute(forward_row[i][j], upward_col[i][j]);
                if(downward_col[i][j] != 1)
                    ans += compute(forward_row[i][j], downward_col[i][j]);
            }
            if(backward_row[i][j] != 1) {
                if(upward_col[i][j] != 1)
                    ans += compute(backward_row[i][j], upward_col[i][j]);
                if(downward_col[i][j] != 1)
                    ans += compute(backward_row[i][j], downward_col[i][j]);
            }
            
        }
    }

    cout << ans << nl;

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