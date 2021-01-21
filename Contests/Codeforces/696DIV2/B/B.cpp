#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert

//----------------------------------- END DEFINES -------------------------------- 

vector<int64_t> count_divisors(int64_t n) {
    vector<int64_t> divisors;
    int cnt = 0;
    for(int64_t i=1;i*i<=n;i++) {
        if(n % i == 0) {
            cnt++;
            divisors.push_back(i);
            if(n / i != i) {
                cnt++;
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

bool is_prime(int n) {
    for(int i=2;i*i<=n;i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int brute(int d) {
    for(int i=6;;i++) {
        vector<int64_t> divs = count_divisors(i);
        int n = divs.size();
        if(n & 1) {
            n++;
        }
        // debug() << imie(i) imie(n) imie(divs);
        bool ok = true;
        sort(all(divs));
        for(int i=0;i<n-1;i++) {
            if(divs[i+1] - divs[i] < d) {
                ok = false;
                break;
            }
        }
        if(ok and n >= 4) {
            return i;
        }
    }
}

int actual(int d) {
    for(int i=1+d;;i++) {
        if(is_prime(i)) {
            for(int j=i+d;;j++) {
                if(is_prime(j)) {
                    return i*j;
                }
            }
        }
    }
}

void checker() {
    for(int i=1;i<=100;i++) {
        // debug() << imie(brute(i)) imie(actual(i));
        if(brute(i) != actual(i)) {
            debug() << imie(brute(i)) imie(actual(i));
        }
    }
}

void run_cases() {
    int d;
    cin >> d;
    for(int i=1+d;;i++) {
        if(is_prime(i)) {
            for(int j=i+d;;j++) {
                if(is_prime(j)) {
                    cout << i * j << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    checker();
    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}