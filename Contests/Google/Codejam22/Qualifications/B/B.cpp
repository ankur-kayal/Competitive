#include <bits/stdc++.h>
#include <numeric>
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
    vector<vector<int>> colors(3, vector<int>(4));

    for(auto &u: colors) {
        for(auto &v: u)
            cin >> v;
    }

    vector<int> D = colors[0];

    for(int i = 1; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            D[j] = min(D[j], colors[i][j]);
        }
    }


    if(accumulate(D.begin(), D.end(), 0) < 1000000) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        int extra = accumulate(D.begin(), D.end(), 0) - 1000000;

        for(auto &u: D) {
            int toRemove = min(extra, u);
            u -= toRemove;
            extra -= toRemove;
        }


        for(auto u: D) {
            cout << u << " ";
        }
        cout << '\n';
    }
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