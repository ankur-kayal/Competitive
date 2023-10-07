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

vector<int> factorize(int n) {
    vector<int> factors;
    for(int64_t i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            factors.push_back(i);
            if(n / i != i) {
                factors.push_back(n / i);
            }
        }
    }

    sort(factors.begin(), factors.end());

    return factors;
}

void run_cases() {
    int width, height;
    cin >> width >> height;

    debug() << imie(width) imie(factorize(width));
    debug() << imie(height) imie(factorize(height));

    vector<int> height_factors = factorize(height);

    height_factors.pop_back();

    vector<int> used;

    while(!height_factors.empty()) {
        int x = height_factors.back();
        height_factors.pop_back();

        bool ok = true;
        for(auto u: used) {
            if(lcm(u, x) < height) {
                ok = false;
                break;
            }
        }

        if(ok) {
            used.push_back(x);
        }
    }

    debug() << imie(used);

    while(!used.empty() && width % used.size() != 0) {
        used.pop_back();
    }

    cout << used.size() << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}