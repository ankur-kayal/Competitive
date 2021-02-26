#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("trapv")

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
using namespace std::chrono;

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

vector<vector<int>> adj, levels;
vector<int> p, children;
vector<uint64_t> factor;
int ans = 0;

umap<pair<int,int>, int> store;

void dfs(int node, int depth) {
    levels[depth].push_back(node);
    factor[node] = 1;
    uint64_t LCM = 1;
    vector<uint64_t> child_factors;
    for(int child : adj[node]) {
        if(child != p[node]) {
            dfs(child, depth + 1);
            // child_factors.push_back(factor[child]);
            LCM = lcm(LCM, factor[child]);
        }
    }
    LCM *= children[node];
    factor[node] = max(uint64_t(1), LCM);
} 

void solve(int node, int tasks) {
    bool ok = false;
    if(children[node] == 0) return;
    if(tasks % children[node] == 0) {
        if(tasks < factor[node] and factor[node] % tasks == 0) {
            ans += tasks;
        }
        else if(tasks % factor[node] != 0) {
            for(int child: adj[node]) {
                if(child != p[node]) {
                    solve(child, tasks / children[node]);
                }
            }
        }
    }
    else {
        ans += tasks;
    }
}

void run_cases() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1, vector<int>());
    levels = vector<vector<int>>(n + 1, vector<int>());
    p = vector<int>(n + 1);
    children = vector<int>(n + 1);
    factor = vector<uint64_t>(n + 1);
    for(int i=2;i<=n;i++) {
        cin >> p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
        children[p[i]]++;
    }
    debug() << imie(p[n-1]);

    dfs(1, 1);
    
    // cout << "No integer overflow" << nl;

    // debug() << imie(factor);
    debug() << imie(factor[1]);

    int Q;
    cin >> Q;
    debug() << imie(Q);
    while(Q--) {
        int v, w;
        cin >> v >> w;
        if(store.count({v,w})) {
            cout << store[{v, w}] << nl;
            continue;
        }
        ans = 0;
        solve(v, w);
        store[{v, w}] = ans;
        cout << ans << nl;
    }


    // debug() << 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    auto start = high_resolution_clock::now();

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }

    auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<milliseconds>(stop - start); 
   
    // cout << duration.count() << endl; 
    debug() << duration.count();
}