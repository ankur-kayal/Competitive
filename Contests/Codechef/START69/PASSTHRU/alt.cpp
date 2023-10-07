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

	vector<int> cnt(N + 10);

	vector<int> A(N);
	for(auto &u: A) {
		cin >> u;
	}

	vector<int64_t> values(N);

	vector<pair<int, int>> pairs(N);
	for(int i = 0; i < N; ++i) {
		pairs[i] = {A[i], i};
	}
	sort(pairs.begin(), pairs.end());
	int nxt = 0;
	for(int i = 0; i < N; ++i) {
		if(i > 0 && pairs[i-1].first != pairs[i].first) nxt++;
		values[nxt] = A[pairs[i].second];
		A[pairs[i].second] = nxt;
	}

	for(auto u: A) {
		cnt[u]++;
	}

	debug() << imie(values);
	debug() << imie(A);


	vector<pair<int,int>> edges;

	vector<vector<int>> adj(N);
	for(int i = 1; i < N; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.emplace_back(u, v);
	}

	vector<int> depth(N), nodes(N);

	vector<int64_t> answer(N);

	auto merge_vectors = [&](vector<vector<pair<int,int>>> &colors) {
		struct compare_size {
            bool operator()(const vector<pair<int,int>> &x, const vector<pair<int,int>> &y) {
                return x.size() > y.size();
            }
        };

        priority_queue<vector<pair<int,int>>, vector<vector<pair<int,int>>>, compare_size> pq(colors.begin(), colors.end());

        while (pq.size() > 1) {
            vector<pair<int,int>> a = pq.top(); pq.pop();
            vector<pair<int,int>> b = pq.top(); pq.pop();
            
            int pa = 0, pb = 0;

            vector<pair<int,int>> result;

            while(pa < a.size() && pb < b.size()) {
            	if(a[pa].first == b[pb].first) {
            		result.emplace_back(a[pa].first, a[pa].second + b[pb].second);
            		pa++;
            		pb++;
            	} else if (a[pa].first < b[pb].first) {
            		result.push_back(a[pa]);
            		pa++;
            	} else {
            		result.push_back(b[pb]);
            		pb++;
            	}
            }

            while(pa < a.size()) {
            	result.push_back(a[pa]);
        		pa++;
            }

            while(pb < b.size()) {
            	result.push_back(b[pb]);
        		pb++;
            }

           	pq.push(result);
        }

        return pq.top();

	};

    function<vector<pair<int,int>>(int,int)> dfs = [&](int node, int par) -> vector<pair<int,int>> {
	    nodes[node] = 1;
	    vector<vector<pair<int,int>>> colors = {{{A[node], 1}}};
	    for(int child: adj[node]) {
	        if(child != par) {
	        	depth[child] = depth[node] + 1;
	            colors.push_back(dfs(child, node));
	            nodes[node] += nodes[child];
	        }
	    }
	    vector<pair<int, int>> result = merge_vectors(colors);
	    vector<pair<int,int>> filtered;

	    for(auto u: result) {
	    	if (cnt[u.first] == u.second) {
	    		continue;
	    	}
	    	filtered.push_back(u);
	    }


	    for(auto [color, amount]: filtered) {
	    	if (cnt[color] > amount && amount != 0) {
	    		answer[node] += values[color];
	    	}
	    }

	    return filtered;

    };

    dfs(0, -1);


    for(auto [u, v]: edges) {
    	if (depth[u] > depth[v]) {
    		cout << answer[u] << " ";
    	} else {
    		cout << answer[v] << " ";
    	}
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