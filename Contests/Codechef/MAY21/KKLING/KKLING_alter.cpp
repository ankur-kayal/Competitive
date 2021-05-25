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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

const int inf = 1e9 +7 ;

/*
Optimisations:

1. Save the transitions for each node ? may reduce complexity for certains cases (Solved)

2. Somehow do a dp that tells in O(1) if the transition is needed ?

*/

void run_cases() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    vector<int> assassins;
    vector<int> depths(N);
    vector<int> positions(N);
    vector<int> parent(N);
    vector<bool> alive(N, true);
    vector<vector<int>> towns(N);
    vector<int> travel_time(N);
    vector<bool> has_another_leaf_above(N, false);
    vector<int> store_transitions(N, -1);
    iota(positions.begin(), positions.end(), 0);
    for(int i=0;i<N-1;i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    function <void(int,int)> find_parent_and_depths = [&](int node, int par) -> void {
        if(adj[node].size() == 1 and node != 0) {
            assassins.push_back(node);
            // towns[node].push_back(node);
        }
        if(adj[node].size() > 2 && node != 0) {
            has_another_leaf_above[node] = has_another_leaf_above[node] | true;
        }
        parent[node] = par;
        for(int child: adj[node]) {
            if(child != par) {
                depths[child] = depths[node] + 1;
                has_another_leaf_above[child] = has_another_leaf_above[node] | has_another_leaf_above[child];
                find_parent_and_depths(child, node);
            }
        }
    };


    find_parent_and_depths(0, -1);
    // debug() << imie(assassins);
    // debug() << imie(alive);
    // for(int i=0;i<N;i++) {
    //     debug() << imie(i) imie(has_another_leaf_above[i]);
    // }
    
    // Somehow do the simulation :(
    unordered_set<int> dead_towns;
    unordered_set<int> vertex_paths;
    auto start_killing = [&](int node) -> int {
        unordered_set<int> current_climb_nodes;
        int current_position = positions[node];
        int transitioned = -1;
        while(parent[current_position] != -1 && has_another_leaf_above[parent[current_position]]) {
            if(store_transitions[parent[current_position]] != -1) {
                transitioned = store_transitions[parent[current_position]];
                break;
            }
            current_position = parent[current_position];
            // for every climb check if there is any assassin present
            if(!towns[current_position].empty()) {
                current_climb_nodes.insert(current_position);
                vertex_paths.insert(current_position);
                transitioned = current_position;
                dead_towns.insert(current_position);
            }
        }
        if(transitioned != -1) {
            for(auto u: current_climb_nodes) {
                store_transitions[u] = transitioned;
            }
        }
        return transitioned;
    };

    int time_taken = -1;
    for(int day=1;day<=N;day++) {
        dead_towns.clear();
        time_taken = day;
        // TODO: replace this with multiset for better time complexity maybe ?
        sort(assassins.rbegin(), assassins.rend(), [&](int assassin1, int assassin2) {
            return depths[positions[assassin1]] < depths[positions[assassin2]];
        });

        // debug() << imie(assassins) imie(positions);

        vector<int> tmp_pos = positions;

        for(int assassin : assassins) {
            towns[positions[assassin]].push_back(assassin);
        }
        for(int assassin : assassins) {
            if(dead_towns.count(positions[assassin])) continue;
            int next_town = start_killing(assassin);
            if(next_town == -1) {
                positions[assassin] = parent[positions[assassin]];
            } else {
                positions[assassin] = next_town;
            }
            travel_time[assassin]++;
        }

        // Mark all dead assassins
        for(auto u: dead_towns) {
            for(auto dead_assassin: towns[u]) {
                alive[dead_assassin] = false;
            }
        }

        // Clear all towns to be populated with updated values
        for(int assassin : assassins) {
            towns[tmp_pos[assassin]].clear();
        }
        vector<int> alive_assassins;
        for(int assassin: assassins) {
            if(alive[assassin]) {
                alive_assassins.push_back(assassin);
            }
        }
        assassins = alive_assassins;
        for(int assassin : assassins) {
            if(positions[assassin] == 0) goto king_killed;
        }
        for(auto u: vertex_paths) {
            store_transitions[u] = -1;
        }
        
    }
    king_killed:
    vector<int> successful_assassins;
    for(int assassin: assassins) {
        if(travel_time[assassin] == time_taken && positions[assassin] == 0) {
            successful_assassins.push_back(assassin);
        }
    }
    assert(time_taken != -1);
    cout << successful_assassins.size() << " " << time_taken << '\n';
    sort(successful_assassins.begin(), successful_assassins.end());
    output_vector(successful_assassins, true);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
    // cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}