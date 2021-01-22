#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>
using namespace __gnu_pbds;

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void run_cases() {
    int n;
    int64_t x;
    cin >> n >> x;
    vector<int64_t> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    vector<int64_t> part1;
    vector<int64_t> part2;
    int middle = n / 2;
    for(int i=0;i<n;i++) {
        if(i < middle) {
            part1.pb(a[i]);
        }
        else {
            part2.pb(a[i]);
        }
    }

    unordered_map<int64_t, int64_t, custom_hash> left;
    int64_t ans = 0;
    for(int i=0;i<(1<<part1.size());i++) {
        int64_t sum = 0;
        for(int j=0;j<part1.size();j++) {
            if((i & (1 << j)) != 0) {
                sum += part1[j];
            }
        }
        if(sum <= x)
        left[sum]++;
    }

    for(int i=0;i<(1<<part2.size());i++) {
        int64_t sum = 0;
        for(int j=0;j<part2.size();j++) {
            if((i & (1 << j)) != 0) {
                sum += part2[j];
            }
        }

        if(left.count(x - sum)) {
            ans += left[x - sum];
        }

        // ans += left[x - sum];

    }

    cout << ans << '\n';
}   

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}