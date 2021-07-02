#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

// Also known as "extended KMP"
template<typename T>
vector<int> z_algorithm(const T &pattern) {
    // Z[i] = for the suffix [i, n) of pattern, the longest prefix that is also a prefix of pattern.
    int n = int(pattern.size());
    vector<int> Z(n, 0);
    Z[0] = n;
    int loc = 1;
 
    for (int i = 1; i < n; i++) {
        if (i < loc + Z[loc])
            Z[i] = min(Z[i - loc], loc + Z[loc] - i);
 
        while (i + Z[i] < n && pattern[Z[i]] == pattern[i + Z[i]])
            Z[i]++;
 
        // Find the location with the furthest-reaching umbrella.
        if (i + Z[i] > loc + Z[loc])
            loc = i;
    }
 
    return Z;
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
    string S;
    cin >> N >> K >> S;

    vector<int> Z = z_algorithm(S);
    debug() << imie(Z);

    int x = 1;
    for(int end = 2; end <= N; end++) {
        int y = end - x;
        // Let x_str = S.substr(0, x) and y_str = S.substr(x, y). 
        // Determine whether y_str + x_str < x_str + y_str.
        if (Z[x] < y) {
            if (S[x + Z[x]] < S[Z[x]])
                x = end;
        } else if (Z[y] < x) {
            if (S[Z[y]] < S[y + Z[y]])
                x = end;
        }
        debug() << imie(x);
    }
    string pattern = S.substr(0, x);
    string ans = "";
    while(ans.length() < K) {
        ans += pattern;
    }
    while(ans.length() > K) {
        ans.pop_back();
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}