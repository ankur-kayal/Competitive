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
    string S;
    cin >> S;

    vector<array<int, 3>> prefix_sums(N + 1);
    for(int i = 0; i < N; i++) {
        prefix_sums[i + 1] = prefix_sums[i];
        prefix_sums[i + 1][S[i] - 'a']++;
    }

    vector<int> positions_a;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'a') {
            positions_a.push_back(i);
        }
    }

    auto get_freq = [&](int i, int j) {
        array<int, 3> l = prefix_sums[i];
        array<int, 3> r = prefix_sums[j + 1];
        for(int k = 0; k < 3; k++) {
            r[k] -= l[k];
        }

        return r;

    };

    int ans = N + 1;

    for(int length = 2; length <= min(100, int(positions_a.size())); length++) {
        for(int i = 0; i < positions_a.size(); i++) {
            int j = i + length - 1;
            if(j >= positions_a.size()) {
                break;
            }
            array<int, 3> freq = get_freq(positions_a[i], positions_a[j]);
            if(freq[0] > freq[1] && freq[0] > freq[2]) {
                ans = min(ans, positions_a[j] - positions_a[i] + 1);
            }
        }
    }

    cout << (ans == N + 1 ? -1 : ans) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}