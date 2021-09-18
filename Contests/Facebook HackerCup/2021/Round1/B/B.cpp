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
    int N, M, A, B;
    cin >> N >> M >> A >> B;

    int buffer = N + M - 2;

    vector<vector<int>> grid(N, vector<int>(M, 1000));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(i == 0 || j == 0 || i == N - 1 || j == M - 1) {
                grid[i][j] = 1;
            }
        }
    }

    A -= buffer;
    B -= buffer;

    if(A <= 0 || B <= 0) {
        cout << "Impossible" << '\n';
        return;
    }
 
    cout << "Possible" << '\n';

    for(int i = 1; i < M - 1; i++) {
        grid[N - 1][i] = 1000;
    }

    grid[N - 1][M - 1] = A;
    grid[N - 1][0] = B;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("b_validation_input.txt", "r", stdin);
    // freopen("b_validation_output.txt", "w", stdout);

    /*For final submit*/
    freopen("b_final_input.txt", "r", stdin);
    freopen("b_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}