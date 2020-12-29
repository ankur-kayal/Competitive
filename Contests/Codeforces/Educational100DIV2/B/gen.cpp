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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int64_t rand(int64_t a, int64_t b) {
    return a + (rng() % (b - a + 1));
}

void run_tests(int n, vector<int64_t> &a) {
        // int n;
        // cin >> n;
        // vector<int64_t> a(n);
        // for(auto &u: a) {
        //     cin >> u;
        // }

        int64_t sum = 0;
        for(auto u: a) {
            sum += u;
        }
        vector<int64_t> b(n);

        b[0] = a[0];
        for(int i=1;i<n;i++) {
            // if(b[i-1] % a[i] == 0) {
            //     b[i] = a[i];
            //     continue;
            // }
            // if(a[i] % b[i-1] <= b[i-1] / 2) {
            //     b[i] = max(1LL, (a[i] / b[i-1]) * b[i-1]);
            // }
            // else {
            //     b[i] = max(1LL, (a[i] + b[i-1] - 1) / b[i-1] * b[i-1]);
            // }
            // // if(i == 3)break;

            // b[i] = (a[i] - (a[i] % b[i-1]));
            // if(b[i] == 0) {
            //     b[i] = 
            // }
            // debug() << imie(b[i]);

            if(b[i-1] % a[i] == 0) {
                b[i] = a[i];
                continue;
            }
            // if(a[i] % b[i-1] <= b[i-1] / 2) {
            //     b[i] = max(1LL, (a[i] / b[i-1]) * b[i-1]);
            // }
            // else {
            //     b[i] = max(1LL, (a[i] + b[i-1] - 1) / b[i-1] * b[i-1]);
            // }
            // // if(i == 3)break;

            b[i] = (a[i] - (a[i] % b[i-1]));
            b[i] = max(1LL, b[i]);

        }

        int64_t s1 = 0;
        for(int i=0;i<n;i++) {
            s1 += abs(a[i] - b[i]);
        }
        // debug() << imie(2 * s1) imie(sum);
        if(2 * s1 > sum) {
            debug() << imie(n);
            debug() << imie(a);
            debug() << imie(b);
            debug() << imie(2 * s1) imie(sum);
            exit(0);
        }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        int n = rand(1, 50);
        vector<int64_t> a(n);
        for(int i=0;i<n;i++) {
            a[i] = rand(1, 1000000000);
        }

        run_tests(n, a);
    }

    cerr << "All Pretests passed!" << '\n';
}