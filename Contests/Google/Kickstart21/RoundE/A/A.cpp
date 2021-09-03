#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)


void run_cases() {
    string S;
    cin >> S;

    int N = S.length();

    vector<vector<int>> indices(26);
    for(int i = 0; i < N; i++) {
        indices[S[i] - 'a'].push_back(i);
    }

    int mx = -1;

    for(int i = 0; i < 26; i++) {
        mx = max(mx, int(indices[i].size()));
    }

    if(2 * mx > S.length()) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }

    string A = S;

    priority_queue<pair<int,int>> pq;
    for(int i = 0; i < 26; i++) {
        if(indices[i].empty()) continue;

        // debug() << imie(indices.size());

        pq.push({indices[i].size(), i});
    }

    debug() << imie(indices);

    int single = -1;

    while(!pq.empty()) {
        if(pq.size() == 1) {
            single = pq.top().second;
            break;
        }
        auto first = pq.top();
        pq.pop();
        auto second = pq.top();
        pq.pop();

        debug() << imie(first) imie(second);

        int index1 = indices[first.second].back();
        indices[first.second].pop_back();
        int index2 = indices[second.second].back();
        indices[second.second].pop_back();

        swap(A[index2], A[index1]);

        first.first--;
        if(first.first != 0) {
            pq.push(first);
        }

        second.first--;
        if(second.first != 0) {
            pq.push(second);
        }
    }

    if(single != -1) {
        debug() << imie(indices[single]);
        if(indices[single].size() > 1) {
            cout << "IMPOSSIBLE" << '\n';
            return;
        }
        int index = indices[single][0];
        bool ok = false;

        for(int i = 0; i < N; i++) {
            swap(A[i], A[index]);
            if(S[i] != A[i] && A[index] != S[index]) {
                ok = true;
                break;
            }
            swap(A[i], A[index]);
        }
        assert(ok);
    }

    cout << A << '\n';


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}