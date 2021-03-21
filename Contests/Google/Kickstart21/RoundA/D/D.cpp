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

void run_cases() {
    int n;
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> A[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> B[i][j];
        }
    }

    vector<int> checksum_row(n), checksum_col(n);

    for(int i=0;i<n;i++) {
        cin >> checksum_row[i];
    }

    for(int i=0;i<n;i++) {
        cin >> checksum_col[i];
    }
    // debug() << nl;
    // debug() << imie(A);
    // debug() << imie(B);
    // debug() << imie(checksum_row);
    // debug() << imie(checksum_col);
    // debug() << nl;

    vector<pair<int,int>> row_cnt(n), col_cnt(n);

    int fill = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(A[i][j] == 1) {
                row_cnt[i].first++;
                col_cnt[j].first++;
            }
            if(A[i][j] == -1) {
                row_cnt[i].second++;
                col_cnt[j].second++;
                fill++;
            }
        }
    }

    int64_t ans = 0;

    while(fill > 0) {
        int init_fill = fill;
        for(int row=0;row<n;row++) {
            for(int col=0;col<n;col++) {
                if(A[row][col] == -1) {
                    if(row_cnt[row].second == 1) {
                        fill--;
                        if(checksum_row[row] == 1) {
                            if(row_cnt[row].first % 2 == 0) {
                                A[row][col] = 1;
                                row_cnt[row].first++;
                                row_cnt[row].second--;
                                col_cnt[col].first++;
                                col_cnt[col].second--;

                            }
                            else {
                                A[row][col] = 0;
                                row_cnt[row].second--;
                                col_cnt[col].second--;
                            }
                        }
                        else {
                            if(row_cnt[row].first % 2 == 1) {
                                A[row][col] = 1;
                                row_cnt[row].first++;
                                row_cnt[row].second--;
                                col_cnt[col].first++;
                                col_cnt[col].second--;
                            }
                            else {
                                A[row][col] = 0;
                                row_cnt[row].second--;
                                col_cnt[col].second--;
                            }
                        }
                    }

                    else if(col_cnt[col].second == 1) {
                        fill--;
                        if(checksum_col[col] == 1) {
                            if(col_cnt[col].first % 2 == 0) {
                                A[row][col] = 1;
                                row_cnt[row].first++;
                                row_cnt[row].second--;
                                col_cnt[col].first++;
                                col_cnt[col].second--;

                            }
                            else {
                                A[row][col] = 0;
                                row_cnt[row].second--;
                                col_cnt[col].second--;
                            }
                        }
                        else {
                            if(col_cnt[col].first % 2 == 1) {
                                A[row][col] = 1;
                                row_cnt[row].first++;
                                row_cnt[row].second--;
                                col_cnt[col].first++;
                                col_cnt[col].second--;

                            }
                            else {
                                A[row][col] = 0;
                                row_cnt[row].second--;
                                col_cnt[col].second--;
                            }
                        }
                    }
                }
            }
        }
        // debug() << imie(A);
        // debug() << imie(row_cnt) imie(col_cnt);
        if(init_fill == fill) {
            fill--;
            int row = -1;
            int col = -1;
            int score = 100000;

            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(A[i][j] == -1) {
                        if(B[i][j] < score) {
                            row = i;
                            col = i;
                            score = B[i][j];
                        }
                    }
                }
            }

            if(checksum_row[row] == 1) {
                if(row_cnt[row].first % 2 == 0) {
                    A[row][col] = 1;
                    row_cnt[row].first++;
                    row_cnt[row].second--;
                    col_cnt[col].first++;
                    col_cnt[col].second--;
                }
                else {
                    A[row][col] = 0;
                    row_cnt[row].second--;
                    col_cnt[col].second--;
                }
            }
            else {
                if(row_cnt[row].first % 2 == 1) {
                    A[row][col] = 1;
                    row_cnt[row].first++;
                    row_cnt[row].second--;
                    col_cnt[col].first++;
                    col_cnt[col].second--;
                }
                else {
                    A[row][col] = 0;
                    row_cnt[row].second--;
                    col_cnt[col].second--;
                }
            }

            ans += score;

        }

        // debug() << imie(ans);

    }

    // debug() << nl;
    // debug() << imie(A);
    // debug() << imie(B);
    // debug() << imie(checksum_row);
    // debug() << imie(checksum_col);
    // debug() << nl;

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