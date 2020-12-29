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

char a[1001][1001];
int vis[1001][1001];
int ans;
int n,m;

pair<int,int> finish;

vector<char> path;
vector<char> shortest;
int length = 1e9;

void minify() {
    if()
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    debug() << imie(x) imie(y);
    if(finish == make_pair(x,y)) {
        minify();
        return;
    }
    if(a[x][y] == '#') {
        return;
    }
    if(x + 1 <= n and vis[x + 1][y] == 0) {
        path.push_back('D');
        dfs(x + 1, y);
        path.pop_back();
    }
    if(y + 1 <= m and vis[x][y + 1] == 0) {
        path.push_back('R');
        dfs(x, y + 1);
        path.pop_back();
    }
    if(x - 1 >= 1 and vis[x - 1][y] == 0) {
        path.push_back('U');
        dfs(x - 1, y);
        path.pop_back();
    }
    if(y - 1 >= 1 and vis[x][y - 1] == 0) {
        path.push_back('L');
        dfs(x, y - 1);
        path.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> a[i][j];
        }
    }

    pair<int,int> start;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i][j] == 'A') {
                start = {i, j};
            }
            if(a[i][j] == 'B') {
                finish = {i, j};
            }
        }
    }

    dfs(start.first, start.second);
    cout << "NO";
}