#include <bits/stdc++.h>
using namespace std;

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



string binary(int N) {
    string bin = "";
    while(N != 0) {
        bin += to_string(N % 2);
        N /= 2;
    }
    while(bin.length() != 8) {
        bin += '0';
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

int bintodec(string S) {
    int ans = 0;
    reverse(S.begin(), S.end());
    for(int i = 0; i < 8; i++) {
        ans += (1 << i) * (S[i] - '0');
    }
    return ans;
}

void run_cases() {
    vector<vector<int>> bins(9);
    for(int i = 0; i < 256; i++) {
        bins[__builtin_popcount(i)].push_back(i);
    }
    cout << binary(255) << endl;
    int N;
    cin >> N;
    if(N == 0) {
        return;
    }

    while(true) {
        int numbers = bins[N].size();
        int ind = uid(0, numbers - 1);
        // debug() << imie(binary(bins[N][ind]));
        cout << binary(bins[N][ind]) << endl;
        cin >> N;
        if(N == 0) {
            return;
        }

        if(N == -1) {
            exit(0);
        }
    }
}

// python runner.py python local_testing_tool.py 0 -- C.exe

int main() {
    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}