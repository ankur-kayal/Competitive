#include <algorithm>
#include <bits/stdc++.h>
#include <exception>
#include <iomanip>
#include <utility>
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
#define Reminder __FILE__ "(" $Line ") : Warning: "

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

long double get_distance(int64_t x, int64_t y) {
    return sqrtl(x * x + y * y);
}

void run_cases() {
    int n;
    cin >> n;
    umap<int,int> miners, mines;
    vector<int> miner, mine;
    deque<int> pos, neg;

    for(int i=0;i<2*n;i++) {
        int x,y;
        cin >> x >> y;
        if(x == 0) {
            miners[y]++;
            miner.push_back(y);
        }
        else{
            mines[x]++;
            mine.push_back(x);
        }
    }
    sort(all(mine));
    // debug() << imie(mine);
    auto it = unique(all(mine));
    mine.resize(distance(mine.begin(), it));
    sort(all(miner));
    // debug() << imie(mine);
    for(auto u: miner) {
        if(u < 0) {
            neg.push_back(u);
        }
        else {
            pos.push_back(u);
        }
    }
    int l = 0, r = mine.size() - 1;
    long double ans = 0;
    while(l <= r) {
        int closest_miner = 0;
        if(pos.size() == 0) {
            closest_miner = neg.back();
            neg.pop_back();
        }
        else if(neg.size() == 0) {
            closest_miner = pos.front();
            pos.pop_front();
        }
        else {
            if(abs(neg.back()) < pos.front()) {
                closest_miner = neg.back();
                neg.pop_back();
            }
            else {
                closest_miner = pos.front();
                pos.pop_front();
            }
        }

        double ldist = get_distance(mine[l], closest_miner);
        double rdist = get_distance(mine[r], closest_miner);
        if(abs(mine[l]) > abs(mine[r])) {
            debug() << imie(mine[l]) imie(closest_miner);
            l++;
            ans += ldist;
        }
        else {
            debug() << imie(mine[r]) imie(closest_miner);
            r--;
            ans += rdist;
        }
        if(pos.empty() and neg.empty()) {
            break;
        }
    }
    cout << ans << nl;


    

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}