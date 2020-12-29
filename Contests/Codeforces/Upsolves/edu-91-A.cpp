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
        for(auto &u: a) {
            cin >> u;
        }

        bool exists = false;
        int I,J,K;

        for(int j=1;j<n-1;j++) {
            int score = 0;
            for(int i=0;i<j;i++) {
                if(a[i] < a[j]) {
                    score++;
                    I = i;
                    break;
                }
            }
            for(int k=j+1;k<n;k++) {
                if(a[k] < a[j]) {
                    score++;
                    K = k;
                    break;
                }
            }
            if(score == 2) {
                J = j;
                exists = true;
            }
        }

        if(exists) {
            cout << "YES" << '\n';
            cout << I + 1 << " " << J + 1 << " " << K + 1 << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}