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
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }

        vector<vector<int>> pos(n + 1, vector<int>());
        for(int i=0;i<n;i++) {
            pos[a[i]].push_back(i + 1);
        }
        int ans = 1e9;
        for(int i=1;i<=n;i++) {
            if(pos[i].size() == 0) continue;
            else if(pos[i].size() == 1 and (pos[i][0] == 1 or pos[i][0] == n)) {
                ans = min(1, ans);
            }
            else if(pos[i].size() == 1) {
                ans = min(2, ans);
            }
            int tmp = 0;
            int start = pos[i][0];
            int end = pos[i].back();
            for(int j=0;j<pos[i].size() - 1;j++) {
                if(pos[i][j + 1] - pos[i][j] != 1) {
                    tmp++;
                }
            }
            tmp += (start != 1) + (end != n);
            debug() << imie(i) imie(tmp);
            ans = min(ans, tmp);
        }
        cout << ans << '\n';
    }
}