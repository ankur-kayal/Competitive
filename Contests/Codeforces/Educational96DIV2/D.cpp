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
        string s;
        cin >> s;
        s += '#';
        set<pair<int,int>> grps;
        set<pair<int,int>> ori;
        int index = 0;
        char val = s[0];
        int cnt = 1;
        for(int i=1;i<=n;i++) {
            if(val != s[i]) {
                pair<int,int> grp = {index, cnt};
                if(cnt > 1) {
                    grps.insert(grp);
                }
                ori.insert(grp);
                index = i;
                cnt = 1;
                val = s[i];
            }
            else {
                cnt++;
            }
        }
        debug() << imie(grps) imie(ori);
        int ans = 0;
        while(!ori.empty()) {
            ans++;
            if(!grps.empty()) {
                pair<int,int> grp = *grps.begin();
                pair<int,int> top = *ori.begin();
                ori.erase(ori.find(grp));
                grps.erase(grps.begin());
                // debug() << imie(grp) imie(top);
                if(grp != top) {
                    grp.second--;
                    if(grp.second > 1) {

                        grps.insert(grp);
                    }
                    ori.insert(grp);
                    ori.erase(ori.begin());
                }
            }
            else {
                ori.erase(ori.begin());
                if(!ori.empty()) {
                    ori.erase(ori.begin());
                }
            }
            debug() << imie(grps) imie(ori);
            // exit(0);
        }
        if(ans == 4) {
            debug() << imie(s);
        }
        cout << ans << '\n';
    }
}