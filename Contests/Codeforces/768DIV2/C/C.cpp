#include <algorithm>
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

/*
7 6
5 1
4 2
3 0

1111 1110
1101 0001
1100 0011
1010 0100
1001 0110


*/

void run_cases() {
    int N, K;
    cin >> N >> K;

    vector<pair<int,int>> ans;

    int fixed = N - 1;
    vector<bool> vis(N);
    if(K == N - 1) {
        if(N == 4) {
            cout << -1 << '\n';
            return;
        }
        vis[N - 1] = true;
        vis[N - 2] = true;
        vis[N - 4] = true;
        vis[0] = true;
        vis[3] = true;
        vis[1] = true;

        ans = {{N - 1, N - 2}, {N - 4, 0}, {3, 1}};
        for(int i = 0; i < N; i++) {
            if(!vis[i]) {
                int mirror = fixed ^ i;
                vis[mirror] = true;
                ans.emplace_back(i, mirror);
            }
        }

    } else {
        ans.emplace_back(fixed, K);
        vis[K] = true;
        vis[fixed ^ K] = true;
        if(K != 0) {
            vis[0] = true;
            vis[N - 1] = true;
            ans.emplace_back(0, fixed ^ K);
        }
        for(int i = 0; i < N; i++) {
            if(!vis[i]) {
                int e = i;
                vis[i] = true;
                int mirror = fixed ^ i;
                vis[mirror] = 1;
                ans.emplace_back(e, mirror);
            }
        }

    }

    int S = 0;
    for(auto [a, b]: ans) {
        S += (a & b);
    }

    if(S == K) {
        set<int> u;
        for(auto [a, b]: ans) {
            u.insert(a);
            u.insert(b);
        }

        assert(u.size() == N);
        debug() << imie(u);
        for(auto [a, b]: ans) {
            cout << a << " " << b << '\n';
        }
    } else {
        cout << -1 << '\n';
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