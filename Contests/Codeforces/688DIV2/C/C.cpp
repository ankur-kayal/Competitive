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



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                char ch;
                cin >> ch;
                a[i][j] = ch - '0';
            }
        }

        vector<int> row_first, row_last, col_first, col_last;
        row_first = vector<int>(10, 1e9);
        row_last = vector<int>(10, 0);
        col_first = vector<int>(10, 1e9);
        col_last = vector<int>(10, 0);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int val = a[i][j];
                row_first[val] = min(row_first[val], i);
                row_last[val] = max(row_last[val], i);
                col_first[val] = min(col_first[val], j);
                col_last[val] = max(col_last[val], j);
            }   
        }
        vector<int> ans(10, 0);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                int val = a[i][j];
                ans[val] = max(ans[val], max(row_last[val] - i, i - row_first[val]) * max(j, n - j - 1));
                ans[val] = max(ans[val], max(col_last[val] - j, j - col_first[val]) * max(i, n - i - 1));
            }
        }
        for(auto u: ans) {
            cout << u << " ";
        }
        cout << '\n';
    }
}