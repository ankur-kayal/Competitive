#include <algorithm>
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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 

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
const int inf = 1e9;

int score(vector<int> a) {
    int n = a.size();
    int64_t ans = 0;
    for(int i=0;i<n-1;i++) {
        int val = inf;
        int index = -1;
        for(int j=i;j<n;j++) {
            if(a[j] < val) {
                index = j;
                val = a[j];
            }
        }
        assert(index != -1);
        reverse(a.begin() + i, a.begin() + index + 1);
        ans += index - i + 1;
    }
    assert(is_sorted(all(a)));
    return ans;
}

void run_cases() {
    int n,k;
    cin >> n >> k;
    int needed_score = k;
    int min_score = n - 1;
    vector<int> max_a;
    for(int i=2;i<=n;i += 2) {
        max_a.pb(i);
    }
    int ending = n & 1 ? n : n - 1;
    for(int i=ending;i>=1;i-=2) {
        max_a.pb(i);
    }

    int max_score = score(max_a);
    sort(all(max_a));

    if(min_score <= k && k <= max_score) {
        k -= min_score;
        vector<int> rsort(n);
        for(int i=1;i<=n;i++) {
            rsort[i-1] = i;
        }
        int high = n;
        int start = 0;
        int max_val = n;
        bool rotated = false;
        while(k > 0) {
            // debug() << imie(k) imie(rotated) imie(start) imie(high);
            if(!rotated) {
                int val = min(max_val - 1, k);
                k -= val;
                reverse(rsort.begin() + start, rsort.begin() + start + val + 1);
                // debug() << imie(rsort) imie(val);
                high--;
                max_val--;
                rotated = !rotated;
            }
            else {
                int val = min(max_val - 1, k);
                k -= val;
                reverse(rsort.begin() + high - val - 1, rsort.begin() + high);
                // debug() << imie(rsort) imie(val);
                start++;
                max_val--;
                rotated = !rotated;
            }
        }
        // assert(score(rsort) == needed_score);
        if(score(rsort) != needed_score) {
            debug() << imie(rsort);
            debug() << imie(n) imie(needed_score) << nl;
            exit(0);
        }
        for(auto u: rsort) {
            cout << u << " ";
        }
        cout << nl;
    } else {
        cout << "IMPOSSIBLE" << nl;
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