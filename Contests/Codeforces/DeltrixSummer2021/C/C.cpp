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
    int N;
    cin >> N;

    vector<int64_t> C(N);

    for(auto &u: C)
        cin >> u;

    int64_t ans = 0;
    int64_t zero = 0;

    int64_t sum = 0;

    for(int i = 0; i < N; i++) {
        if(i % 2 == 1) {
            ans += min(sum, C[i]);
            sum -= C[i];
        } else {
            sum += C[i];
        }

        sum = max(zero, sum);
    }


    debug() << imie(ans);

    for(int i = 0; i < N; i++) {
        sum = 0;
        int cnt = 0;
        int64_t prev = -1;
        if(i % 2 == 1) {
            continue;
        }
        for(int j = i; j < N; j++) {
            // j % 2 == 0, ( else )

            if(j % 2 == 1) {
                sum -= C[j];
                if(prev == -1 && sum >= 0) {
                    prev = sum;
                }
                if(sum < prev) {
                    debug() << imie(i) imie(prev) imie("bug");
                    cnt++;
                    ans += (cnt > 1);
                    cnt = 0;
                    prev = sum;
                }
                if(sum == prev) {
                    cnt++;
                    ans += (cnt > 1);
                }
                debug() << imie(i) imie(j) imie(sum) imie(prev) imie(cnt) imie(ans);

            } else {
                sum += C[j];
            }

            if(sum < 0) {
                break;
            }
        }
        debug() << imie(i) imie(cnt);


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