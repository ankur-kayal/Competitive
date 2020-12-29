#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
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
        int n;
        cin >> n;
        char a[n][n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin >> a[i][j];
            }
        }

        char ans[3][n][n];

        vector<pair<int,int>> cnt = {{0,0}, {0,1}, {0,2}};
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ans[0][i][j] = ans[1][i][j] = ans[2][i][j] = a[i][j];
                int parity = (i + j) % 3;
                if(a[i][j] == 'X') {
                    cnt[parity].first++;
                    ans[parity][i][j] = 'O';
                }
            }
        }

        sort(cnt.begin(), cnt.end());
        int parity = cnt[0].second;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout << ans[parity][i][j];
            }
            cout << '\n';
        }
    }
}