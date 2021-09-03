#include <bits/stdc++.h>
#include <utility>
using namespace std;

#define nl '\n'


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

// hash is i * r + c


void run_cases() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> crossword(N, vector<char>(M));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> crossword[i][j];
        }
    }

    vector<vector<int>> adj(N * M);

    auto hash = [&](int i, int j) {
        return (i * M + j);
    };

    auto decode = [&](int hash_value) {
        return make_pair(hash_value / M, hash_value % M);
    };

    auto add_edge = [&](int u, int v) {

        // debug() << imie(decode(u)) imie(decode(v));
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    auto compute_vertical = [&](int i, int j) {
        if(crossword[i][j] == '#') {
            return;
        }
        bool ok = false;
        if(i - 1 < 0) {
            ok = true;
        } else if(crossword[i - 1][j] == '#') {
            ok = true;
        }

        deque<int> indices;

        if(ok) {
            for(int r = i; r < N; r++) {
                if(crossword[r][j] != '#') {
                    // debug() << imie(r) imie(j);
                    indices.push_back(hash(r, j));
                } else {
                    break;
                }
            }
        }

        // debug() << imie(i) imie(j) imie(indices);

        while(indices.size() > 1) {
            int u = indices.front();
            int v = indices.back();
            indices.pop_front();
            indices.pop_back();
            add_edge(u, v);
        }


    };

    auto compute_horizontal = [&](int i, int j) {
        if(crossword[i][j] == '#') {
            return;
        }
        bool ok = false;
        if(j - 1 < 0) {
            ok = true;
        } else if(crossword[i][j - 1] == '#') {
            ok = true;
        }

        deque<int> indices;

        if(ok) {
            for(int c = j; c < M; c++) {
                if(crossword[i][c] != '#') {
                    indices.push_back(hash(i, c));
                } else {
                    break;
                }
            }
        }

        while(indices.size() > 1) {
            int u = indices.front();
            int v = indices.back();
            indices.pop_front();
            indices.pop_back();
            add_edge(u, v);
        }
    };

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            compute_vertical(i, j);
            compute_horizontal(i, j);
        }
    }


    vector<int> components;
    vector<bool> vis(N * M);

    function<void(int)> dfs = [&](int node) -> void {
        components.push_back(node);
        vis[node] = true;
        for(int child: adj[node]) {
            if(!vis[child]) {
                dfs(child);
            }
        }
    };

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(crossword[i][j] == '#') {
                vis[hash(i, j)] = true;
            }
        }
    }

    int filled = 0;

    int cnt = 0;


    for(int i = 0; i < N * M; i++) {
        if(!vis[i]) {
            components.clear();
            dfs(i);

            char value = '.';
            int r, c;

            // debug() << "Component: " << cnt++ << '\n';

            // for(auto u: components) {
            //     debug() << imie(decode(u));
            // }

            for(auto u: components) {
                tie(r, c) = decode(u);

                if(crossword[r][c] != '.') {
                    value = crossword[r][c];
                    break;
                }
            }

            for(auto u: components) {
                tie(r, c) = decode(u);
                if(crossword[r][c] != value) {
                    filled++;
                }
                crossword[r][c] = value;
            }
        }
    }

    cout << filled << '\n';

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << crossword[i][j];
        }
        cout << '\n';
    }
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