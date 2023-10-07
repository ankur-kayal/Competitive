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

    vector<int> A(N);

    for(auto &u: A)
        cin >> u;

    vector<int> out_of_range;
    vector<int> contains(N + 1);
    for(auto u: A) {
        if(u <= N) {
            if(contains[u]) {
                out_of_range.push_back(u);
            } else {
                contains[u] = 1;
            }
        } else {
            out_of_range.push_back(u);
        }
    }

    vector<int> needed;
    for(int i = 1; i <= N; i++) {
        if(!contains[i]) {
            needed.push_back(2 * i + 1);
        }
    }

    sort(out_of_range.begin(), out_of_range.end());

    assert(out_of_range.size() == needed.size());

    for(int i = 0; i < needed.size(); i++) {
        if(out_of_range[i] < needed[i]) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << needed.size() << '\n';


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}