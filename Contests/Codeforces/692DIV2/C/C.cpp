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
        int ans = m;
        vector<pair<int,int>> pos;
        vector<int> row(n + 1, 0), col(n + 1, 0), cnt(n + 1, 0);
        for(int i=0;i<m;i++) {
            int x,y;
            cin >> x >> y;
            pos.emplace_back(x,y);
            row[x]++;
            col[y]++;
            cnt[x]++, cnt[y]++;
        }
        // debug() << imie(ans);
        // bool special = false;
        // debug() << imie(cnt);
        // for(auto u: pos) {
        //     int x = u.first, y = u.second;
        //     if(x == y) {
        //         ans--;
        //     }
        //     // else if(row[x] == 2 and col[y] == 2) {
        //     //     bool special = true;
        //     // }

        //     else if(cnt[x] == 2 and cnt[y] == 2) {
        //         special = true;
        //     }
        //     debug() << imie(x) imie(y) imie(cnt[x]) imie(cnt[y]);
        // }
        // debug() << imie(special);
        // if(special) {
        //     ans++;
        // }

        vector<pair<int,int>> tmp;
        int moved = true;
        while(true) {
            debug() << imie("inf");

            moved = false;
            for(auto u: pos) {
                int x = u.first;
                int y = u.second;
                if(x == y) {
                    ans--;
                }
                else if(cnt[x] == 2 and cnt[y] != 2) {
                    cnt[x]--;
                    cnt[y]++;
                    moved = true;
                }
                else if(cnt[y] == 2 and cnt[x] != 2) {
                    cnt[y]--;
                    cnt[x]++;
                    moved = true;
                }
                else if(cnt[y] == 1 and cnt[x] == 1){
                    cnt[y]--;
                    cnt[x]++;
                    moved = true;
                }
                else {
                    tmp.push_back(u);
                }
            }
            pos = tmp;
            tmp.clear();
            if(!moved) {
                break;
            }
        }
        
        if(pos.size() != 0) {
            int l = pos.size();
            vector<int> vis(n + 1, 0);
            vector<int> perm(n + 1, 0);
            for(auto u: pos) {
                int x = u.first;
                int y = u.second;
                perm[x] = y;
            }
            for(auto u: pos) {
                int x = u.first;
                int y = u.second;
                if(vis[x] != 2) {
                    ans++;
                    while(true) {
                        vis[x]++;
                        vis[y]++;
                        if(vis[x] == 2 and vis[y] == 2) {
                            break;
                        }
                        x = y;
                        y = perm[y];
                    }
                }
            }
        }

        cout << ans << '\n';
    }
}