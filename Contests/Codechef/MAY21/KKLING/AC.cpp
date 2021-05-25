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
        parent[node] = par;
        for(int child: adj[node]) {
            if(child != par) {
                depths[child] = depths[node] + 1;
                find_parent_and_depths(child, node);
            }
        }
    };


    find_parent_and_depths(0, -1);
    debug() << imie(assassins);
    debug() << imie(alive);
    // Somehow do the simulation :(

    auto start_killing = [&](int node) -> int {
        int current_position = positions[node];
        int transitioned = -1;
        while(parent[current_position] != -1) {
            current_position = parent[current_position];
            // for every climb check if there is any assassin present
            for(auto people_present: towns[current_position]) {
                debug() << imie(people_present);
                alive[people_present] = false;
                transitioned = current_position;
            }
        }
        return transitioned;
    };

    int time_taken = -1;
    for(int day=1;day<=N;day++) {
        time_taken = day;
        sort(assassins.rbegin(), assassins.rend(), [&](int assassin1, int assassin2) {
            return make_pair(depths[positions[assassin1]], assassin1) < make_pair(depths[positions[assassin2]], assassin2);
        });

        debug() << imie(assassins) imie(positions);

        vector<int> tmp_pos = positions;

        for(int assassin : assassins) {
            towns[positions[assassin]].push_back(assassin);
        }
        for(int assassin : assassins) {
            if(!alive[assassin]) continue;
            int next_town = start_killing(assassin);
            if(next_town == -1) {
                positions[assassin] = parent[positions[assassin]];
            } else {
                positions[assassin] = next_town;
            }
            travel_time[assassin]++;
        }

        for(int assassin : assassins) {
            towns[tmp_pos[assassin]].clear();
            towns[positions[assassin]].clear();
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
}