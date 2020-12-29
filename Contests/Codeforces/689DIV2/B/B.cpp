#include <bits/stdc++.h>
#include <cstdint>
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        char a[n][m];
        vector<vector<int>> ans(n, vector<int>(m,0));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> a[i][j];
            }
        }
        // continue;
        for(int i=n-1;i>=0;i--) {
            int cnt = 0;
            for(int j=0;j<m;j++) {
                if(a[i][j] == '*') {
                    ans[i][j]++;
                    cnt++;
                    if(cnt >= 3 and i - 1 >= 0 and a[i-1][j-1] == '*') {
                        ans[i-1][j-1] += min({ans[i][j-2], ans[i][j-1], ans[i][j]});
                    }
                }
                else {
                    cnt = 0;
                }
            }
        }
        for(auto u: ans) {
            debug() << imie(u);
        }
        int64_t res = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                res += ans[i][j];
            }
        }
        cout << res << '\n';
    }
}