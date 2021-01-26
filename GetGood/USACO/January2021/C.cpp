#include <algorithm>
#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

// USACO 2021 January Contest, Bronze
// Problem 3. Just Stalling

/*

4
1 2 3 4
2 4 3 4


4 -> 2,4
3 -> 2,3,4
2 -> 1,2,3,4
1 -> 1,2,3,4

5
100 25 36 41 58
45 56 98 120 145

1 -> 4,5
2 -> 1,2,3,4,5
3 -> 1,2,3,4,5
4 -> 1,2,3,4,5
5 -> 3,4,5

*/

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


void run_cases() {
    int n;
    cin >> n;
    vector<int64_t> cow(n), barn(n);
    for(int i=0;i<n;i++) {
        cin >> cow[i];
    }
    for(int i=0;i<n;i++) {
        cin >> barn[i];
    }

    int64_t ans = 0;

}

bool verify(vector<int64_t>& a, vector<int64_t>& b) {
    int n = a.size();
    for(int i=0;i<n;i++) {
        if(a[i] > b[i]) {
            return false;
        }
    }
    return true;
}

void brute() {
    int n;
    cin >> n;
    vector<int64_t> cow(n), barn(n);
    for(int i=0;i<n;i++) {
        cin >> cow[i];
    }
    for(int i=0;i<n;i++) {
        cin >> barn[i];
    }
    vector<int> indices(n);
    for(int i=0;i<n;i++) {
        indices[i] = i;
    }

    int64_t ans = 0;
    do {
        vector<int64_t> a;
        for(auto u : indices) {
            a.push_back(cow[u]);
        }
        if(verify(a, barn)) {
            debug() << imie(a);
            ans++;
        }
    } while(next_permutation(indices.begin(), indices.end()));

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int64_t fact = 1;
    for(int i=1;i<=20;i++) {
        fact *= i;
    }

    debug() << imie(fact);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        // run_cases();
        brute();
    }
}