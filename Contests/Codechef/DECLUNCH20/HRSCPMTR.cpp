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
        int n,m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> b(n, vector<int>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                b[i][j] = a[i][m - j - 1];
            }
        }
        // debug() << "a";
        // for(auto u: a) {
        //     debug() << imie(u);
        // }

        // debug() << "b";
        // for(auto u: b) {
        //     debug() << imie(u);
        // }

        vector<map<int,int>> diag(n + m - 1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                diag[(i + j)][b[i][j]]++;
            }
        }
        // for(int i=0;i<n+m-1;i++) {
        //     debug() << imie(i) imie(diag[i]);
        // }

        set<int> cnt;
        for(int i=0;i<n + m - 1;i++) {
            if(diag[i].size() == 1) {
                cnt.insert(i);
            }
        }

        // debug() << imie(cnt);

        int q;
        cin >> q;
        while(q--) {
            int x,y,v;
            cin >> x >> y >> v;
            --x,--y;
            y = m - y - 1;
            if(cnt.count(x + y))
                cnt.erase(cnt.find(x + y));
            diag[(x + y)][b[x][y]]--;
            if(diag[(x + y)][b[x][y]] == 0) {
                diag[(x + y)].erase(b[x][y]);
            }
            b[x][y] = v;
            diag[(x + y)][b[x][y]]++;
            if(diag[(x + y)].size() == 1) {
                cnt.insert(x + y);
            }

            if(cnt.size() == n + m - 1) {
                cout << "Yes" << '\n';
            }
            else {
                cout << "No" << '\n';
            }
        }
    }
}