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

    int n,m;
    cin >> n >> m;
    int b[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> b[i][j];
        }
    }
    vector<int> col(m, 0);
    vector<int> row(n, 0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            col[j] += b[i][j];
            row[i] += b[i][j];
        }
    }
    // debug() << imie(row) imie(col);
    int a[n][m];
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(row[i] + col[j] == n + m + 1) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = 0;
            }
        }
    }

    int tmp[n][m];
    memset(tmp, 0, sizeof(tmp));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<n;k++) {
                tmp[i][j] |= a[i][k];
            }
            for(int k=0;k<m;k++) {
                tmp[i][j] |= a[k][j];
            }
        }
    }

    bool ok = true;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(tmp[i][j] != b[i][j]) {
                ok = false;
            }
        }
    }

    if(ok) {
        cout << "YES" << '\n';
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
}