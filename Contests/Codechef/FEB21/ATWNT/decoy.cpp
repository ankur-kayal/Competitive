#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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
#define int128_t __int128


//----------------------------------- END DEFINES --------------------------------


vector<vector<int>> adj, levels;
vector<int> p, children;
vector<int64_t> factor;
vector<unordered_map<int,int>> LCM;
vector<vector<pair<int,int>>> prime_factors(1000100);
int ans = 0;

void preprocess() {
    for(int i=2;i<=1000000;i++) {
        if(prime_factors[i].size() == 0) {
            for(int j=i;j<=1000000;j+=i) {
                int num = j;
                pair<int,int> factor = {i, 0};
                while(num % i == 0) {
                    factor.second++;
                    num /= i;
                }
                prime_factors[j].push_back(factor);
            }
        }
    }
}

void dfs(int node, int depth) {
    levels[depth].push_back(node);
    vector<int64_t> child_factors;
    for(int child : adj[node]) {
        if(child != p[node]) {
            dfs(child, depth + 1);
            // child_factors.push_back(factor[child]);
            for(auto u: LCM[child]) {
                LCM[node][u.first] = max(LCM[node][u.first], u.second);
            }
        }
    }
    if(children[node] != 0)
        for(auto u: prime_factors[children[node]]) {
            LCM[node][u.first] += u.second;
        }
} 

void solve(int node, int tasks) {
    bool ok = false;
    if(children[node] == 0) return;
    if(tasks % children[node] == 0) {
        for(auto u: LCM[node]) {
            int val = u.first;
            int cnt = 0;
            int tmp = tasks;
            while(tmp % val == 0) {
                cnt++;
                tmp /= val;
            }
            if(cnt < u.second) {
                ok = true;
                break;
            }

        }

        if(ok) {
            for(auto u: adj[node]) {
                if(u != p[node]) {
                    solve(u, tasks / children[node]);
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
    LCM = vector<unordered_map<int,int>>(n + 1);
    p = vector<int>(n + 1);
    children = vector<int>(n + 1);
    factor = vector<int64_t>(n + 1);
    for(int i=2;i<=n;i++) {
        cin >> p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
        children[p[i]]++;
    }

    dfs(1, 1);
    
    int Q;
    cin >> Q;
    while(Q--) {
        int v, w;
        cin >> v >> w;
        ans = 0;
        solve(v, w);
        cout << ans << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    auto start = high_resolution_clock::now();

    int tests = 1;
    // cin >> tests;
    preprocess();

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }

    auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<milliseconds>(stop - start); 
   
    cout << duration.count() << endl; 
    debug() << imie(duration.count());
}