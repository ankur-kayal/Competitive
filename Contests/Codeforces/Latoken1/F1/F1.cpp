#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

struct SCC {
    vector<vector<int>> adj;
    vector<vector<int>> comp;

    int N;
    int idx, cs;
    vector<bool> u;
    vector<int> pre, low, map;
    deque<int> s;

    SCC(int nodes) {
        N = nodes;
        adj = vector<vector<int>>(nodes);
    }

    void add_edge(int from, int to) {
        adj[from].push_back(to);
    }

    vector<int> create_mapping() {
        comp = vector<vector<int>>(N);
        idx = 1; cs = 0;
        pre = vector<int>(N);
        low = vector<int>(N);
        map = vector<int>(N);
        u = vector<bool>(N);
        for(int i = 0; i < N; i++) {
            if(pre[i] == 0) {
                dfs(i);
            }
        }
        return map;
    }

    void dfs(int v) {
        pre[v] = low[v] = idx++;
        s.push_back(v);
        u[v] = true;
        for(int to: adj[v]) {
            if(pre[to] == 0) {
                dfs(to);
                low[v] = min(low[v], low[to]);
            } else if(u[to]) {
                low[v] = min(low[v], pre[to]);
            }
        }
        if(low[v] == pre[v]) {
            int next;
            do {
                next = s.back();
                u[next] = false;
                map[next] = cs;
                comp[cs].push_back(next);
                s.pop_back();
            } while(next != v);
            cs++;
        }
    }

    // Make sure to call create_mapping() before calling this function.
    // Function returns a new graph such that all SCCs are
    // compressed into one node and only the edges connecting
    // two components are in the new graph.
    // nodeMapping is an integer array that will store the mapping
    // for each node in the old graph into the new graph.

    vector<vector<int>> compressSCC() {
        vector<vector<int>> g(cs);
        vector<int> added(cs, -1);
        for(int i = 0; i < cs; i++) {
            for(int v: comp[i]) {
                for(int to: adj[v]) {
                    int map_to = map[to];
                    if(map_to != i && added[map_to] != i) {
                        g[i].push_back(map_to);
                        added[map_to] = i;
                    }
                }
            }
        }
        return g;
    }
};

void run_cases() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> board(w, vector<char>(h));
    vector<vector<int>> id(w, vector<int>(h, -1));
    int nNodes = 0;

    for(int y = 0; y < h; y++) {
        for(int x = 0; x < w; x++) {
            cin >> board[x][y];
        }
    }

    for(int y = h - 1; y >= 0; y--) {
        for(int x = 0; x < w; x++) {
            if(board[x][y] == '#') {
                id[x][y] = nNodes++;
            }
        }
    }

    SCC scc(nNodes);

    vector<int> topInX(w, -1);

    for(int y = h - 1; y >= 0; y--) {
        for(int x = 0; x < w; x++) {
            if(board[x][y] == '#') {
                if(topInX[x] != -1) {
                    scc.add_edge(id[x][y], topInX[x]);
                }
                if(x != 0 && topInX[x - 1] != -1) {
                    scc.add_edge(id[x][y], topInX[x - 1]);
                }

                if(x != w - 1) {
                    if(board[x + 1][y] == '#') {
                        scc.add_edge(id[x][y], id[x + 1][y]);
                    } else if(topInX[x + 1] != -1) {
                        scc.add_edge(id[x][y], topInX[x + 1]);
                    }
                }

                if (y != 0 && board[x][y - 1] == '#'){
                    scc.add_edge(id[x][y], id[x][y - 1]);
                } 
                topInX[x] = id[x][y];
            }
        }
    }

    vector<int> map = scc.create_mapping();

    vector<vector<int>> comp = scc.compressSCC();

    vector<int> indegree(comp.size(), 0);
    for(auto edges: comp) {
        for(int v: edges) {
            indegree[v]++;
        }
    }

    cout << count(indegree.begin(), indegree.end(), 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}