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

const int64_t inf = 1e17;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;
    int n = s.length();
    vector<vector<int64_t>> dp(n, vector<int64_t>(2,inf));
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(int i=1;i<n;i++) {
        char ch = s[i];
        char prev = s[i-1];
        if(ch == '0') {
            if(prev == '0') {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
            else if(prev == '1') {
                dp[i][0] = dp[i-1][1] + y;
                dp[i][1] = dp[i-1][1] + y;
            }
            else {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1] + y);
                dp[i][1] = dp[i][0];
            }
        }
        else if(ch == '1') {
            if(prev == '0') {
                dp[i][0] = dp[i-1][0] + x;
                dp[i][1] = dp[i-1][1] + x;
            }
            else if(prev == '1') {
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i][0];
            }
            else {
                dp[i][1] = min(dp[i-1][1], dp[i-1][0] + x);
                dp[i][0] = dp[i][1];
            }
        }
        else {
            if(prev == '0') {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][0] + x;
            }
            else if(prev == '1') {
                dp[i][0] = dp[i-1][1] + y;
                dp[i][1] = dp[i-1][1];
            }
            else {
                dp[i][0] = min(dp[i-1][1] + y, dp[i-1][0]);
                dp[i][1] = min(dp[i-1][0] + x, dp[i-1][1]);
            }
            
        }
        debug() << imie(dp);
    }

    cout << min(dp[n-1][0], dp[n-1][1]) << '\n';
}       