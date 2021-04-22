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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


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

struct custom_node {
    int64_t val;
    int64_t lazy;
    // add more data types if you need  

    custom_node() {
        // ... init here with default neutral values;

        
        val = 0;
        lazy = -1;
        
    }

    custom_node(int64_t _val) {
        // ... init here with the actual value
        
        val = _val;
        lazy = -1;
        
    }

    custom_node op(custom_node& other) {
        // ... update the operation you want to use
        
        custom_node ans = custom_node(gcd(val, other.val));
        return ans;
        
    }

    custom_node lazy_op(int64_t val, int64_t size) {
        // ... define the lazy operation you want to use
        
        custom_node ans;
        ans.lazy = val;
        ans.val = (val);
        return ans;
    }
};

struct segment_tree {
    int size; // size of the segment tree, 

    custom_node NEUTRAL_ELEMENT; //  neutral element

    int NO_LAZY; // define the parameter which defines if you have any lazy left

    vector<custom_node> values; // segment tree cumulative values

    void init(int n) {
        // #pragma message(Reminder "Don't forget to define the lazy parameter")
        NO_LAZY = -1; // define the no lazy parameter
        size = 1;
        while(size < n) {
            size *= 2;
        }
        values.assign(2 * size, NEUTRAL_ELEMENT);
    }

    custom_node merge(custom_node& a, custom_node& b) {
        custom_node res;
        res = a.op(b);
        return res;
    }

    void build(vector<int64_t>& a, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(lx < int(a.size())) {
                values[x] = custom_node(a[lx]);
            }
            return;
        }

        int m = (rx + lx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void build(vector<int64_t>& a) {
        build(a, 0, 0, size);
    }

    custom_node query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if(lx >= r or l >= rx) {
            return NEUTRAL_ELEMENT;
        }

        else if(lx >= l and rx <= r) {
            return values[x];
        }

        int m = (lx + rx) / 2;

        custom_node s1 = query(l, r, 2 * x + 1, lx, m);
        custom_node s2 = query(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }

    custom_node query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    void propagate(int x, int lx, int rx) {
        if(values[x].lazy == NO_LAZY) {
            return;
        }
        int m = (rx - lx) / 2;

        values[x] = values[x].lazy_op(values[x].lazy, rx - lx);

        if(rx - lx != 1) { // if you have children propagate the lazy parameter to the children
            // custom define how you want to update !! Most errors occur Here !!
            // #pragma message(Reminder "Define how you want to pass lazy parameters, once done comment this")
            values[2 * x + 1].lazy = values[x].lazy;
            values[2 * x + 2].lazy = values[x].lazy;

        }

        values[x].lazy = NO_LAZY;
    }

    void range_update(int l, int r, int64_t val, int x, int lx, int rx) {
        propagate(x, lx, rx); // try propagating once you touch every node
        if(lx >= r or l >= rx) {
            return;
        }
        if(lx >= l and rx <= r) {
            // custom define how you want to update !! Most errors occur Here !!
            // #pragma message(Reminder "Define how you want to pass lazy parameters and update, once done comment this")
            // values[x].val = val;
            values[x].lazy = val;
            propagate(x, lx, rx);
            return;
        }

        int m = (lx + rx) / 2;
        range_update(l, r, val, 2 * x + 1, lx, m);
        range_update(l, r, val, 2 * x + 2, m, rx);

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void range_update(int l, int r, int64_t val) {
        range_update(l, r, val, 0, 0, size);
    }
};

struct Edge {
    int64_t to;
    int64_t weight;
    int64_t toll;

    Edge() {}
    Edge(int64_t _to, int64_t _weight, int64_t _toll) : to(_to), weight(_weight), toll(_toll) {}
};

struct Query {
    int64_t id;
    int64_t weight;

    Query() {}
    Query(int64_t _id, int64_t _weight) : id(_id), weight(_weight) {}
};

void run_cases() {
    int64_t N,Q;
    cin >> N >> Q;

    vector<vector<Edge>> adj(N + 1);

    for(int64_t i=0;i<N-1;i++) {
        int64_t x,y,l_i, a_i;
        cin >> x >> y >> l_i >> a_i;
        adj[x].push_back(Edge(y, l_i, a_i));
        adj[y].push_back(Edge(x, l_i, a_i));
    }

    segment_tree tree;
    tree.init(int(3e5));

    vector<int64_t> ans(Q);
    vector<vector<Query>> query(N + 1);

    for(int i=0;i<Q;i++) {
        int64_t city, weight;
        cin >> city >> weight;
        query[city].push_back(Query(i, weight));
    }

    auto dfs = y_combinator([&](auto dfs, int node, int par) -> void {

        for(auto u: query[node]) {
            ans[u.id] = tree.query(1, u.weight + 1).val;
        }

        for(auto u: adj[node]) {
            if(u.to != par) {
                tree.range_update(u.weight, u.weight + 1, u.toll);
                dfs(u.to, node);
                tree.range_update(u.weight, u.weight + 1, 0);
            }
        }
    });

    dfs(1, -1);

    for(auto u: ans) {
        cout << u << " ";
    }
    cout << nl;

    
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