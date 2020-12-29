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

int64_t evaluate(vector<int64_t>& a, int target) {
    int n = a.size();
    int64_t tmp = 0;
    int64_t sum = 0;
    for(int i=0;i<n;i++) {
        int64_t need = a[i] - target;
        int64_t req = need - sum;
        tmp += abs(req);
        sum += req;
    }
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<int64_t> a = {1, 4, 3, 2, 4, 1};
    int n = a.size();
    int64_t minans = 1e18;
    for(int i=0;i<n;i++) {
        int in = a[i];
        for(int val = -5;val < 6;val++) {
            a[i] = val;
            for(int target = -5; target < 6;target++) {
                debug() << imie(a) imie(target) imie(evaluate(a, target));
                minans = min(minans, evaluate(a, target));
            }
        }
        a[i] = in;
    }
    cout << minans << '\n';
}