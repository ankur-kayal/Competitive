#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

const int64_t INF64 = 1e18;


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
    int64_t N, M;
    cin >> N >> M;
    set<int64_t> diff;
    for(int64_t i = 0; i < N; i++) {
        int64_t A, B;
        cin >> A >> B;
        for(int64_t j = A; j <= B; j++) {
            diff.insert(j);
        }
    }
    vector<int64_t> ans;

    // debug() << imie(diff);

    for(int i = 0; i < M; i++) {
        int64_t S;
        cin >> S;
        auto it = diff.lower_bound(S);
        // debug() << imie(*it);
        if(it == diff.begin()) {
            ans.push_back(*it);
            diff.erase(it);
        } else if(it == diff.end()) {
            it = prev(it);
            ans.push_back(*it);
            diff.erase(it);
        } else {
            int64_t small = *prev(it);
            int64_t large = *it;
            if(abs(small - S) <= abs(large - S)) {
                ans.push_back(small);
                diff.erase(prev(it));
            } else {
                ans.push_back(large);
                diff.erase(it);
            }
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