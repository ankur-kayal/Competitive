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
    string s;
    cin >> s;
    int N = s.length();
    vector<vector<int64_t>> dp(N, vector<int64_t>(2, 0));

    // dp states: number of unstable strings ending at i
    // .....10

    if(s[0] == '1') {
        dp[0][1] = 1;
    } else if(s[0] == '0') {
        dp[0][0] = 1;
    } else {
        dp[0][1] = 1;
        dp[0][0] = 1;
    }

    for(int i = 1; i < N; i++) {
        if(s[i] == '1') {
            dp[i][1] = dp[i - 1][0] + 1;
        } else if(s[i] == '0') {
            dp[i][0] = dp[i - 1][1] + 1;
        } else {
            dp[i][0] = dp[i - 1][1] + 1;
            dp[i][1] = dp[i - 1][0] + 1;
        }
    }

    debug() << imie(dp);

    int64_t ans = 0;

    int64_t questions = 0;
    for(int i = 0; i < N; i++) {
        if(s[i] == '?') {
            questions++;
        } else {
            ans -= questions * (questions + 1) / 2;
            questions = 0;
        }
        for(int j = 0; j < 2; j++) {
            ans += dp[i][j];
        }
    }

    ans -= questions * (questions + 1) / 2;
    questions = 0;

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