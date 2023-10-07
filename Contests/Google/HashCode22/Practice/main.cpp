#include <bits/stdc++.h>
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

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for(auto &u: A)
        cin >> u;
    for(auto &u: B)
        cin >> u;

    vector<vector<int>> adj(N);

    vector<pair<int,int>> orderA;
    for(int i = 0; i < N; i++) {
        orderA.emplace_back(A[i], i);
    }

    sort(orderA.begin(), orderA.end());

    for(int i = 1; i < N; i++) {
        int u = orderA[i].second;
        int v = orderA[i-  1].second;
        adj[u].push_back(v);
    }

    vector<pair<int,int>> orderB;
    for(int i = 0; i < N; i++) {
        orderB.emplace_back(B[i], i);
    }

    sort(orderB.begin(), orderB.end());

    for(int i = 1; i < N; i++) {
        int u = orderB[i].second;
        int v = orderB[i-  1].second;
        adj[u].push_back(v);
    }

    vector<vector<int>> components;
    vector<int> visited(N);
    vector<int> in(N), low(N);
    vector<bool> inStack(N);
    vector<int> inStackNodes;

    int timer = 0;

    function<void(int)> dfs = [&](int node) -> void {
        in[node] = low[node] = timer++;
        visited[node] = true;
        inStack[node] = true;
        inStackNodes.push_back(node);
        for(int child: adj[node]) {
            if(visited[child] && inStack[child]) {
                low[node] = min(low[node], in[child]);
            } else {
                if(!visited[child]) {
                    dfs(child);
                    if(inStack[child]) {
                        low[node] = min(low[node], low[child]);
                    }
                }
            }
        }

        if(in[node] == low[node]) {
            vector<int> component;
            while(true) {
                int u = inStackNodes.back();
                inStackNodes.pop_back();
                component.push_back(u);
                inStack[u] = false;
                if(u == node) {
                    break;
                }
            }
            components.push_back(component);
        }
    };  

    int largest = orderA.back().second;
    dfs(largest);

    debug() << imie(adj);
    debug() << imie(components);

    string answer = string(N, '0');

    if(count(visited.begin(), visited.end(), true) == N) {
        for(auto u: components) {
            if(count(u.begin(), u.end(), largest)) {
                for(auto v: u) {
                    answer[v] = '1';
                }
                break;
            }
        }
    }

    cout << answer << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}