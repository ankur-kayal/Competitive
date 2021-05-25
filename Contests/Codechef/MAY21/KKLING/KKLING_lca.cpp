#include <algorithm>
#include <bits/stdc++.h>
#include <time.h>
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

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;
 
    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }
 
    static int highest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }
 
    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }
 
    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = highest_bit(n) + 1;
        range_low.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }
 
    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = highest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }
 
    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};
 
struct LCA {
    int n = 0;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end, postorder;
    vector<int> tour_list, rev_tour_list;
    vector<int> heavy_root;
    RMQ<int> rmq;
    bool built;
 
    LCA(int _n = 0) {
        init(_n);
    }
 
    // Warning: this does not call build().
    LCA(const vector<vector<int>> &_adj) {
        init(_adj);
    }
 
    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        postorder.resize(n);
        tour_list.resize(n);
        heavy_root.resize(n);
        built = false;
    }
 
    // Warning: this does not call build().
    void init(const vector<vector<int>> &_adj) {
        init(int(_adj.size()));
        adj = _adj;
    }
 
    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    int degree(int v) const {
        return int(adj[v].size()) + (built && parent[v] >= 0);
    }
 
    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;
 
        // Erase the edge to parent.
        adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());
 
        for (int child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }
 
        // Heavy-light subtree reordering.
        sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
            return subtree_size[a] > subtree_size[b];
        });
    }
 
    int tour, post_tour;
 
    void tour_dfs(int node, bool heavy) {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
        bool heavy_child = true;
 
        for (int child : adj[node]) {
            tour_dfs(child, heavy_child);
            euler.push_back(node);
            heavy_child = false;
        }
 
        tour_end[node] = tour;
        postorder[node] = post_tour++;
    }
 
    void build(int root = -1, bool build_rmq = true) {
        parent.assign(n, -1);
 
        if (0 <= root && root < n)
            dfs(root, -1);
 
        for (int i = 0; i < n; i++)
            if (i != root && parent[i] < 0)
                dfs(i, -1);
 
        tour = post_tour = 0;
        euler.clear();
        euler.reserve(2 * n);
 
        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                // Add a -1 in between connected components to help us detect when nodes aren't connected.
                euler.push_back(-1);
            }
 
        rev_tour_list = tour_list;
        reverse(rev_tour_list.begin(), rev_tour_list.end());
        assert(int(euler.size()) == 2 * n);
        vector<int> euler_depths;
        euler_depths.reserve(euler.size());
 
        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);
 
        if (build_rmq)
            rmq.build(euler_depths);
 
        built = true;
    }
 
    pair<int, array<int, 2>> get_diameter() const {
        assert(built);
 
        // We find the maximum of depth[u] - 2 * depth[x] + depth[v] where u, x, v occur in order in the Euler tour.
        pair<int, int> u_max = {-1, -1};
        pair<int, int> ux_max = {-1, -1};
        pair<int, array<int, 2>> uxv_max = {-1, {-1, -1}};
 
        for (int node : euler) {
            if (node < 0) break;
            u_max = max(u_max, {depth[node], node});
            ux_max = max(ux_max, {u_max.first - 2 * depth[node], u_max.second});
            uxv_max = max(uxv_max, {ux_max.first + depth[node], {ux_max.second, node}});
        }
 
        return uxv_max;
    }
 
    // Note: returns -1 if `a` and `b` aren't connected.
    int get_lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];
 
        if (a > b)
            swap(a, b);
 
        return euler[rmq.query_index(a, b + 1)];
    }
 
    bool is_ancestor(int a, int b) const {
        return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
    }
 
    bool on_path(int x, int a, int b) const {
        return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
    }
 
    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }
 
    // Returns the child of `a` that is an ancestor of `b`. Assumes `a` is a strict ancestor of `b`.
    int child_ancestor(int a, int b) const {
        assert(a != b);
        assert(is_ancestor(a, b));
 
        // Note: this depends on RMQ breaking ties by latest index.
        int child = euler[rmq.query_index(first_occurrence[a], first_occurrence[b] + 1) + 1];
        assert(parent[child] == a);
        assert(is_ancestor(child, b));
        return child;
    }
 
    int get_kth_ancestor(int a, int k) const {
        while (a >= 0) {
            int root = heavy_root[a];
 
            if (depth[root] <= depth[a] - k)
                return tour_list[tour_start[a] - k];
 
            k -= depth[a] - depth[root] + 1;
            a = parent[root];
        }
 
        return a;
    }
 
    int get_kth_node_on_path(int a, int b, int k) const {
        int anc = get_lca(a, b);
        int first_half = depth[a] - depth[anc];
        int second_half = depth[b] - depth[anc];
        assert(0 <= k && k <= first_half + second_half);
 
        if (k < first_half)
            return get_kth_ancestor(a, k);
        else
            return get_kth_ancestor(b, first_half + second_half - k);
    }
 
    // Note: this is the LCA of any two nodes out of three when the third node is the root.
    // It is also the node with the minimum sum of distances to all three nodes (the centroid of the three nodes).
    int get_common_node(int a, int b, int c) const {
        // Return the deepest node among lca(a, b), lca(b, c), and lca(c, a).
        int x = get_lca(a, b);
        int y = get_lca(b, c);
        int z = get_lca(c, a);
        x = depth[y] > depth[x] ? y : x;
        x = depth[z] > depth[x] ? z : x;
        return x;
    }
 
    // Given a subset of k tree nodes, computes the minimal subtree that contains all the nodes (at most 2k - 1 nodes).
    // Returns a list of {node, parent} for every node in the subtree. Runs in O(k log k).
    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};
 
        auto &&compare_tour = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), compare_tour);
        int k = int(nodes.size());
 
        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));
 
        sort(nodes.begin() + k, nodes.end(), compare_tour);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result = {{nodes[0], -1}};
 
        for (int i = 1; i < int(nodes.size()); i++)
            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));
 
        return result;
    }
};

