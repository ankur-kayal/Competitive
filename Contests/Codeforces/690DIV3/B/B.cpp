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
        if(n <= 4) {
            if(s == "2020") {
                cout << "YES" << '\n';
            }
            else {
                cout << "NO" << '\n';
            }
            continue;
        }
        bool ok = false;
        string tmp = "";
        string rev(s);
        reverse(rev.begin(), rev.end());
        for(int i=0;i<3;i++) {
            tmp += s[i];
                // debug() << imie(tmp) << imie(s.substr(n+i-3, 4 - i  -1));
            if(tmp + s.substr(n+i-3, 4 - i  -1) == "2020") {
                ok = true;
            }
        }
        // cout << s.substr(n - 4, 4) << '\n';
        if(s.substr(n - 4,4) == "2020") {
            // cout << "here" << '\n';
            ok = true;
        }
        if(s.substr(0,4) == "2020") {
            // cout << "here" << '\n';
            ok = true;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}