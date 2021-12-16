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

string bin(int64_t n) {
    string res = "";
    while(n != 0) {
        res += to_string(n % 2);
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

void run_cases() {
    int64_t x, y;
    cin >> x >> y;

    if(x == y) {
        cout << "YES\n";
        return;
    }

    debug() << imie(bin(x)) << '\n' <<  imie(bin(y));


    string binx = bin(x);
    string biny = bin(y);
    for(int i = 0; i < biny.length(); i++) {
        if(biny.substr(i, binx.length()) == binx) {
            int before = 0, after = 0;
            for(int j = 0; j < i; j++) {
                if(biny[j] == '1') {
                    before++;
                }
            }
            for(int j = i + binx.length(); j < biny.length(); j++) {
                if(biny[j] == '1') {
                    after++;
                }
            }
            biny.erase(i, binx.length());
            if(count(biny.begin(), biny.end(), '0') == 0) {
                if(binx.back() == '0') {
                    debug() << imie(after);
                    if(after > 0) {
                        cout << "YES\n";
                        return;
                    } else {
                        break;

                    }
                } else {
                    cout << "YES\n";
                    return;
                }
                
            } else {
                break;
            }
        }
    }

    biny = bin(y);
    reverse(binx.begin(), binx.end());

    for(int i = 0; i < biny.length(); i++) {
        if(biny.substr(i, binx.length()) == binx) {
            int before = 0, after = 0;
            for(int j = 0; j < i; j++) {
                if(biny[j] == '1') {
                    before++;
                }
            }
            for(int j = i + binx.length(); j < biny.length(); j++) {
                if(biny[j] == '1') {
                    after++;
                }
            }
            biny.erase(i, binx.length());
            if(count(biny.begin(), biny.end(), '0') == 0) {
                cout << "YES\n";
                return;                
            } else {
                break;
            }
        }
    }

    reverse(binx.begin(), binx.end());
    biny = bin(y);

    while(binx.back() == '0') {
        binx.pop_back();
    }
    

    for(int i = 0; i < biny.length(); i++) {
        if(biny.substr(i, binx.length()) == binx) {
            biny.erase(i, binx.length());
            if(count(biny.begin(), biny.end(), '0') == 0) {
                cout << "YES\n";
                return;
            } else {
                break;
            }
        }
    }

    reverse(binx.begin(), binx.end());
    biny = bin(y);

    for(int i = 0; i < biny.length(); i++) {
        if(biny.substr(i, binx.length()) == binx) {
            biny.erase(i, binx.length());
            if(count(biny.begin(), biny.end(), '0') == 0) {
                cout << "YES\n";
                return;
            } else {
                break;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}