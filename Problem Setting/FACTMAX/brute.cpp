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

const int maxA = 1000100;

vector<int> smallestPrimeFactor(maxA);

void init() {
    iota(smallestPrimeFactor.begin(), smallestPrimeFactor.end(), 0);
    for(int i=2;i*i<maxA;i++) {
        if(smallestPrimeFactor[i] == i) {
            for(int j=i*i;j<maxA;j+=i) {
                smallestPrimeFactor[j] = min(smallestPrimeFactor[j], i);
            }
        }
    }
}

int countDivisors(int A) {
    int ans = 1;
    int tmp = 1;
    int val = smallestPrimeFactor[A];
    while(smallestPrimeFactor[A] != 1) {
        if(smallestPrimeFactor[A] == val) {
            tmp++;
        }
        else {
            ans *= tmp;
            tmp = 2;
            val = smallestPrimeFactor[A];
        }
        A /= smallestPrimeFactor[A];

    }
    ans *= tmp;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();

    int n,q;
    cin >> n >> q;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        a.emplace_back(countDivisors(tmp), tmp);
    }

    while(q--) {
        int ch;
        cin >> ch;
        if(ch == 1) {
            int index, val;
            cin >> index >> val;
            --index;
            a[index] = make_pair(countDivisors(val), val);
        }
        else {
            int l,r;
            cin >> l >> r;
            --l; --r;
            pair<int,int> ans = {-1, -1};
            for(int i=l;i<=r;i++) {
                ans = max(ans, a[i]);
            }
            cout << ans.second << '\n';
        }
    }

}