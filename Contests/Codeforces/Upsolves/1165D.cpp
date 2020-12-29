// problem link = https://codeforces.com/contest/1165/problem/D

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

bool isPrime(int64_t n) {
    bool prime = true;
    for(int64_t i=2;i*i<=n;i++) {
        if(n % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}

int countFactors(int64_t n) {
    int cnt = 0;
    for(int64_t i=2;i*i<=n;i++) {
        if(n % i == 0) {
            cnt++;
            if(i != n / i) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int64_t> d(n);
        for(auto &u: d) {
            cin >> u;
        }
        sort(d.begin(), d.end());
        if(n == 1) {
            if(isPrime(d[0])) {
                cout << d[0] * d[0] << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }

        else {
            int64_t target = d[0] * d[n-1];
            bool ok = true;
            for(int i=0;i<=n/2;i++) {
                if(target != d[i] * d[n-i-1]) {
                    ok = false;
                    break;
                }
            }
            int cnt = countFactors(target);
            debug() << imie(cnt);
            cout << (ok and cnt == n ? target : -1) << '\n';
        }
    }
}