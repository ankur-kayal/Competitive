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
    string s;
    cin >> s;

    int N = s.length();

    vector<deque<int>> positions(26);
    for(int i = 0; i < s.length(); i++) {
        positions[s[i] - 'a'].push_back(i);
    }

    const int INF = 1e9 + 7;

    vector<int> dp(N + 1, INF);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 0; i < N; i++) {
        positions[s[i] - 'a'].pop_front();
        if(!positions[s[i] - 'a'].empty()) {
            dp[positions[s[i] - 'a'].front() + 1] = min(dp[positions[s[i] - 'a'].front() + 1], dp[i] + positions[s[i] - 'a'].front() - i - 1);
        }

        dp[i + 1] = min(dp[i] + 1, dp[i + 1]);
    }

    int ans = INF;
    for(int i = 0; i <= N; i++) {
        ans = min(ans, dp[i] + N - i);
    }

    debug() << imie(dp);

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