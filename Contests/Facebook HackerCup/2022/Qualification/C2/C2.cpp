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

const int inf = 1e9;

void run_cases() {
    cout << '\n';
    int N;
    cin >> N;

    int nodeIndex = 0;

    vector<vector<pair<int, char>>> adj;

    queue<pair<int,int>> nodes;
    nodes.push({0, 0});

    while(!nodes.empty()) {
        auto [node, depth] = nodes.front();
        nodes.pop();

        if(depth >= 10) {
            continue;
        }

        int leftChild = ++nodeIndex;
        int rightChild = ++nodeIndex;

        adj.push_back({});
        adj.push_back({});

        adj[node].emplace_back(leftChild, '.');
        adj[node].emplace_back(rightChild, '-');

        nodes.push({leftChild, depth + 1});
        nodes.push({rightChild, depth + 1});
    }

    string C1;
    cin >> C1;

    C1 = C1.substr(0, 10);

    // debug() << imie(C1) imie(C1.length());

    // left edge '.', right edge '-'

    function<void(int, int)> markCurrentCodeword = [&](int node, int index) -> void {
        if(index == C1.length()) {
            // debug() << imie(adj[node]);
            adj[node].clear();
            // debug() << imie(adj[node]);

            return;
        }

        for(auto [child, edge] : adj[node]) {
            if(edge == C1[index]) {
                markCurrentCodeword(child, index + 1);
            }
        }

    };

    markCurrentCodeword(0, 0);

    vector<string> codewords;
    string codeword = "";

    function<void(int)> generateCodewords = [&](int node) -> void {
        for(auto [child, edge]: adj[node]) {
            codeword.push_back(edge);
            if(adj[child].size() == 0) {
                codewords.push_back(codeword);
                if(codewords.size() == N) {
                    return;
                }
            } else {
                generateCodewords(child);
                if(codewords.size() == N) {
                    return;
                }
            }
            codeword.pop_back();
        }
    };

    generateCodewords(0);

    
    vector<string> answer;
    for(auto u: codewords) {
        if(u == C1) {
            continue;
        }
        answer.push_back(u);
    }

    for(int i = 0; i < N - 1; i++) {
        cout << answer[i] << '\n';
    }


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("c2_validation_input.txt", "r", stdin);
    // freopen("c2_validation_output.txt", "w", stdout);

    /*For final submit*/
    freopen("c2_final_input.txt", "r", stdin);
    freopen("c2_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}