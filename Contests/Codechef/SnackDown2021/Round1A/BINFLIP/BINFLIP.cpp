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
    int N, K;
    cin >> N >> K;

    if(K == 0) {
        cout << "YES\n";
        cout << 0 << '\n';
        return;
    }

    if(K % 2 == 0) {
        cout << "NO\n";
        return;
    }

    vector<int> bits;

    int total_sum = 0;

    for(int i = 0; i < 31; i++) {
        if((1 << i) <= K) {
            bits.push_back(i);
            total_sum += (1 << i);
        } else {
            break;
        }
    }

    int overlap_size = (total_sum - K) / 2;

    vector<bool> used(bits.size());
    vector<int> starts(bits.size());

    int l = 1;

    if(overlap_size != 0) {

        vector<int> overlapping_bits;

        int highest = -1;

        for(int i = 0; i < 31; i++) {
            if(overlap_size >> i & 1) {
                overlapping_bits.push_back(i);
                highest = i;
            }
        }

        starts[highest + 1] = l;
        l += (1 << (highest + 1));
        used[highest + 1] = true;

        for(auto u: overlapping_bits) {
            l -= (1 << u);
            starts[u] = l;
            used[u] = true;
        }
    }

    for(auto u: bits) {
        if(!used[u]) {
            starts[u] = l;
            l += (1 << u);
        }
    }

    cout << "YES\n";

    cout << starts.size() << '\n';

    for(auto u: starts) {
        cout << u << '\n';
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