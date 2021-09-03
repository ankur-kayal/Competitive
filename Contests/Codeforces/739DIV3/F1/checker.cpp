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


const int64_t INF64 = 2e18;

int run_cases1(int n, int k) {

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
        return ans;

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

        return ans;
    }
}

int run_cases2(int n, int k) {
 
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
        return ans;
 
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
 
        for(char first_digit = N[0]; first_digit <= min('9',char(N[0] + 1)); first_digit++) {            
            for(char second_digit = '0'; second_digit <= '9'; second_digit++) {
                if(second_digit == first_digit) {
                    continue;
                }
 
                // debug() << imie(first_digit) imie(second_digit);
 
 
                for(int mask = 0; mask < (1 << len); mask++) {
                    string tmp = "";
                    bool ok = true;
                    for(int j = 0; j < len; j++) {
                        if(mask >> j & 1) {
                            tmp += first_digit;
                        } else if(j == 0 && second_digit == '0') {
                            ok = false;
                            break;
                        } else {
                            tmp += second_digit;
                        }
                    }
 
                    // debug() << imie(tmp);
 
                    if(ok) {
                        int64_t num = stoll(tmp);
                        if(num >= n)
                            ans = min(ans, num);
                    }
                }
 
 
            }
        }
 
        return ans;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    for(int i = 1; i <= 10000000; i++) {
        if(run_cases1(i, 2) != run_cases2(i, 2)) {
            debug() << imie(i) imie(run_cases1(i, 2)) imie(run_cases2(i, 2));
            break;
        }
    }
}