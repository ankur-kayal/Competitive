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
#define Stringize( L )     #L 
#define MakeString( M, L ) M(L)
#define $Line MakeString( Stringize, __LINE__ )
#define Reminder __FILE__ "("  ") : Warning: "

//----------------------------------- END DEFINES -------------------------------- 

//-------------------------- CUSTOM UNORDERED MAP HASH ---------------------------

struct custom_hash{
    static uint64_t splitmix64(uint64_t x){
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(a + FIXED_RANDOM);
    }
    template<class T> size_t operator()(T a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        return splitmix64(x(a) + FIXED_RANDOM);
    }
    template<class T, class H> size_t operator()(pair<T, H> a) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        hash<T> x;
        hash<H> y;
        return splitmix64(x(a.first) * 37 + y(a.second) + FIXED_RANDOM);
    }
};
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;

//----------------------- CUSTOM UNORDERED MAP HASH END--------------------------

void run_cases() {
    int64_t x,y;
    string s;
    cin >> x >> y >> s;
    int n = s.length();
    vector<vector<int64_t>> dp(n, vector<int64_t>(2, 0)); // 0 for C 1 for J
    for(int i=1;i<n;i++) {
        if(s[i] == 'C') {
            if(s[i-1] == 'C') {
                dp[i][0] = dp[i-1][0];
            } else if(s[i-1] == 'J') {
                dp[i][0] = dp[i-1][1] + y;
            } else {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1] + y);
            }
        } else if(s[i] == 'J') {
            if(s[i - 1] == 'J') {
                dp[i][1] = dp[i-1][1];
            } else if(s[i - 1] == 'C') {
                dp[i][1] = dp[i - 1][0] + x;
            } else {
                dp[i][1] = min(dp[i-1][1], dp[i-1][0] + x);
            }
        } else {
            if(s[i - 1] == 'J') {
                dp[i][1] = dp[i-1][1];
                dp[i][0] = dp[i-1][1] + y;
            } else if(s[i - 1] == 'C') {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][0] + x;
            } else {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1] + y);
                dp[i][1] = min(dp[i-1][1], dp[i-1][0] + x);
            }
        }
    }

    if(s[n-1] == 'C') {
        cout << dp[n-1][0] << nl;
    } else if(s[n-1] == 'J') {
        cout << dp[n-1][1] << nl;
    } else {
        cout << min(dp[n-1][0], dp[n-1][1]) << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}