#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

#define nl '\n'

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


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
    vector<int> A(N);

    for(auto &u: A)
        cin >> u;

    vector<vector<int>> colored_indices(K + 1);
    vector<int> color_count(K + 1);
    vector<vector<int>> positions(N + 1);
    for(int i = 0; i < N; i++) {
        positions[A[i]].push_back(i);
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(int i = 1; i <= K; i++) {
        pq.push({0, i});
    }

    // debug() << imie(positions);

    vector<int> ans(N, 0);

    for(int i = 1; i <= N; i++) {
        int last = min((int)positions[i].size(), K);
        vector<pair<int,int>> processed;
        for(int j = 0; j < last; j++) {
            auto ele = pq.top();
            pq.pop();
            ele.first++;
            ans[positions[i][j]] = ele.second;
            processed.push_back(ele);
            color_count[ele.second]++;
            colored_indices[ele.second].push_back(positions[i][j]);
        }
        // debug() << imie(processed);
        for(auto u: processed) {
            pq.push(u);
        }
    }

    int minimum = *min_element(color_count.begin() + 1, color_count.end());

    // debug() << imie(color_count);
    for(int i = 1; i <= K; i++) {
        while(colored_indices[i].size() > minimum) {
            ans[colored_indices[i].back()] = 0;
            colored_indices[i].pop_back();
        }
    }

    output_vector(ans);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}