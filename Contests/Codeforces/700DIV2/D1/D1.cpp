#include <algorithm>
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

#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

//----------------------------------- DEFINES ----------------------------------- 

#define sz(x) (int)(x).size()
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ins insert
#define nl '\n'

//----------------------------------- END DEFINES -------------------------------- 

// void run_cases() {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     trav(u, a) cin >> u;
//     vector<int> part1, part2;
//     part1.push_back(a[0]);
//     int parity = 1;
//     for(int i=1;i<n;i++) {
//         if(parity == 1) {
//             if(part1.back() != a[i]) part1.push_back(a[i]);
//             else part2.push_back(a[i]);
//             parity = 2;
//         }
//         else {
//             if(part2.empty()) {
//                 part2.push_back(a[i]);
//             }
//             else if(part2.back() != a[i]) part2.push_back(a[i]);
//             else part1.push_back(a[i]);
//             parity = 1;
//         }
//     }
//     debug() << imie(part1) imie(part2);
//     auto it = unique(all(part1));
//     part1.resize(distance(part1.begin(), it));


//     it = unique(all(part2));
//     part2.resize(distance(part2.begin(), it));
//     debug() << imie(part1) imie(part2);
//     cout << int(part1.size()) + int(part2.size()) << nl;

// }

void run_cases() {
    int n;
    cin >> n;
    vector<int> a(n);
    trav(u, a) cin >> u;
    a.push_back(10001000);
    vector<int> part1, part2;
    part1.push_back(a[0]);
    for(int i=1;i<n;i++) {
        if(part1.back() != a[i]) {
            bool ok = true;
            if(part2.empty()) {
                ok = true;
            }
            else if(part2.back() == a[i + 1]) {
                ok = false;
            }
            if(ok)
                part1.push_back(a[i]);
            else {
                part2.push_back(a[i]);
            }
        }
        else part2.push_back(a[i]);
    }
    debug() << imie(part1) imie(part2);
    auto it = unique(all(part1));
    part1.resize(distance(part1.begin(), it));


    it = unique(all(part2));
    part2.resize(distance(part2.begin(), it));
    debug() << imie(part1) imie(part2);
    cout << int(part1.size()) + int(part2.size()) << nl;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}