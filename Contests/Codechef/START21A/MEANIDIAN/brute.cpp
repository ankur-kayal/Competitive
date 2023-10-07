#include <bits/stdc++.h>
#include <numeric>
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

#define nl '\n'

int median_cost(vector<int> A, int median) {
    sort(A.begin(), A.end());
    int N = A.size();
    int op = 0;
    debug() << imie(A) imie(median);
    while(A[(N - 1) / 2] != median) {
        A[(N - 1) / 2]++;
        op++;
        sort(A.begin(), A.end());
        debug() << imie(A);
    }
    debug() << imie(median);
    return op;
}

int mean_cost(vector<int> A, int mean) {
    int op = mean * A.size() - accumulate(A.begin(), A.end(), 0);
    debug() << imie(op);
    return op;
}

void run_cases() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    sort(A.begin(), A.end());

    int mean = A[(N - 1) / 2];

    while(true) {
        if(median_cost(A, mean) <= mean_cost(A, mean)) {
            cout << mean_cost(A, mean) << '\n';
            break;
        }
        mean++;
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