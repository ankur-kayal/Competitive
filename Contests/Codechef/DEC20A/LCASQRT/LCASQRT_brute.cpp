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

vector<int> ans, par, c;
vector<vector<int>> cache;
int cnt,n,p;
vector<vector<int>> LCA;
vector<vector<vector<int>>> L;

void process(vector<int>& res) {
    bool ok = true;

    for(int x=1;x<=n;x++) {
        int tmp = 0;
        for(int i=1;i<=n;i++) {
            for(auto j : L[i][x]) {
                tmp = (tmp + res[i-1] * res[j-1])%p;
            }
        }
        debug() << imie(tmp) imie(c[x]) imie(x) imie(res);
        if(tmp != c[x]) {
            ok = false;
            break;
        }
    }

    if(ok) {
        cnt++;
        ans = res;
        cache.push_back(res);
    }
}

void debugPrint() {
    for(int x=1;x<=n;x++) {
        int tmp = 0;
        debug() << imie(x);
        for(int i=1;i<=n;i++) {
            for(auto j : L[i][x]) {
                debug() << imie(i) imie(j);
            }
        }
    }
}

void genAllCombination(vector<int> &res) {
    for(int i=0;i<p;i++) {
        res.push_back(i);
        if(res.size() == n) {
            process(res);
        }
        else {
            genAllCombination(res);
        }
        res.pop_back();
    }
}

struct LCABinaryLift {
    int lg;
    int n;
    vector<int> depth;
    vector<vector<int>> edges;
    vector<vector<int>> lift;

    void init(int sz) {
        n = sz;
        lg = ceil(log2(sz));
        depth = vector<int>(n);
        edges = vector<vector<int>>(n, vector<int>());
        lift = vector<vector<int>>(n, vector<int>(lg, -1));
    }

    void addEdge(int a, int b) {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    void initLift(int v = 0) {
        depth[v] = 0;
        dfs(v, -1);

        for(int j=1;j<lg;j++) {
            for(int i=0;i<n;i++) {
                if(lift[i][j-1] != -1) {
                    int par = lift[i][j-1];
                    lift[i][j] = lift[par][j-1];
                }
            }
        }
    }

    void dfs(int v, int par) {
        lift[v][0] = par;
        for(auto u: edges[v]) {
            if(u != par) {
                depth[u] = depth[v] + 1;
                dfs(u, v);
            }
        }
    }

    int getKthAncestor(int v, int k) {
        for(int i=lg-1;i>=0;i--) {
            if(v == -1) return v;

            if((1 << i) <= k) {
                v = lift[v][i];
                k -= (1 << i);
            }
        }
        return v;
    }

    int getLCA(int a, int b) {
        if(depth[a] < depth[b]) swap(a,b);
        int d = depth[a] - depth[b];
        int v = getKthAncestor(a,d);

        if(v == b) {
            return v;
        }
        else {
            for(int i=lg-1;i>=0;i--) {
                if(lift[v][i] != lift[b][i]) {
                    v = lift[v][i];
                    b = lift[b][i];
                }
            }
            return lift[b][0];
        }
    }

    int getDistance(int a, int b) {
        int v = getLCA(a,b);
        return depth[a] + depth[b] - 2 * depth[v];
    }
};

LCABinaryLift lc;

void compute() {
    cnt = 0;
    ans.clear();
    ans.push_back(-1);
    vector<int> res;


    lc.initLift(1);
    // init all LCA
    // LCA = vector<vector<int>>(n+1, vector<int>(n+1));
    L = vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>()));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int lca = lc.getLCA(i,j);
            L[i][lca].push_back(j);
        }
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         debug() << imie(i) imie(j) imie(L[i][j]);
    //     }
    // }
    // return;

    vector<int> corr = {37, 92, 72, 76, 20, 90, 25, 12, 81};
    // vector<int> corr = {3, 70, 5, 76, 20, 11, 25, 12, 81};
    // vector<int> corr = {1,2,0,1,1,1};
    process(corr);
    return;
    // debugPrint();
    // return;
    genAllCombination(res);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> p;
        c = vector<int>(n + 1);
        par = vector<int>(n+1);
        lc.init(n + 1);
        par[1] = -1;
        for(int i=2;i<=n;i++) {
            cin >> par[i];
            lc.addEdge(i, par[i]);
        }
        for(int i=1;i<=n;i++) {
            cin >> c[i];
        }

        compute();
        cout << cnt << '\n';
        for(auto u: ans) {
            cout << u << " ";
        }
        cout << '\n';
        for(auto u : cache) {
            debug() << imie(u);
        }
        cerr << "answer: ";
        debug() << imie(ans);
    }


}