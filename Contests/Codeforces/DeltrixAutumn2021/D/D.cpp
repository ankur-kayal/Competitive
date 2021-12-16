#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

class DSU {
public:
    vector<int> parent, component_size;
    
    DSU(int n = 0) {
        parent = vector<int>(n);
        component_size = vector<int>(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            component_size[i] = 1;
        }
    }
    
    int find_parent(int a) {
        return parent[a] == a ? a : parent[a] = find_parent(parent[a]);
    }
    
    bool merge(int a, int b) {
        a = find_parent(a);
        b = find_parent(b);
        
        if(a == b) {
            return false;
        }
        
        parent[a] = b;
        component_size[b] += component_size[a];
        return true;
    }
};


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
    int N, D;
    cin >> N >> D;

    DSU dsu(N + 1);

    int extra = 0;

    for(int i = 0; i < D; i++) {
        int u, v;
        cin >> u >> v;

        bool merged = dsu.merge(u, v);

        if(!merged) {
            extra++;
        }

        vector<int> components;
        for(int i = 1; i <= N; i++) {
            if(dsu.find_parent(i) == i) {
                components.push_back(dsu.component_size[i]);
            }
        }

        int ans = 0;
        int tmp = extra;
        sort(components.rbegin(), components.rend());
        ans = components[0];
        for(int j = 1; j < components.size(); j++) {
            if(tmp == 0) {
                break;
            }
            ans += components[j];
            tmp--;
            if(tmp == 0) {
                break;
            }
        }

        cout << ans - 1 << '\n';
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