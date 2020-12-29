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
        string s;
        cin >> s;
        vector<int> cnt(26, 0);
        for(auto u: s) {
            cnt[u - 'a']++;
        }

        multiset<int> cache;
        for(auto u: cnt) {
            if(u != 0) {
                cache.insert(u);
            }
        }

        int ans = 0;
        while(true) {
            debug() << imie(cache);
            int back = *prev(cache.end());
            cache.erase(prev(cache.end()));
            if(back < 2) {
                break;
            }
            back -= 2;
            if(back > 0) {
                cache.insert(back);
            }

            if(cache.size() > 0) {
                int front = *cache.begin();
                cache.erase(cache.begin());
                front--;
                if(front > 0) {
                    cache.insert(front);
                }
                ans++;
            }
            else {
                break;
            }
            if(cache.empty()) {
                break;
            }
        }

        cout << ans << '\n';
    }
}