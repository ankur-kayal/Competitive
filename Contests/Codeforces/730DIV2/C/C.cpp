#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#define nl '\n'

/*
Cash Slip : c
Impound Strike Release Marker: m
Pink slip of rival car: p
volatility factor: v
*/


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
double expectation = 0;
const double eps = 1e-9;

void recurse(double race, double c, double m, double p, double v, double val) {
    // debug() << imie(c) imie(m) imie(p) imie(val);
    if(c > eps) {
        double red = min(c, v);
        double new_m = m < eps ? 0 : m + red / 2;
        double new_p = m < eps ? p + red : p + red / 2;
        recurse(race + 1, c - red, new_m, new_p, v, val * c);
    }
    if(m > eps) {
        double red = min(m, v);
        double new_c = c < eps ? 0 : c + red / 2;
        double new_p = c < eps ? p + red : p + red / 2;
        recurse(race + 1, new_c, m - red, new_p, v, val * m);
    }
    expectation += race * val * p;
    // debug() << imie(race) imie(val * p);
}

void run_cases() {
    double c, m, p, v;
    cin >> c >> m >> p >> v;

    expectation = 0;

    recurse(1, c, m, p, v, 1);


    cout << expectation << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    cout << setprecision(11) << fixed;

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}