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
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pair<int64_t, int64_t>> values;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        values.emplace_back(a, 1);
    }

    for(int i = 0; i < M; i++) {
        int b;
        cin >> b;
        values.emplace_back(b, 0);
    }

    vector<int64_t> prefix_sum_values(N + M + 1), prefix_sum_ids(N + M + 1);
    sort(values.begin(), values.end());

    for(int i = 0; i < N + M; i++) {
        prefix_sum_values[i + 1] = prefix_sum_values[i] + values[i].first;
    }

    for(int i = 0; i < N + M; i++) {
        prefix_sum_ids[i + 1] = prefix_sum_ids[i] + values[i].second;
    }

    auto compute_range = [&](int l, int r) -> int64_t {
        int monocarp_items = prefix_sum_ids[r + 1] - prefix_sum_ids[l];

        return prefix_sum_values[r + 1] - prefix_sum_values[r + 1 - monocarp_items];
    };

    vector<pair<int,int>> ranges(N + M);
    for(int i = 0; i < N + M; i++) {
        ranges[i] = {i, i};
    }

    vector<int> parent(N + M);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> get_parent = [&](int node) -> int {
        return parent[node] == node ? node : parent[node] = get_parent(parent[node]);
    };

    auto merge = [&](int node1, int node2) {
        node1 = get_parent(node1);
        node2 = get_parent(node2);

        assert(node1 != node2);

        parent[node1] = node2;

        ranges[node2] = {min(ranges[node1].first, ranges[node2].first), max(ranges[node1].second, ranges[node2].second)};
    };

    vector<int64_t> answers(Q);

    vector<pair<int,int>> queries;
    for(int i = 0; i < Q; i++) {
        int k;
        cin >> k;
        queries.emplace_back(k, i);
    }

    sort(queries.begin(), queries.end());

    int64_t current_sum = 0;

    for(int i = 0; i < N + M; i++) {
        if(values[i].second == 1) {
            current_sum += values[i].first;
        }
    }

    vector<array<int64_t, 3>> adjacent_difference;
    for(int i = 1; i < N + M; i++) {
        adjacent_difference.push_back({values[i].first - values[i - 1].first, i, i - 1});
    }

    sort(adjacent_difference.rbegin(), adjacent_difference.rend());

    for(auto [k, index] : queries) {

        while(!adjacent_difference.empty()) {
            if(adjacent_difference.back()[0] <= k) {
                int node1 = adjacent_difference.back()[1];
                int node2 = adjacent_difference.back()[2];

                node1 = get_parent(node1);
                node2 = get_parent(node2);

                current_sum -= compute_range(ranges[node1].first, ranges[node1].second);
                current_sum -= compute_range(ranges[node2].first, ranges[node2].second);
                merge(node1, node2);
                node1 = get_parent(node1);
                current_sum += compute_range(ranges[node1].first, ranges[node1].second);
                adjacent_difference.pop_back();
            } else {
                break;
            }
        }

        answers[index] = current_sum;
    }

    for(auto u: answers) {
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