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

const int maxA = 1e6 + 10;
vector<int> seive(maxA);

void init() {
    for(int i=0;i<maxA;i++) {
        seive[i] = i;
    }

    for(int i=2;i*i<maxA;i++) {
        if(seive[i] == i) {
            for(int j=i*i;j<maxA;j+=i) {
                if(seive[j] == j) {
                    seive[j] = i;
                }
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();

    int t;
    cin >> t;
    while(t--) {
        int n,q;
        cin >> n >> q;
        vector<int> a(n);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }

        auto query1 = [&](int l, int r) {
            int ans = 1;
            for(int i=l;i<=r;i++) {
                if(a[i] != 1) 
                ans = max(seive[a[i]], ans);
            }
            return ans;
        };

        auto query0 = [&](int l, int r) -> void {
            // debug() << imie(l) imie(r);
            for(int i=l;i<=r;i++) {
                a[i] = a[i] / seive[a[i]];
            }
        };

        while(q--) {
            int ch,l,r;
            cin >> ch >> l >> r;
            --l, --r;
            if(ch == 0) {
                query0(l, r);
            }
            else {
                cout << query1(l,r) << " ";
            }
            // debug() << imie(a);
        }
        cout << '\n';

    }
}