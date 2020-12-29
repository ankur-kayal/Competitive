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

    int q;
    cin >> q;
    set<pair<int,int>> polycarp, monocarp;
    // polycarp -> -value, index
    // monocarp -> index, value
    int index = 1;
    while(q--) {
        int ch;
        cin >> ch;
        int cust_id, money;
        if(ch == 1) {
            int value;
            cin >> value;
            polycarp.insert({-value, index});
            monocarp.insert({index, value});
            index++;
        }
        else if(ch == 2) {
            // monocarp 
            tie(cust_id, money) = *monocarp.begin();
            monocarp.erase(monocarp.begin());
            polycarp.erase(polycarp.find({-money, cust_id}));
            cout << cust_id << ' ';
        }
        else if(ch == 3) {
            // polycarp
            tie(money, cust_id) = *polycarp.begin();
            money = -money;
            polycarp.erase(polycarp.begin());
            monocarp.erase(monocarp.find({cust_id, money}));
            cout << cust_id << ' ';
        }
    }
}