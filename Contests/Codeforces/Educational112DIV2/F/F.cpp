#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

int highest_bit(int x) {
    return x == 0 ? -1 : 31 - __builtin_clz(x);
}

struct segment_change {
    int64_t to_set;

    // Make sure that the default constructor is the identity segment_change
    segment_change(int64_t _to_set = -1) : to_set(_to_set) {}

    void reset() {
        to_set = -1;
    }

    bool has_change() const {
        return to_set != -1;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(other.to_set);
    }
};

struct segment {
    int64_t sum;

    // Make sure that the default constructor is the identity segment
    segment(int64_t _sum = 0) : sum(_sum) {}

    bool empty() const {
        return sum == 0;
    }

    // lazy propagation apply to the particular node
    void apply(int length, const segment_change &change) {
        if(change.has_change()) {
            sum = change.to_set;
        }
    }

    void join(const segment &other) {
        sum = max(sum, other.sum);
    }

    // merge function
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
    int N;
 
    void init(int n) {
        N = n;
        heavy_child = vector<int>(n);
        parent = vector<int>(n);
        head = vector<int>(n);
        subtree_size = vector<int>(n, 1);
        label = vector<int>(n);
        depth = vector<int>(n);
        subtree_segment = vector<pair<int,int>>(n);
        adj = vector<vector<int>>(n, vector<int>());
        iota(head.begin(), head.end(), 0);
        iota(parent.begin(), parent.end(), 0);
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
 
 
    /** O(N) build of the segment tree for heavy light decomposition structure
        @param roots  -> contains the roots of the forest, if its empty, it would take random roots from the forest
        @param values -> contains the initial values of the nodes
    */
    void build(vector<int> roots, const vector<int64_t> &values) {
        assert(int(values.size()) == N);
        if(roots.empty()) {
            for(int i = 0; i < N; i++) {
                if(parent[i] == i) {
                    find_heavy_child(i, i);
                    accumulate_heavy_segments_and_relabel(i);
                }
            }
            
        } else {
            for(int root: roots) {
                find_heavy_child(root, root);
                accumulate_heavy_segments_and_relabel(root);
            }
        }
        
        
        // do segment tree building
        vector<segment> reordered_values(int(values.size()));
        for(int i=0;i<N;i++) {
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
                segment tmp;
                // tmp = tree.query(label1, label2 + 1);
                // for edge queries comment above and uncomment below
                tmp = tree.query(label1 + 1, label2 + 1);
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
        while(true) {
            int x = head[u];
            int y = head[v];
            if(x == y) {
                int label1 = label[u];
                int label2 = label[v];
                if(label1 > label2) {
                    swap(label1, label2);
                }
                // tree.update(label1, label2 + 1, segment_change(val));
                // for edge queries comment above and uncomment below
                tree.update(label1 + 1, label2 + 1, segment_change(val));
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

class DSU {
    public:
    vector<int> p;
    int n;
 
    DSU(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
 
    inline int find(int x) {
        return (x == p[x] ? x : (p[x] = find(p[x])));
    }
 
    inline bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

void run_cases() {
    int N, Q;
    cin >> N >> Q;

    vector<array<int, 4>> tree_edges, cycle_edges;
    DSU dsu(N);
    heavy_light_decomposition tree;
    tree.init(N);

    for(int i = 0; i < Q; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        if(dsu.find(u) == dsu.find(v)) {
            cycle_edges.push_back({u, v, x, i});
        } else {
            tree.add_bidirectional_edge(u, v);
            tree_edges.push_back({u, v, x, i});
            dsu.unite(u, v);
        }
    }

    vector<string> ans(Q);
    vector<int> depth(N);
    vector<int64_t> values(N);
    vector<int> xor_vals(N);

    vector<vector<int>> adj(N);
    for(auto edges: tree_edges) {
        int u = edges[0];
        int v = edges[1];
        int index = edges[3];

        adj[u].push_back(v);
        adj[v].push_back(u);
        ans[index] = "YES";
    }

    function<void(int,int)> dfs = [&](int node, int par) -> void {
        if(par != -1) {
            depth[node] = depth[par] + 1;
        }
        for(int child: adj[node]) {
            if(child != par) {
                dfs(child, node);
            }
        }
    };

    function<void(int,int)> dfs2 = [&](int node, int par) -> void {
        if(par != -1) {
            xor_vals[node] ^= xor_vals[par];
        }
        for(int child: adj[node]) {
            if(child != par) {
                dfs2(child, node);
            }
        }
    };

    vector<int> roots;
    for(int i = 0; i < N; i++) {
        if(dsu.find(i) == i) {
            roots.push_back(i);
            dfs(i, -1);
        }
    }

    for(auto edges: tree_edges) {
        int u = edges[0];
        int v = edges[1];
        int x = edges[2];

        if(depth[u] > depth[v]) {
            swap(u, v);
        }

        values[v] = x;
        xor_vals[v] = x;
    }

    for(int root: roots) {
        dfs2(root, -1);
    }

    tree.build(roots, values);

    for(auto edges: cycle_edges) {
        int u = edges[0];
        int v = edges[1];
        int x = edges[2];
        int index = edges[3];
        bool ok = false;

        int cycle_xor = xor_vals[u] ^ xor_vals[v] ^ x;

        if(cycle_xor == 1 && tree.query(u, v) <= 1) {
            ok = true;
            tree.update(u, v, 2);
        }

        ans[index] = ok ? "YES" : "NO";
    }

    for(auto u: ans) {
        cout << u << '\n';
    }

    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}