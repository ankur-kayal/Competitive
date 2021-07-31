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
    /*
    69 ->  0000 0100 0101
    696 -> 0010 1011 1000
    640 -> 0010 1000 0000
           0010 1


    765 -> 0010 1111 1101

    765 -> 0010 1111 1101
    709 -> 0010 1100 0101

    696 -> 0010 1011 1000
    709 -> 0010 1100 0101

    69 ->  0000 0100 0101
    709 -> 0010 1100 0101
    640 -> 0010 1000 0000


    123466 -> 0001 1110 0010 0100 0000
    654321 -> 1001 1111 1011 1111 0001
    530866 -> 1000 0001 1001 1011 0010

    4 -> 0100
    6 -> 0110

    3 -> 0011

    011
    101
    100

    */

    int N, M;
    cin >> N >> M;
    if(N > M) {
        cout << 0 << '\n';
        return;
    }

    if((N & M) == N) {
        for(int bit = 0; bit <= 30; bit++) {
            int setN = (N >> bit & 1);
            int setM = (M >> bit & 1);
            debug() << imie(setN) imie(setM) imie(bit);
            if(setM && !setN) {
                M -= (1 << bit);
            }
            else if(!setM && !setN) {
                M += (1 << bit);
                debug() << imie(M) imie(N);
                cout << (N ^ M) << '\n';
                return;
            }
        }
    }

    int64_t ans = 0;
    // int64_t res = 1e18;

    bool one = false;
    int prev_unset = -1;

    for(int bit = 30; bit >= 0; bit--) {
        int setN = (N >> bit & 1);
        int setM = (M >> bit & 1);
        if(setM) {
            one = true;
        }

        if(setN && setM) {
            ans += 0;
        } 
        else if(setN == 0 && setM == 0) {
            if(one) {
                prev_unset = bit;
            }
        } 
        else if(setN) {
            ans += (1 << bit);
            cout << ans << '\n';
            return;
        }  else {
            ans += (1 << bit);
        }
    }

    debug() << imie(ans);

    ans += (1 << prev_unset);
    for(int bit = prev_unset - 1; bit >= 0; bit--) {
        if(ans >> bit & 1) {
            ans -= (1 << bit);
        }
    }

    cout << ans << '\n';

    // now M >= N, so 0 is no more a choice

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}