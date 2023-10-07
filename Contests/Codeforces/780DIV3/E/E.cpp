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

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;

    int ones = 0;
    int ans = N * N;

    vector<vector<char>> grid(N, vector<char>(N));
    for(auto &u: grid) {
        for(auto &v: u) {
            cin >> v;
            if(v == '1') {
                ones++;
            }
        }
    }

    auto index = [&](int i) {
        return (i % N);
    };

    for(int j = 0; j < N; j++) {
        int diagonal = 0;
        for(int i = 0; i < N; i++) {
            if(grid[index(i)][index(j + i)] == '1') {
                diagonal++;
            }
        }

        debug() << imie(diagonal);

        ans = min(ans, N - diagonal + ones - diagonal);
    }

    cout << ans << '\n';

    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}