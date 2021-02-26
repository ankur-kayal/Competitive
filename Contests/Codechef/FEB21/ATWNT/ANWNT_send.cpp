#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")


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
        return splitmix64(x(a.f) * 37 + y(a.s) + FIXED_RANDOM);
    }
};
template<class T, class H>using umap=unordered_map<T,H,custom_hash>;

//----------------------- CUSTOM UNORDERED MAP HASH END--------------------------



const int maxN = 1e5 + 10;

vector<vector<int>> adj;
const int maxTask = 1e6;
vector<gp_hash_table<int,int>> factor;
vector<int> id;

void dfs(int node){
    if(adj[node].size() == 0) {
        factor[node][1] = 1;
        return;
    }

    for(int child: adj[node]) {
        dfs(child);
        if(adj[node].size() > 1) {
            for(auto u: factor[id[child]]) {
                if(u.first * adj[node].size() <= maxTask) {
                    factor[node][u.first * adj[node].size()] += u.second;
                }
            }
        }
    }

    if(adj[node].size() == 1) {
        id[node] = id[adj[node][0]];
    }
}

int calculate_ignored_tasks(int node, int tasks) {
    node = id[node];
    int processed = 0;
    for(auto u: factor[node]) {
        if(tasks % u.first == 0) {
            processed += tasks / u.first * u.second;
        }
    }
    return tasks - processed;
}

void run_cases() {
    int n;
    cin >> n;
    adj = vector<vector<int>>(n + 1, vector<int>());
    factor = vector<gp_hash_table<int,int>>(n + 1);
    id = vector<int>(n + 1);
    for(int i=1;i<n;i++) {
        int u;
        cin >> u;
        adj[u].push_back(i + 1);
    }


    for(int i=1;i<=n;i++) {
        id[i] = i;
    }

    dfs(1);

    int queries;
    cin >> queries;
    while(queries--) {
        int vertex, tasks;
        cin >> vertex >> tasks;
        cout << calculate_ignored_tasks(vertex, tasks) << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}