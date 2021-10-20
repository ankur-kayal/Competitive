#include <bits/stdc++.h>
#include <functional>
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

void run_cases() {
    int N;
    cin >> N;

    vector<vector<int>> adj(N);
    vector<int> indegree(N);

    for(int i = 0; i < N; i++) {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++) {
            int ch;
            cin >> ch;
            --ch;
            indegree[i]++;
            adj[ch].push_back(i);
        }
    }

    set<int> readable;


    for(int i = 0; i < N; i++) {
        if(indegree[i] == 0) {
            readable.insert(i);
        }
    }

    int unread = N;

    int times = 0;

    while(!readable.empty()) {
        times++;
        vector<int> read;
        
        int start = *readable.begin();
        read.push_back(start);
        for(int child: adj[start]) {
            indegree[child]--;
            if(indegree[child] == 0) {
                readable.insert(child);
            }
        }
        while(readable.upper_bound(start) != readable.end()) {
            start = *readable.upper_bound(start);
                for(int child: adj[start]) {
                indegree[child]--;
                if(indegree[child] == 0) {
                    readable.insert(child);
                }
            }
            read.push_back(start);
        }

        for(auto u: read) {
            unread--;
            readable.erase(u);
        }
    }


    if(unread != 0) {
        cout << -1 << '\n';
    } else {
        cout << times << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}