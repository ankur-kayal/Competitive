#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

/*
Strategies:
1. Do a dfs or bfs to find all recheable nodes from 1, and discard all unreacheable nodes now
2. Do a topological sort on recheable nodes and find all cycles in the graph
3. Do a multisource bfs on the cycle nodes and find all nodes that are recheable from the nodes
4. Do a dfs on the remaining nodes and find which nodes have 1 path or more than one path
*/

void run_cases() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<int> indeg(N, 0);
    vector<bool> unreacheable(N, true);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    // find all unrecheable nodes from 1 with a bfs 
    vector<int> q{0};
    unreacheable[0] = false;
    for(int i = 0; i < q.size(); i++) {
        int x = q[i];
        for(auto u: adj[x]) {
            if(unreacheable[u]) {
                unreacheable[u] = false;
                q.push_back(u);
            }
        }
    }

    // remove the unrecheable nodes from the existing graph
    for(int i = 0; i < N; i++) {
        if(unreacheable[i]) {
            for(int x : adj[i]) {
                indeg[x]--;
            }
        }
    }

    // Do topological sort to find the cycle nodes
    vector<bool> in_cycle(N, false);
    vector<bool> vis(N, false);
    q.clear();
    for(int i = 0; i < N; i++) {
        if(!unreacheable[i] && indeg[i] == 0) {
            q.push_back(i);
        }
    }


    for(int i = 0; i < q.size(); i++) {
        int x = q[i];
        vis[x] = true;
        for(int y: adj[x]) {
            indeg[y]--;
            if(indeg[y] == 0) {
                q.push_back(y);
            }
        }
    }

    // Multisource bfs to find all nodes recheable from cycle nodes
    q.clear();
    for(int i = 0; i < N; i++) {
        if(!unreacheable[i] && !vis[i]) {
            in_cycle[i] = true;
            q.push_back(i);
        }
    }

    for(int i = 0; i < q.size(); i++) {
        int x = q[i];
        for(int y: adj[x]) {
            if(!in_cycle[y]) {
                q.push_back(y);
                in_cycle[y] = true;
            }
        }
    }

    vector<int> paths(N, -1);
    paths[0] = 1;
    q.clear();
    if(!in_cycle[0]) {
        q.push_back(0);
    }

    // Count paths for all other vertices
    for(int i = 0; i < q.size(); i++) {
        int x = q[i];
        for(int y: adj[x]) {
            if(!in_cycle[y]) {
                if(paths[y] == -1) {
                    paths[y] = paths[x];
                    q.push_back(y);
                } else if(paths[y] == 1) {
                    paths[y] = 2;
                    q.push_back(y);
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        if(unreacheable[i]) {
            cout << 0;
        } else if(in_cycle[i]) {
            cout << -1;
        } else {
            cout << paths[i];
        }
        cout << (i == N - 1 ? '\n' : ' ');
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}