#include <bits/stdc++.h>
#include <cstdlib>
#include <stdint.h>
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

const int maxN = 1e7 + 10;
vector<int> seive(maxN + 1);

void init() {
    iota(seive.begin(), seive.end(), 0);
    for(int i=2;i*i<maxN;i++) {
        if(seive[i] == i) {
            for(int j=i*i;j<maxN;j+=i) {
                if(seive[j] == j) {
                    seive[j] = i;
                }
            }
        }
    }
}

int64_t calculateDivisors(int64_t n) {
    int64_t ans = 1;
    int64_t cnt = 0;
    int prev = -1;
    while(seive[n] != 1) {
        if(seive[n] != prev) {
            ans = ans * (cnt + 1);
            cnt = 0;
            prev = seive[n];
        }
        cnt++;
        n = n / seive[n];
    }
    ans *= (cnt + 1);
    return ans;
}

int64_t calculateDivisorsNaive(int64_t n) {
    vector<int> divisors;
    for(int i=1;i*i<=n;i++) {
        if(n % i == 0) {
            divisors.push_back(i);
            if(i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return int64_t(divisors.size());
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();
    int64_t n;
    cin >> n;
    int64_t ans = 0;
    for(int64_t i=1;i<=n;i++) {
        ans += i * calculateDivisors(i);
    }
    cout << ans << '\n';
}