#include <bits/stdc++.h>
#include <limits.h>
#include <string>
using namespace std;

const int64_t INF64 = 2e18;

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
    int n, k;
    cin >> n >> k;

    if(k == 1) {
        int64_t ans = INF64;
        int len = to_string(n).length();
        for(char i = '1'; i <= '9'; i++) {
            string tmp = "";
            for(int j = 0; j < len; j++) {
                tmp += i;
            }
            // debug() << imie(tmp);
            int64_t num = stoll(tmp);
            if(num >= n)
                ans = min(ans, num);
        }
        cout << ans << '\n';

    } else {
        int len = to_string(n).length();
        int64_t ans = 0;
        string tmp = "1";
        for(int j = 0; j < len; j++) {
            tmp += '0';
        }

        // debug() << imie(tmp);

        ans = stoll(tmp);

        string N = to_string(n);

        for(char first_digit = '1'; first_digit <= '9'; first_digit++) {            
            for(char second_digit = '0'; second_digit <= '9'; second_digit++) {

                bool ok = true;

                string tmp = "";

                char mn = min(first_digit, second_digit);
                char mx = max(first_digit, second_digit);

                bool greater = false;

                for(int i = 0; i < len; i++) {
                    if(greater) {
                        tmp += mn;
                        continue;
                    }
                    if(mn == N[i]) {
                        tmp += mn;
                    } else if(mx == N[i]) {
                        tmp += mx;
                    } else if(mn > N[i]) {
                        greater = true;
                        tmp += mn;
                    } else if(mx > N[i]) {
                        greater = true;
                        tmp += mx;
                    } else {
                        ok = false;
                        break;
                    }
                }
                if(ok)
                    ans = min(ans, stoll(tmp));
            }
        }

        cout << ans << '\n';
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