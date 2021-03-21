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


const int maxN = 1e6;

pair<int,int> calculate_shift(pair<int,int> a, pair<int,int> b) {
    return {a.first - b.first, a.second - b.second};
}
void run_cases() {
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> cities;
    for(int i=0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        cities.emplace_back(x,y);
    }
    vector<pair<pair<int,int>, pair<int,int>>> wires;
    for(int i=0;i<m;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(make_pair(a,b) > make_pair(c,d)) {
            swap(a,c);
            swap(b,d);
        }
        wires.push_back(make_pair(make_pair(a,b), make_pair(c,d)));
    }

    pair<int,int> pos = {-1, 0};
    pair<int,int> neg = {maxN + 1, maxN};

    vector<int> used(n, 0);
    set<int> not_used;
    for(int i=0;i<n;i++) {
        not_used.insert(i);
    }

    int prob;
    bool weighted = false;
    bool nega = false, posi = false;
    vector<pair<int,int>> ans(n);
    bool one_neg = false, one_pos = false;
    while(!not_used.empty()) {
        int index = uid(0, n - 1);
        while(used[index]) {
            index = uid(0, n - 1);
        }
        if(!weighted){
            prob = uid(1, 100);
            if(prob < 60) {
                nega = false;
            }
            else {
                nega = true;
            }
        } else {
            weighted = false;
        }

        if(not_used.size() == 1 and !one_neg) {
            nega = true;
        }
        if(not_used.size() == 1 and !one_pos) {
            nega = false;
        }

        if(!nega) {
            nega = false;
            ans[index] = calculate_shift(pos, wires[index].first);
            int hi, vi;
            tie(hi, vi) = ans[index];
            if(abs(hi) > maxN or abs(vi) > maxN) {
                nega = true;
                weighted = true;
                ans[index] = {0 , 0};
                continue;
            }
            one_pos = true;
            pos = wires[index].second;
            debug() << imie(pos) imie(wires[index]) imie(ans[index]);
            pos.first += ans[index].first;
            pos.second += ans[index].second;
            debug() << imie(pos);
            pos = wires[index].second;
        }
        else {
            nega = false;
            ans[index] = calculate_shift(neg, wires[index].second);
            int hi, vi;
            tie(hi, vi) = ans[index];
            if(abs(hi) > maxN or abs(vi) > maxN) {
                posi = true;
                weighted = true;
                ans[index] = {0 , 0};
                continue;
            }
            one_neg = true;
            neg = wires[index].first;
            debug() << imie(neg) imie(wires[index]) imie(ans[index]);
            neg.first += ans[index].first;
            neg.second += ans[index].second;
            debug() << imie(neg);
        }
        // if(not_used.size() < 5000) break;
        if(one_neg and one_pos) break;
        not_used.erase(index);
        used[index] = 1;
        debug() << imie(not_used.size());

    }
    for(int i=0;i<n;i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
    cerr << boolalpha << one_neg << " " << one_pos << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}