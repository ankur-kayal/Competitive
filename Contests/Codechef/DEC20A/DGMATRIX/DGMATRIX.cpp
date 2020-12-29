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

vector<vector<int>> a,b;
bool solved;
int n;

bool verify(int i, int j) {

    bool ok =  a[i - 1][j - 1] == b[i][j] + b[i-1][j] + b[i][j-1] + b[i-1][j-1];
    debug() << imie(i) imie(j) imie(a[i-1][j-1]) imie(b[i][j]) imie(ok);
    return ok;
}

void recurse(int i, int j) {
    // cerr << i << " " << j << '\n';
    if(i == 0 or j == 0) {
        int start = 0;
        if(i < n and j < n) {
            start = max(0, a[i][j] - 27);
        }
        // debug() << imie(start);
        for(int val=start;val <= 9;val++) {
            if(solved) {
                return;
            }
            b[i][j] = val;
            if(j + 1 <= n) {
                recurse(i, j + 1);
            } 
            else if(i + 1 <= n) {
                // cerr << "bug" << '\n'
                recurse(i + 1, 0);
            }
        }
    }
    else {
        b[i][j] = a[i-1][j-1] - b[i-1][j] - b[i][j-1] - b[i-1][j-1];
        bool ok = (b[i][j] <= 9 and b[i][j] >= 0);
        // debug() << imie(ok) imie(b[i][j]) imie(a[i-1][j-1]) imie(b[i-1][j]) imie(b[i][j-1]) imie(b[i-1][j-1]);
        if(i == n and j == n and ok) {
            solved = true;
            return;
        }
        else if(ok) {
            if(j + 1 <= n) {
                recurse(i, j + 1);
            }
            else if(i + 1<= n) {
                recurse(i + 1, 0);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    a = vector<vector<int>>(n, vector<int>(n));
    b = vector<vector<int>>(n + 1, vector<int>(n + 1));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> a[i][j];
        }
    }
    recurse(0,0);
    debug() << imie(b);
    assert(solved == true);

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++) {
            cout << b[i][j];
        }
        cout << '\n';
    }
}