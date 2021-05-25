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
void run_cases() {
    int n;
    cin >> n;
    vector<int> occupied, not_occupied;
    for(int i=1;i<=n;i++) {
        int c;
        cin >> c;
        if(c == 1)
            occupied.push_back(i);
        else
            not_occupied.push_back(i);
    }
    if (occupied.empty()) {
        cout << 0 << '\n';
        return;
    }
 
    vector<int> dp(not_occupied.size());
    for (int i = 0; i < not_occupied.size(); ++i) {
        dp[i] = abs(not_occupied[i] - occupied[0]);
    }
    for (int i = 1; i < occupied.size(); ++i) {
        for (int j = 1; j < dp.size(); ++j)
            dp[j] = min(dp[j], dp[j - 1]);
        for (int j = int(dp.size()) - 1; j >= 1; --j) {
            dp[j] = dp[j - 1] + abs(occupied[i] - not_occupied[j]);
        }
        dp[0] = INF;
    }
    cout << *min_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}