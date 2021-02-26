#include <bits/stdc++.h>
#include <limits.h>
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

struct P {
    int64_t x;
    int64_t y;
};

int64_t sq(int64_t n) {
    return n * n;
}

int64_t distance(const P& a, const P& b) {
    return sq(a.x - b.x) + sq(a.y - b.y);
}

int64_t calculate_distance(vector<P>& points) {
    int n = points.size();
    if(n == 1) {
        return LONG_LONG_MAX;
    }
    vector<P> left(points.begin(), points.begin() + n / 2);
    vector<P> right(points.begin() + n / 2, points.end());

    int64_t left_distance = calculate_distance(left);
    int64_t right_distance = calculate_distance(right);

    int64_t d = min(left_distance, right_distance);

    int64_t middle = left.back().x;

    // a.x > middle - d

    vector<P> stripe;
    for(P p: left) {
        if(sq(p.x - middle) < d) {
            stripe.push_back(p);
        }
    }

    for(P p: right) {
        if(sq(p.x - middle) < d) {
            stripe.push_back(p);
        }
    }

    sort(all(stripe), [&](const P& a, const P& b){
        return a.y < b.y;
    });

    int64_t d_stripe = LONG_LONG_MAX;
    for(int i=0;i<stripe.size();i++) {
        for(int j=i+1;j<stripe.size() and sq(stripe[i].y-stripe[j].y) < d;j++) {
            d_stripe = min(d_stripe, distance(stripe[i], stripe[j]));
        }
    }
    return min(d, d_stripe);
}

void run_cases() {
    int n;
    cin >> n;
    vector<P> points(n);
    for(int i=0;i<n;i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(all(points), [&](const P& a, const P& b) {
        return mp(a.x, a.y) < mp(b.x, b.y);
    });

    cout << calculate_distance(points);
    // debug() << imie(LONG_LONG_MAX);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}