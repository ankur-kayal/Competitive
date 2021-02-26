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
#define nl '\n'

//----------------------------------- END DEFINES -------------------------------- 

const int maxN = 1e6 + 100;

vector<int> count_primes(maxN, 0);

void preprocess() {
    vector<bool> primes(maxN, 1);
    primes[0] = primes[1] = 0;
    for(int i=2;i*i<maxN;i++) {
        if(primes[i]) {
            for(int j=i*i;j<maxN;j+=i) {
                primes[j] = 0;
            }
        }
    }


    for(int i=2;i<maxN;i++) {
        count_primes[i] = count_primes[i-1];
        if(primes[i]) {
            count_primes[i]++;
        }
    }
}

void run_cases() {
    int x,y;
    cin >> x >> y;
    string winner;
    if(count_primes[x] <= y) {
        winner = "Chef";
    }
    else {
        winner = "Divyam";
    }
    cout << winner << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    preprocess();
    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}