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

#define mp make_pair

void run_cases(int n) {
    // int n;
    // cin >> n;

    set<pair<pair<int,int>, char>> pts, tmp;
    pts.insert(mp(mp(1, 0), 'R'));
    pts.insert(mp(mp(0, 1), 'U'));
    pts.insert(mp(mp(0, -1), 'D'));
    pts.insert(mp(mp(-1, 0), 'L'));

    for(int i=2;i<=n;i++) {
        tmp = pts;
        pts.clear();
        for(auto u: tmp) {
            char direction = u.second;
            int x = u.first.first;
            int y = u.first.second;
            if(direction == 'U') {
                pts.insert(mp(mp(x - 1, y), 'L'));
                pts.insert(mp(mp(x + 1, y), 'R'));
            }
            if(direction == 'D') {
                pts.insert(mp(mp(x - 1, y), 'L'));
                pts.insert(mp(mp(x + 1, y), 'R'));
            }
            if(direction == 'L') {
                pts.insert(mp(mp(x, y + 1), 'U'));
                pts.insert(mp(mp(x, y - 1), 'D'));
            }
            if(direction == 'R') {
                pts.insert(mp(mp(x, y + 1), 'U'));
                pts.insert(mp(mp(x, y - 1), 'D'));
            }
        }
        // debug() << imie(pts);
    }

    set<pair<int,int>> ans;
    for(auto u: pts) {
        ans.insert(u.first);
    }

    // debug() << imie(ans);

    cout << n << " " << ans.size() << ' ';
}

void hacked() {
    int n;
    cin >> n;

    vector<int64_t> ans(n + 1);
    ans[0] = 1;
    ans[1] = 4;
    ans[2] = 4;
    int diff = 8;
    for(int i=3;i<=n;i+=2) {
        ans[i] = ans[i-2] + diff;
        diff+=4;
    }
    for(int i=4;i<=n;i+=2) {
        ans[i] = (i / 2 + 1) * (i / 2 + 1);
    }

    cout << ans[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    // int t;
    // cin >> t;
    // for(int i=1;i<=t;i++) {
    //     run_cases(i);
    //     hacked(i);
    // }
    // // run_cases();

    hacked();
}