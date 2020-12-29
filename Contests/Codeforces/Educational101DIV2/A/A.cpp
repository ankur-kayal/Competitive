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
        int open = -1, closed = -1;
        int n = s.length();
        int cnt = 0;
        bool ok = true;
        int first = 0, middle = 0, last = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '?') {
                cnt++;
            }
            else if(s[i] == '(') {
                cnt++;
            }
            else {
                cnt--;
            }
            if(cnt < 0) {
                break;
            }
        }
        if(s[n-1] == '(') {
            cnt = 1;
        }
        debug() << imie(cnt);
        cout << (cnt % 2 == 0 and n % 2 == 0 ? "YES" : "NO") << '\n';
    }
}