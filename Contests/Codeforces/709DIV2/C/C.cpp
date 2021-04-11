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

void run_cases() {

    int n, m;
    cin >> n >> m;

    vector<int> day_cnt(m, 0);
    vector<vector<int>> avail(m, vector<int>());
    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> cnt(n + 1 , 0);
    multiset<int> min_cnt;

    for(int i=0;i<m;i++) {
        int k;
        cin >> k;
        avail[i] = vector<int>(k);

        for(int j=0;j<k;j++) {
            cin >> avail[i][j];
            adj[avail[i][j]].pb(i);
        }
        day_cnt[i] = k;
        min_cnt.insert(k);
    }

    debug() << imie(adj);


    vector<int> q;
    for(int i=0;i<m;i++) {
        if(day_cnt[i] == *min_cnt.begin()) {
            q.push_back(i);
        }
    }

    vector<bool> processed(m);
    vector<int> ans(m);
    for(int i=0;i<q.size();i++) {
        int u = q[i];
        if(processed[u]) {
            continue;
        }
        processed[u] = true;
        min_cnt.erase(min_cnt.find(day_cnt[u]));
        int chosen = 1e9;
        int id = -1;
        for(auto v: avail[u]) {
            if(cnt[v] < chosen) {
                id = v;
                chosen = cnt[v];
            }
        }
        assert(id != -1);

        ans[u] = id;
        cnt[id]++;

        for(auto v: adj[id]) {
            if(processed[v]) {
                continue;
            }
            if(day_cnt[v] != 0){
                min_cnt.erase(min_cnt.find(day_cnt[v]));
                day_cnt[v]--;
                min_cnt.insert(day_cnt[v]);
            }
            
            
        }
        debug() << imie("inf");
        for(auto v: adj[id]) {
            if(day_cnt[v] == *min_cnt.begin() and !processed[v]) {
                q.push_back(v);
            }
        }
        debug() << imie(ans);
        debug() << imie(cnt);
        debug() << imie(q) imie(u);
        debug() << imie(day_cnt);
        debug() << imie(min_cnt);
    }

    for(auto u: ans) {
        if(cnt[u] > (m + 1) / 2) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;
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
        run_cases();
    }
}