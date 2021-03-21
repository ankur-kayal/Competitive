#include <bits/stdc++.h>
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
map<int, pair<int,int>> rev_mapping;
map<pair<int,int>, int> mapping;

void build_ranges(vector<pair<int,int>>& ranges) {
    int n = ranges.size();
    vector<int> start, end;
    for(int i=0;i<n;i++) {
        int l,r;
        tie(l, r) = ranges[i];
        start.push_back(l);
        end.push_back(r);
    }
    // sort(all(ranges));
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    vector<pair<int,int>> non_overlap;
    int l = 0, r = 0;   
    int prevr = 1e9;
    while(l < n or r < n) {
        pair<int,int> range;
        range.first = min(l < n ? start[l] : int(1e9), prevr + 1);
        if(start[l] == range.first) {
            l++;
        }
        range.second = min(end[r], l < n ? start[l] - 1 : int(1e9));
        if(range.second == end[r]) {
            r++;
        }
        prevr = range.second;
        if(range.first <= range.second)
                non_overlap.push_back(range);
    }
    debug() << imie(non_overlap);
    for(auto u: non_overlap) {
        rev_mapping[u.first] = u;
    }
}

vector<pair<int,int>> simplify(pair<int,int> a) {
    debug() << imie(a);
    vector<pair<int,int>> child;
    int l = a.first, r = a.second;
    while(l <= r) {
        pair<int,int> range = rev_mapping[l];
        child.push_back(range);
        l = range.second + 1;
    }
    return child;
}
void run_cases() {
    mapping.clear();
    rev_mapping.clear();
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> adj = vector<vector<int>>(1);
    vector<pair<int,int>> range_left, range_right, ranges;
    int index = 1;
    int root = -1, dest = -1;
    for(int i=0;i<m;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        range_left.emplace_back(a,b);
        range_right.emplace_back(c,d);
        ranges.emplace_back(a,b);
        ranges.emplace_back(c,d);
        
    }

    if(x == y) {
        cout << 0 << nl;
        return;
    }

    build_ranges(ranges);
    // debug() << "preprocessed";
    // return;
    for(int i=0;i<m;i++) {
        vector<pair<int,int>> left = simplify(range_left[i]);
        vector<pair<int,int>> right = simplify(range_right[i]);
        debug() << imie(left) imie(right);
        // return;
        for(auto p1: left) {
            for(auto p2: right) {
                int u,v;
                if(mapping.count(p1)) {
                    u = mapping[p1];
                }
                else {
                    u = index;
                    index++;
                    mapping[p1] = u;
                    adj.push_back(vector<int>());
                }
                if(mapping.count(p2)) {
                    v = mapping[p2];
                }
                else {
                    v = index;
                    index++;
                    mapping[p2] = v;
                    adj.push_back(vector<int>());
                }
                if(p1.first <= x and x <= p1.second) {
                    root = u;
                }
                if(p2.first <= x and x <= p2.second) {
                    root = v;
                }
                if(p1.first <= y and y <= p1.second) {
                    dest = u;
                }
                if(p2.first <= y and y <= p2.second) {
                    dest = v;
                }
                adj[u].push_back(v);
            }
        }
    }


    if(dest == -1 or root == -1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> dist(index + 2, -1);
    vector<int> vis(index + 2, 0);
    dist[root] = 0;
    vector<int> q;
    q.push_back(root);
    for(int i=0;i<q.size();i++) {
        int u = q[i];
        vis[u] = 1;
        for(auto v: adj[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                q.push_back(v);
                dist[v] = dist[u] + 1;
            }
        }

    }
    cout << dist[dest] << nl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}