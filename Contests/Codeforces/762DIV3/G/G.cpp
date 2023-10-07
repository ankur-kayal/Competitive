#include <algorithm>
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
    int N, K;
    cin >> N >> K;

    vector<int> x(N), y(N), timer(N);

    map<int, vector<pair<int,int>>> xcoor, ycoor;

    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> timer[i];
    }

    for(int i = 0; i < N; i++) {
        xcoor[x[i]].push_back({y[i], i});
        ycoor[y[i]].push_back({x[i], i});
    }

    vector<vector<int>> adj(N);

    for(auto [key, value] : xcoor) {
        sort(value.begin(), value.end());
        debug() << imie(key) imie(value);
        for(int i = 1; i < value.size(); i++) {
            if(value[i].first - value[i - 1].first <= K) {
                int u = value[i].second;
                int v = value[i - 1].second;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }

    for(auto [key, value] : ycoor) {
        sort(value.begin(), value.end());
        debug() << imie(key) imie(value);
        for(int i = 1; i < value.size(); i++) {
            if(value[i].first - value[i - 1].first <= K) {
                int u = value[i].second;
                int v = value[i - 1].second;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
    }

    vector<bool> visited(N);
    vector<int> values;

    function<void(int)> dfs = [&](int node) -> void{
        values.push_back(timer[node]);
        visited[node] = true;
        for(int child: adj[node]) {
            if(!visited[child]) {
                dfs(child);
            }
        }
    };  

    deque<int> component_values;

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            values.clear();
            dfs(i);
            component_values.push_back(*min_element(values.begin(), values.end()));
        }
    }

    sort(component_values.begin(), component_values.end());

    int total_time = 0;

    debug() << imie(component_values);

    while(!component_values.empty()) {
        component_values.pop_back();
        while(!component_values.empty() && component_values.front() <= total_time) {
            component_values.pop_front();
        }
        debug() << imie(total_time) imie(component_values);

        if(!component_values.empty()) {
            total_time++;
        }

    }

    cout << total_time << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}