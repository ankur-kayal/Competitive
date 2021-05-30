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
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;
    
    vector<vector<int64_t>> dp(N + 1, vector<int64_t>(N + 1, -1));
    for(int i=0;i<=N;i++) {
        dp[i][0] = 0;
    }
    for(int pos=1;pos<=N;pos++) {
        for(int count = 1; count <= pos; count++) {
            if(dp[pos - 1][count - 1] != -1) {
                dp[pos][count] = max({dp[pos][count], dp[pos - 1][count - 1] + A[pos - 1]});
            } 
            if(dp[pos - 1][count] != -1) {
                dp[pos][count] = max(dp[pos][count], dp[pos - 1][count]);
            }
        }
    }

    for(auto u: dp) {
        debug() << imie(u);
    }

    int ans = 0;
    for(int i=0;i<=N;i++) {
        if(dp[N][i] >= 0) {
            ans = i;
        }
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}