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

void run_cases() {
    cout << '\n';
    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(2 * r + 1, vector<char>(2 * c + 1));

    for(int row = 0; row < 2 * r + 1; row++) {
        if(row % 2 == 0) {
            for(int col = 0; col < 2 * c + 1; col++) {
                if(col % 2 == 0) {
                    grid[row][col] = '+';
                } else {
                    grid[row][col] = '-';
                }
            }
        } else {
            for(int col = 0; col < 2 * c + 1; col++) {
                if(col % 2 == 0) {
                    grid[row][col] = '|';
                } else {
                    grid[row][col] = '.';
                }
            }
        }
    }

    grid[0][0] = '.';
    grid[0][1] = '.';
    grid[1][0] = '.';

    for(auto u: grid) {
        for(auto v: u) {
            cout << v;
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ":";
        run_cases();
    }
}