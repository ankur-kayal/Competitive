#include <bits/stdc++.h>
#include <iomanip>
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

/*
1 2 3 4 5 6
1 1 1 1 1 2

1 0 0 1 0 0
*/

void run_cases() {
    int N;
    cin >> N;

    vector<int> colors(N, 0);

    bool bot = true;

    int ans = 0;

    auto is_valid = [&](int index) {
        if(index - 1 >= 0 && colors[index - 1] == 1) {
            return false;
        }

        if(index + 1 < N && colors[index + 1] == 1) {
            return false;
        }

        return true;
    };

    for(int i = 0; i < N; i++) {
        // debug() << imie(i) imie(is_valid(i));
        if(colors[i] == 1 || !is_valid(i)) {
            continue;
        }
        // debug() << imie(i);
        if(bot) {
            if(is_valid(i)) {
                assert(colors[i] == 0);
                colors[i] = 1;
                ans++;
                bot = !bot;
                // debug() << " bot: " << imie(i);
            }
        } else {
            if(i + 1 < N && is_valid(i + 1)) {
                // debug() << " me: " << imie(i + 1);
                colors[i + 1] = 1;
                bot = !bot;
            } else {
                if(is_valid(i)) {
                    // debug() << " me: " << imie(i);

                    colors[i] = 1;
                    bot = !bot;
                }
            }
        }
    }

    // debug() << imie(colors);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    // cout << setprecision(6) << fixed;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}