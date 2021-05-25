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


int highest_bit(int x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}

struct segment_change {
    int64_t to_set;
    static const int64_t SENTINEL = 0;

    // Make sure that the default constructor is the identity segment_change
    segment_change(int64_t _to_set = SENTINEL) : to_set(_to_set) {}

    // resets to the SENTINEL value
    void reset() {
        to_set = SENTINEL;
    }

    bool has_change() const {
        return to_set != SENTINEL;
    }

    // Return the combined result of applying this segment change followed by the `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(to_set + other.to_set);
    }
};

struct segment {
    int64_t sum;

    // Make sure that the default constructor is the identity segment
    segment(int64_t _sum = 0) : sum(_sum) {}

    // checks if the current segment is empty based on the default value
    bool empty() const {
        return sum == 0;
    }

    // evaluating the change on a particular node
    void apply(int length, const segment_change &change) {
        if(change.has_change()) {
            sum = sum + change.to_set * length;
        }
    }

    // merge function
    void join(const segment &other) {
        sum = sum + other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

pair<int, int> right_half[32];

struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void apply_and_combine(int position, int length, const segment_change &change) {
        tree[position].apply(length, change);
        if (position < tree_n) changes[position] = changes[position].combine(change);
    }

    void push_down(int position, int length) {
        if (changes[position].has_change()) {
            apply_and_combine(2 * position, length / 2, changes[position]);
            apply_and_combine(2 * position + 1, length / 2, changes[position]);
            changes[position].reset();
        }
    }

    // Calls push_down for all necessary nodes in order to query the range [a, b).
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = highest_bit(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }

    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }

    // Calls join for all necessary nodes after updating the range [a, b).
    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }

    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1)
                range_op(a++, length);

            if (b & 1)
                right_half[r_size++] = {--b, length};
        }

        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);

        if (needs_join)
            join_all(original_a, original_b);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        debug() << imie(a) imie(b);
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            apply_and_combine(position, length, change);
        });
    }

    vector<segment> to_array() {
        for (int i = 1; i < tree_n; i++)
            push_down(i, tree_n >> highest_bit(i));

        vector<segment> segs(tree_n);

        for (int i = 0; i < tree_n; i++)
            segs[i] = tree[tree_n + i];

        return segs;
    }

    void update_single(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;

        for (int up = highest_bit(tree_n); up > 0; up--)
            push_down(position >> up, 1 << up);

        tree[position] = seg;

        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    // Finds the last subarray starting at `first` that satisifes `should_join` via binary search in O(log n).
    template<typename T_bool>
    int find_last_subarray(T_bool &&should_join, int n, int first = 0) {
        assert(0 <= first && first <= n);
        segment current;

        // Check the degenerate case.
        if (!should_join(current, current))
            return first - 1;

        return y_combinator([&](auto search, int position, int start, int end) -> int {
            if (end <= first) {
                return end;
            } else if (first <= start && end <= n && should_join(current, tree[position])) {
                current.join(tree[position]);
                return end;
            } else if (end - start == 1) {
                return start;
            }

            push_down(position, end - start);
            int mid = (start + end) / 2;
            int left = search(2 * position, start, mid);
            return left < mid ? left : search(2 * position + 1, mid, end);
        })(1, 0, tree_n);
    }
};
 
// Uses segment tree template
struct heavy_light_decomposition {
    vector<int> heavy_child, parent, head, depth, subtree_size, label, order;
    vector<vector<int>> adj;
    vector<pair<int,int>> subtree_segment;
    seg_tree tree;
 
    void init(int n) {
        heavy_child = vector<int>(n);
        parent = vector<int>(n);
        head = vector<int>(n);
        subtree_size = vector<int>(n, 1);
        label = vector<int>(n);
        depth = vector<int>(n);
        subtree_segment = vector<pair<int,int>>(n);
        adj = vector<vector<int>>(n, vector<int>());
        iota(head.begin(), head.end(), 0);
        tree.init(n);
    }
 