struct union_find {
    struct node {
        int parent, rank, size;
        node (int id = 0) : parent(id), rank(0), size(1) {}
    };

    mutable std::vector<node> data;

    union_find(int SZ = 0) : data(SZ) {
        iota(data.begin(), data.end(), 0);
    }

    // Returns the root of the component containing i
    int find(int i) const {
        if (i != data[i].parent)
            data[i].parent = find(data[i].parent);
        return data[i].parent;
    }

    bool is_root(int i) const {
        return i == find(i);
    }

    node& root_node(int i) const {
        return data[find(i)];
    }

    /* Unites the components containing a and b if they are different.
     * Returns a boolean indicating whether a and b were in different components.
     */
    bool unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return false;

        if (data[a].rank < data[b].rank)
            std::swap(a, b);

        data[b].parent = a;
        data[a].size += data[b].size;
        if (data[a].rank == data[b].rank)
            data[a].rank++;

        return true;
    }

    friend void pr(const union_find& u) {
        std::cout << "{";
        bool first = 1;
        for (int i = 0; i < int(u.data.size()); i++) {
            if (u.is_root(i)) {
                if (!first) std::cout << ", ";
                else first = 0;
                std::cout << "[ " << i << " | rank=" << u.data[i].rank
                    << " size=" << u.data[i].size << " ]";
            }
        }
        std::cout << "}";
    }
};

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_cases() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    vector<int> deg(N);
    vector<int> parent(N, -1);
    vector<int> position(N);
    vector<int> values(N, -1);
    vector<int> depth(N);
    vector<bool> can_kill(N);
    for(int i=1;i<=N-1;i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    union_find uf(N);
    LCA tree;
    tree.init(adj);
    tree.build();

    function<void(int,int)> dfs = [&](int node, int par) -> void {
        if(par != -1) {
            parent[node] = par;
        }
        for(int child: adj[node]) {
            if(child != par) {
                depth[child] = depth[node] + 1;
                dfs(child, node);
            }
        }
    };

    dfs(0, -1);

    // Contains the town in which the assassin is currently in
    vector<int> assassins;
    for(int i=0;i<N;i++) {
        if(adj[i].size() == 1 && i != 0) {
            values[i] = i;
            assassins.push_back(i);
        }
    }

    int travel_time = 0;

    while(true) {
        // debug() << imie(values);
        // debug() << imie(deg);
        // debug() << imie(assassins);
        
        assert(travel_time <= N);
        travel_time++;
        vector<int> will_be_killed;
        vector<int> leaf_assassins;
        vector<int> alive_assassins;
        vector<int> killing_depths;
        for(int assassin: assassins) {
            if(deg[assassin] != 1) {
                will_be_killed.push_back(assassin);
                can_kill[assassin] = true;
                killing_depths.push_back(depth[assassin]);
                values[assassin] = -1;
            } else {
                leaf_assassins.push_back(assassin);
            }
        }

        // There is no assassin ahead of each other in the same path
        if(will_be_killed.empty()) {
            for(int i=0;i<assassins.size();i++) {
                int tmp_value = values[assassins[i]];
                assassins[i] = parent[assassins[i]];
                deg[assassins[i]]--;
                if(values[assassins[i]] == -1) {
                    values[assassins[i]] = uf.find(tmp_value);
                    alive_assassins.push_back(assassins[i]);
                } else {
                    uf.unite(uf.find(tmp_value), uf.find(values[assassins[i]]));
                }
            }
        } else {
            // There is some assassin ahead of someone, so needs to be killed
            sort(killing_depths.begin(), killing_depths.end());
            killing_depths.resize(unique(killing_depths.begin(), killing_depths.end()) - killing_depths.begin());
            // debug() << imie(killing_depths);
            for(auto u: leaf_assassins) {
                bool killed_someone = false;
                pair<int,int> best = {10000000, -1};
                for(auto v: killing_depths) {
                    if(v >= depth[u]) {
                        break;
                    }
                    int k = depth[u] - v;
                    int kth_ancestor = tree.get_kth_ancestor(u, k);
                    // debug() << imie(u) imie(k) imie(kth_ancestor) imie(can_kill[kth_ancestor]);
                    if(can_kill[kth_ancestor]) {
                        best = min(best, {v, kth_ancestor});
                        killed_someone = true;
                        deg[kth_ancestor] = 1;
                        break;

                    }
                }
                if(killed_someone) {
                    // debug() << imie(best) imie(u);
                    assert(best.second != -1);
                    if(values[best.second] == -1) {
                        values[best.second] = uf.find(values[u]);
                        alive_assassins.push_back(best.second);
                    } else {
                        uf.unite(uf.find(values[u]), uf.find(values[best.second]));
                    }
                 } else {
                    int assassin = parent[u];
                    deg[assassin]--;
                    if(values[assassin] == -1) {
                        values[assassin] = uf.find(values[u]);
                        alive_assassins.push_back(assassin);
                    }
                    else {
                        uf.unite(uf.find(values[u]), uf.find(values[assassin]));
                    }
                }
                
            }
            for(auto u: will_be_killed) {
                can_kill[u] = false;
            }
        }

        // debug() << imie(values);
        // debug() << nl;

        assassins = alive_assassins;
        if(values[0] != -1) {
            break;
        }

    }

    // pr(uf);

    int killer = uf.find(values[0]);
    vector<int> killers;
    for(int i=0;i<N;i++) {
        // debug() << imie(uf.find(i)) imie(killer);
        if(uf.find(i) == killer) {
            killers.push_back(i);
        }
    }

    cout << killers.size() << " " << travel_time << '\n';
    sort(killers.begin(), killers.end());
    output_vector(killers, 1);

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
    debug() << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    // assert(1000 * clock() / CLOCKS_PER_SEC <= 4000);
}