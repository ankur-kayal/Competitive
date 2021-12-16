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
    int64_t N;
    cin >> N;

    vector<int64_t> B(N);
    for(auto &u: B) {
        cin >> u;
    }

    int64_t total_sum = accumulate(B.begin(), B.end(), 0LL);

    int64_t divisor = N * (N + 1) / 2;
    if(total_sum % divisor != 0) {
        cout << "NO\n";
        return;
    }
    int64_t sum_ai = total_sum / (N * (N + 1) / 2);

    vector<int64_t> A(N);

    for(int i = 0; i < N; i++) {
        int64_t first = B[i] - B[(((i - 1) % N) + N) % N];
        int64_t second = sum_ai;

        debug() << imie(first) imie(second);

        if(second - first <= 0 || (second - first) % N != 0) {
            cout << "NO\n";
            return;
        }

        A[i] = (second - first) / (N);
    }

    cout << "YES\n";
    for(auto u: A) {
        cout << u << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}