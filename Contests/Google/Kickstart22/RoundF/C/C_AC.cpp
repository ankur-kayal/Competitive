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
    int64_t D, N, X;
    cin >> D >> N >> X;

    deque<array<int64_t, 3>> seeds;

    for(int i = 0; i < N; i++) {
        int64_t q, l, v;
        cin >> q >> l >> v;

        seeds.push_back({v, -l, q});
    }

    sort(seeds.rbegin(), seeds.rend());

    int64_t answer = 0;

    vector<bool> used(D);

    for(int64_t i = 0; i < N; i++) {


        int64_t quantity = seeds[i][2];
        int64_t value = seeds[i][0];
        int64_t days = -seeds[i][1];
            
        int plantingDay = D - days - 1;

        debug() << imie(plantingDay);

        while (plantingDay >= 0 && used[plantingDay]) {
            plantingDay--;
        }

        if (plantingDay >= 0) {
            used[plantingDay] = true;
            answer += value;
            debug() << imie(value);
        }

        debug() << imie(used);
    }

    cout << answer << '\n';


}   

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}