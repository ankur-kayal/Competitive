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
/*
1
5
17942112 454594138 234740361 242899555 138750740
*/
/*
[n: 4] 
 [a: [436899940, 667781341, 459666161, 425113456]] 
 [b: [436899940, 873799880, 873799880, 1]] 
 [2 * s1: 2090531426]  [sum: 1989460898]

*/

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for(auto &u: a) {
            cin >> u;
        }

        int64_t sum = 0;
        for(auto u: a) {
            sum += u;
        }
        vector<int64_t> b(n);

        b[0] = a[0];
        for(int i=1;i<n;i++) {
            if(b[i-1] % a[i] == 0) {
                b[i] = a[i];
                continue;
            }
            // if(a[i] % b[i-1] <= b[i-1] / 2) {
            //     b[i] = max(1LL, (a[i] / b[i-1]) * b[i-1]);
            // }
            // else {
            //     b[i] = max(1LL, (a[i] + b[i-1] - 1) / b[i-1] * b[i-1]);
            // }
            // // if(i == 3)break;

            b[i] = (a[i] - (a[i] % b[i-1]));
            b[i] = max(1LL, b[i]);
            // if(b[i] == 0) {
            //     b[i] = 
            // }
            // debug() << imie(b[i]);

        }

        int64_t s1 = 0;
        for(int i=0;i<n;i++) {
            s1 += abs(a[i] - b[i]);
        }
        debug() << imie(2 * s1) imie(sum);
        assert(2 * s1 <= sum);
        for(auto u: b) {
            cout << u << " ";
        }
        cout << '\n';
    }
}