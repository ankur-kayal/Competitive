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
    100010111

    011101100
    110010011


    101101100
    ----------

    001011011
    110101100
    011010011
    100101101

    011010101
    110101100 


    111011
    111100

    100100

    001011011
    111100100
    100011011
    011100100
    011010101


    0010
    0001

    1110
    1001
    0111

    ----------------
    **    *
    100010111
    101101100

    721
     *   ***
    001011011
    011010101

    11001
    11110

    10111
    01100
    10011
    01101
    11011
    


    */
    int N;
    cin >> N;

    string a, b;
    cin >> a >> b;

    if(a == b) {
        cout << 0 << '\n';
    } else {
        if(count(a.begin(), a.end(), '1') == 0) {
            cout << -1 << '\n';
        } else {
            int match01 = 0, match10 = 0, match11 = 0, match00 = 0;
            for(int i = 0; i < N; i++) {
                if(a[i] != b[i]) {
                    if(a[i] == '1' && b[i] == '0') {
                        match10++;
                    } else {
                        match01++;
                    }
                } else {
                    if(a[i] == '1') {
                        match11++;
                    } else{
                        match00++;
                    }
                }
            }

            int moves = N + 100;

            if(match11 == 1 && match00 == 0) {
                moves = 1;
            }

            if(match00 >= 1 && match11 >= 2 && (match00 + match11) % 2 == 1) {
                moves = min(moves, match11 + match00);
            }

            if(match01 >= 2 && match10 >= 2 && (match10 + match01) % 2 == 0) {
                moves = min(moves , match01 + match10);
            }

            if()

            cout << (moves == N + 100 ? -1 : moves) << '\n';


        }
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