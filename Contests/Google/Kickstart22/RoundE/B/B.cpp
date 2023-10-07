#include <bits/stdc++.h>
#include <numeric>
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

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);

    for(auto &u: A)
        cin >> u;

    vector<pair<int,int>> indexedA;

    for(int i = 0; i < N; i++) {
        indexedA.emplace_back(A[i], i);
    }

    sort(indexedA.begin(), indexedA.end());
    vector<int> ans(N);

    // debug() << imie(indexedA);

    for(int i = 0; i < N; i++) {
        int target = 2 * A[i];

        if(indexedA.front().first > target) {
            ans[i] = -1;
            continue;
        }

        int l = 0, r = N;

        while(r > l + 1) {
            int m = (l + r) / 2;

            if(indexedA[m].first <= target) {
                l = m;
            } else {
                r = m;
            }
        }

        // debug() << imie(l);

        if(indexedA[l].second == i) {
            l--;
        }

        if(l == -1) {
            ans[i] = -1;
        } else {
            ans[i] = indexedA[l].first;
        }
    }   

    output_vector(ans);
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