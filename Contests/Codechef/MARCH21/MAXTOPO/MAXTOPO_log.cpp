#include <bits/stdc++.h>
using namespace std;

// template from https://codeforces.com/contest/1493/submission/109248875

template<const int &MOD>
struct _m_int {
    int val;
 
    _m_int(int64_t v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(uint64_t v) {
        if (v >= MOD) v %= MOD;
        val = int(v);
    }
 
    _m_int(int v) : _m_int(int64_t(v)) {}
    _m_int(unsigned v) : _m_int(uint64_t(v)) {}
 
    explicit operator int() const { return val; }
    explicit operator unsigned() const { return val; }
    explicit operator int64_t() const { return val; }
    explicit operator uint64_t() const { return val; }
    explicit operator double() const { return val; }
    explicit operator long double() const { return val; }
 
    _m_int& operator+=(const _m_int &other) {
        val -= MOD - other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    _m_int& operator-=(const _m_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
 
    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return unsigned(x % m);
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }
 
    _m_int& operator*=(const _m_int &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }
 
    _m_int& operator/=(const _m_int &other) {
        return *this *= other.inv();
    }
 
    friend _m_int operator+(const _m_int &a, const _m_int &b) { return _m_int(a) += b; }
    friend _m_int operator-(const _m_int &a, const _m_int &b) { return _m_int(a) -= b; }
    friend _m_int operator*(const _m_int &a, const _m_int &b) { return _m_int(a) *= b; }
    friend _m_int operator/(const _m_int &a, const _m_int &b) { return _m_int(a) /= b; }
 
    _m_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
 
    _m_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
 
    _m_int operator++(int) { _m_int before = *this; ++*this; return before; }
    _m_int operator--(int) { _m_int before = *this; --*this; return before; }
 
    _m_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
 
    friend bool operator==(const _m_int &a, const _m_int &b) { return a.val == b.val; }
    friend bool operator!=(const _m_int &a, const _m_int &b) { return a.val != b.val; }
    friend bool operator<(const _m_int &a, const _m_int &b) { return a.val < b.val; }
    friend bool operator>(const _m_int &a, const _m_int &b) { return a.val > b.val; }
    friend bool operator<=(const _m_int &a, const _m_int &b) { return a.val <= b.val; }
    friend bool operator>=(const _m_int &a, const _m_int &b) { return a.val >= b.val; }
 
    static const int SAVE_INV = int(1e6) + 5;
    static _m_int save_inv[SAVE_INV];
 
    static void prepare_inv() {
        // Make sure MOD is prime, which is necessary for the inverse algorithm below.
        for (int64_t p = 2; p * p <= MOD; p += p % 2 + 1)
            assert(MOD % p != 0);
 
        save_inv[0] = 0;
        save_inv[1] = 1;
 
        for (int i = 2; i < SAVE_INV; i++)
            save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
    }
 
    _m_int inv() const {
        if (save_inv[1] == 0)
            prepare_inv();
 
        if (val < SAVE_INV)
            return save_inv[val];
 
        _m_int product = 1;
        int v = val;
 
        while (v >= SAVE_INV) {
            product *= MOD - MOD / v;
            v = MOD % v;
        }
 
        return product * save_inv[v];
    }
 
    _m_int pow(int64_t p) const {
        if (p < 0)
            return inv().pow(-p);
 
        _m_int a = *this, result = 1;
 
        while (p > 0) {
            if (p & 1)
                result *= a;
 
            p >>= 1;
 
            if (p > 0)
                a *= a;
        }
 
        return result;
    }
 
    friend ostream& operator<<(ostream &os, const _m_int &m) {
        return os << m.val;
    }
};
 
template<const int &MOD> _m_int<MOD> _m_int<MOD>::save_inv[_m_int<MOD>::SAVE_INV];
 
extern const int MOD = int(1e9) + 7;
using mod_int = _m_int<MOD>;

vector<vector<int>> dag,adj;

mod_int ans;
vector<int> subtree;
double log_ans = 0;

void init(int n) {
    dag = vector<vector<int>>(n + 1);
    ans = 0;
    subtree = vector<int>(n + 1);
}

void make_dag(int node, int par) {
    for(int child: adj[node]) {
        if(child != par){
            make_dag(child, node);
            dag[child].push_back(node);
        }
    }
}

void generate_toposort() {

}

void dfs(int node, int par) {
    subtree[node] = 1;
    for(auto child: adj[node]) {
        if(child != par) {
            dfs(child, node);
            subtree[node] += subtree[child];
        }
    }
}

const int maxN = 1e6;
vector<mod_int> facts(maxN, 1);
vector<double> logs(maxN + 1, 0);

double eps = 1e-9;

// https://codeforces.com/blog/entry/57593
vector<int> Centroid(const vector<vector<int>> &g) {
    int n = g.size() - 1;
    vector<int> centroid;
    vector<int> size(n + 1);
    function<void (int, int)> dfs = [&](int u, int prev) {
        size[u] = 1;
        bool is_centroid = true;
        for (auto v : g[u]) if (v != prev) {
                dfs(v, u);
                size[u] += size[v];
                if (size[v] > n / 2) is_centroid = false;
        }
        if (n - size[u] > n / 2) is_centroid = false;
        if (is_centroid) centroid.push_back(u);
    };
    dfs(1, -1);
    return centroid;
}

void run_case() {
    int n,k;
    cin >> n >> k;
    adj = vector<vector<int>>(n + 1);
    vector<int> degree(n + 1);
    vector<pair<double,pair<int, int>>> order;
    for(int i=1;i<=n-1;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    vector<int> degree_order;
    for(auto u: degree) {
        degree_order.push_back(u);
    }
    sort(degree_order.rbegin(), degree_order.rend());

    vector<int> chosen;
    for(int i=1;i<=n;i++) {
        if(degree[i] == degree_order[0]) {
            chosen.push_back(i);
        }
    }
    chosen = Centroid(adj);
    vector<int> tmp;
    if(chosen.size() < k) {
        assert(chosen.size() == 1);
        if(adj[chosen[0]].size() > 100) {
            chosen.push_back(*max_element(adj[chosen[0]].begin(), adj[chosen[0]].end()));
        }
        else {
            for(auto u: adj[chosen[0]]) {
                chosen.push_back(u);
            }
        }
        
    }

    for(auto node: chosen) {
    // {
        // int node = chosen[0];
        init(n);
        dfs(node, node);
        ans = facts[n];
        double magnitude = logs[n];
        for(int i=1;i<=n;i++) {
            ans /= subtree[i];
            magnitude -= log10(subtree[i]);
        }
        order.emplace_back(make_pair(magnitude, make_pair(ans, node)));
    }

    sort(order.begin(), order.end(), [&](auto a, auto b) {
        if(abs(a.first - b.first) < eps) {
            return a.second > b.second;
        }
        else if(a.first > b.first) {
            return true;
        }
        return false;
    });

    cout << order[k-1].second.second << " " << order[k-1].second.first << '\n';


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    for(int i=1;i<maxN;i++) {
        facts[i] = facts[i-1] * i;
    }
    for(int i=2;i<maxN;i++) {
        logs[i] = logs[i-1] + log10(i);
    }

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_case();
    }
}