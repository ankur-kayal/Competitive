#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int maxN = 2e5 + 10;
vector<vector<int>> divisors;

void generate_divisors(int N) {
    divisors = vector<vector<int>>(N);

    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            divisors[j].push_back(i);
        }
    }
}

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
 
struct Query {
    int l, r, id, X, u;
    int64_t ord;

    Query(): l(), r(), id(), X(), u() {}
    Query(int _l, int _r, int _id, int _X, int _u): l(_l), r(_r), id(_id), X(_X), u(_u), ord(gilbertOrder(l, r, 21, 0)) {}

    bool operator<(const Query& other) const {
        return ord < other.ord;
    }
};


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

void run_cases() {
    int N, Q;
    cin >> N >> Q;


    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    debug() << imie(A);

    const int maxA = 3e5;

    vector<int> values(maxA);

    vector<vector<int>> adj(N);
    vector<int> in(N), out(N), euler;
    int timer = 0;

    auto add_edge = [&](int u, int v) -> void {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    for(int i = 1; i < N; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        add_edge(x, y);
    }

    debug() << imie(adj);


    function<void(int,int)> dfs = [&](int node, int par) -> void {
        in[node]=timer++;
        euler.push_back(A[node]);
        for(int child: adj[node]) {
            if(child != par) {
                dfs(child, node);
            }
        }
        out[node] = timer++;
        euler.push_back(A[node]);
    };

    dfs(0, -1);

    debug() << imie(euler);

    vector<Query> queries;


    for(int i = 0; i < Q; i++) {
        int u, v, X;
        cin >> u >> v >> X;
        --u, --v;

        queries.push_back(Query(in[u], out[u] + 1, i, X, u));
        queries.push_back(Query(in[v], out[v] + 1, i, X, v));
    }

    vector<vector<pair<int,int>>> answers(Q);


    sort(queries.begin(), queries.end());
 
    int global_left = 0, global_right = 0;
 
    auto add_element = [&](int64_t element) {
        values[element]++;
    };
 
    auto delete_element = [&](int64_t element) {
        values[element]--;
    };
 
    for(Query q: queries) {
 
        while(global_left < q.l) {
            delete_element(euler[global_left]);
            global_left++;
        }
 
        while(global_left > q.l) {
            global_left--;
            add_element(euler[global_left]);
        }
 
        while(global_right < q.r) {
            add_element(euler[global_right]);
            global_right++;
        }
 
        while(global_right > q.r) {
            global_right--;
            delete_element(euler[global_right]);
        }
 
        int score = 0;

        // debug() << imie(divisors[q.X]) imie(q.X);
 
        for(auto u: divisors[q.X]) {
            score += values[u];
        }

        debug() << imie(q.id) imie(score) imie(q.u + 1) imie(q.X) imie(q.l) imie(q.r);

        for(int i = 1; i <= 5; i++) {
            debug() << imie(i) imie(values[i]);
        }

        answers[q.id].emplace_back(score, q.u + 1);
    }

    for(auto u: answers) {
        if(u[0].first > u[1].first) {
            cout << u[0].second << '\n';
        } else if(u[0].first < u[1].first) {
            cout << u[1].second << '\n';
        } else {
            cout << "Draw" << '\n';
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    generate_divisors(maxN);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}