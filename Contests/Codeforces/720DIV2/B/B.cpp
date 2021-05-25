#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


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

vector<int> smallest_factor;
vector<bool> prime;
vector<int> primes;
 
void sieve(int maximum) {
    maximum = max(maximum, 1);
    smallest_factor.assign(maximum + 1, 0);
    prime.assign(maximum + 1, true);
    prime[0] = prime[1] = false;
    primes = {};
 
    for (int p = 2; p <= maximum; p++)
        if (prime[p]) {
            smallest_factor[p] = p;
            primes.push_back(p);
 
            for (int64_t i = int64_t(p) * p; i <= maximum; i += p)
                if (prime[i]) {
                    prime[i] = false;
                    smallest_factor[i] = p;
                }
        }
}

void run_cases() {
    int n;
    cin >> n;
    vector<int64_t> A(n);
    for(auto &u: A) {
        cin >> u;
    }
    int minA = *min_element(A.begin(), A.end());
    int pos = find(A.begin(), A.end(), minA) - A.begin();
    debug() << imie(pos);
    vector<vector<int64_t>> operations;

    for(int i=pos+1;i<n;i++) {
        if((i - pos) & 1) {
            A[i] = minA + 1;
        } else {
            A[i] = minA;
        }
        operations.push_back(vector<int64_t>{pos+1, i+1, A[pos], A[i]});
    }
    for(int i=pos-1;i>=0;i--) {
        if((-i + pos) & 1) {
            A[i] = minA + 1;
        } else {
            A[i] = minA;
        }
        operations.push_back(vector<int64_t>{pos+1, i+1, A[pos], A[i]});
    }

    // debug() << imie(A);
    for(int i=0;i<n-1;i++) {
        int hcf = gcd(A[i], A[i+1]);
        // debug() << imie(hcf);
        assert(hcf == 1);
    }
    // for(auto u: operations) {
    //     debug() << imie(u);
    // }

    cout << operations.size() << nl;
    for(auto u: operations) {
        cout << u[0] << " " << u[1] << " " << u[2] << " " << u[3] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    sieve(int(2e6));
    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}