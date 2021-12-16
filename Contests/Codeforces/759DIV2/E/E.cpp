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

#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp>   
using namespace __gnu_pbds;
 
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// pbds usage
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero).


void run_cases() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    vector<vector<int>> adj(N);

    for(int i = 1; i < N; i++) {
        int pi;
        cin >> pi;
        --pi;

        adj[pi].push_back(i);
        adj[i].push_back(pi);
    }

    vector<int> answers(Q);

    vector<vector<array<int, 3>>> queries(N);

    for(int i = 0; i < Q; i++) {
        int v, l, k;
        cin >> v >> l >> k;

        --v;
        queries[v].push_back({i, l, k});
    }

    ordered_set<pair<int, int>> pq;
    vector<int> freq(N + 1);

    function<void(int,int)> dfs = [&](int node, int par) -> void {
        if(freq[A[node]] != 0) {
            pq.erase(pq.find({freq[A[node]], A[node]}));
        }
        freq[A[node]]++;
        pq.insert({freq[A[node]], A[node]});

        debug() << imie(node) imie(pq) imie(queries[node]);

        for(auto [index, l, k]: queries[node]) {
            auto start = *pq.upper_bound({l - 1, N + 100});
            int offset = pq.order_of_key(start);
            k = k + offset;

            if(k > pq.size()) {
                answers[index] = -1;
            } else {
                pair<int,int> element = *pq.find_by_order(k - 1);
                if(element.first < l) {
                    answers[index] = -1;
                } else {
                    answers[index] = element.second;
                }
            }
        }

        for(auto child: adj[node]) {
            if(child != par) {
                dfs(child, node);
            }
        }

        pq.erase(pq.find({freq[A[node]], A[node]}));
        freq[A[node]]--;
        if(freq[A[node]] != 0) {
            pq.insert({freq[A[node]], A[node]});
        }
    };

    dfs(0, -1);


    for(auto u: answers) {
        cout << u << " ";
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}