    // Add a bi-directional edge from `from` to `to`
    void add_bidirectional_edge(const int &from, const int &to) {
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
 
    // Finds the heavy child of a node and precomputes the depth of each node
    void find_heavy_child(int node, int par) {
        parent[node] = par;
        int max_child_subtree_size = 0;
        heavy_child[node] = node;
 
        for(int child: adj[node]) {
            if(child == par) {
                continue;
            }
            depth[child] = depth[node] + 1;
            find_heavy_child(child, node);
            
            if(subtree_size[child] > max_child_subtree_size) {
                max_child_subtree_size = subtree_size[child];
                heavy_child[node] = child;
            }
            subtree_size[node] += subtree_size[child];
        }
    }
 
    // relabels the heavy nodes in a continuous segment so that later one segment tree 
    // can do the job. The head of each heavy segment is stored in the heavy chain nodes.
    void accumulate_heavy_segments_and_relabel(int node) {
        order.push_back(node);
        label[node] = int(order.size()) - 1;
        subtree_segment[node].first = label[node];
        head[heavy_child[node]] = head[node];
        if(heavy_child[node] != node)
            accumulate_heavy_segments_and_relabel(heavy_child[node]);
 
        for(int child: adj[node]) {
            if(child != heavy_child[node] && child != parent[node]) {
                accumulate_heavy_segments_and_relabel(child);
            }
        }
        subtree_segment[node].second = int(order.size());
    }
 
 
    // O(N) build of the segment tree for heavy light decomposition structure
    void build(const vector<int64_t> &values) {
        find_heavy_child(0, 0);
        accumulate_heavy_segments_and_relabel(0);
        // do segment tree building
        vector<segment> reordered_values(int(values.size()));
        int n = values.size();
        for(int i=0;i<n;i++) {
            reordered_values[i] = segment(values[order[i]]);
        }
 
        tree.build(reordered_values);
    }
 
    // Calculate the defined function along the path from node `u` to node `v`
    // It takes O(log^2(N)) in the worst case
    int64_t query (int u, int v) {
        segment res;
        while(true) {
            int x = head[u];
            int y = head[v];
            if(x == y) {
                int label1 = label[u];
                int label2 = label[v];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                segment tmp = tree.query(label1, label2 + 1);
                res.join(tmp);
                break;
            }
 
            if(depth[x] > depth[y]) {
                int label1 = label[u];
                int label2 = label[x];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                segment tmp = tree.query(label1, label2 + 1);
                res.join(tmp);
                u = parent[x];
            } else {
                int label1 = label[v];
                int label2 = label[y];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                segment tmp = tree.query(label1, label2 + 1);
                res.join(tmp);
                v = parent[y];
            }
        }
        return res.sum;
    }
 
    // Update the nodes along the path from node `u` to node `v` based on the defined function
    // It takes O(log^2(N)) in the worst case
    void update(int u, int v, const int64_t &val) {
        debug() << imie(u) imie(v) imie(val);
        while(true) {
            int x = head[u];
            int y = head[v];
            if(x == y) {
                int label1 = label[u];
                int label2 = label[v];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                tree.update(label1, label2 + 1, segment_change(val));
                break;
            }
 
            if(depth[x] > depth[y]) {
                int label1 = label[u];
                int label2 = label[x];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                tree.update(label1, label2 + 1, segment_change(val));
                u = parent[x];
            } else {
                int label1 = label[v];
                int label2 = label[y];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                tree.update(label1, label2 + 1, segment_change(val));
                v = parent[y];
            }
        }
    }
 
    void update_entire_subtree(int node, const int64_t &val) {
        tree.update(subtree_segment[node].first, subtree_segment[node].second, segment_change(val));
    }
};


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

1. Save the transitions for each node ? may reduce complexity for certains cases

2. Somehow do a dp that tells in O(1) if the transition is needed ?

*/

void run_cases() {
    int N;
    cin >> N;
    heavy_light_decomposition tree;
    tree.init(N);
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
        tree.add_bidirectional_edge(u, v);
    }
    vector<int64_t> tmp(N, 0);
    tree.build(tmp);
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
    debug() << imie(assassins);
    debug() << imie(alive);
    for(int i=0;i<N;i++) {
        debug() << imie(i) imie(has_another_leaf_above[i]);
    }
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

        debug() << imie(assassins) imie(positions);

        vector<int> tmp_pos = positions;
        unordered_set<int> used_pos;
        for(int assassin : assassins) {
            // tree.update(positions[assassin], positions[assassin], 1);
            if(!used_pos.count(positions[assassin])){
                used_pos.insert(positions[assassin]);
                tree.update_entire_subtree(positions[assassin], 1);
            }
            towns[positions[assassin]].push_back(assassin);
        }
        for(int assassin : assassins) {
            if(dead_towns.count(positions[assassin])) continue;
            debug() << imie(assassin) imie(positions[assassin]) imie(tree.query(positions[assassin], positions[assassin]));
            if(tree.query(positions[assassin], positions[assassin]) == 1) {
                positions[assassin] = parent[positions[assassin]];
            } else {
                int next_town = start_killing(assassin);
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
        for(auto u: used_pos) {
            // tree.update(tmp_pos[assassin], tmp_pos[assassin], 0);
            tree.update_entire_subtree(u, -1);
            towns[u].clear();
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
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}