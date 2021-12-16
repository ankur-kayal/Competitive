#include "testlib.h"
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

int main(int argc, char*argv[]) {
    registerTestlibCmd(argc, argv);

    int test_case = inf.readInt();

    for(int test = 1; test <= test_case; test++){
        int N = inf.readInt();
        int K = inf.readInt();

        vector<int> A(N);
        for(int i = 0; i < K; i++) {
            A[i] = 1;
        }

        string status = ouf.readString();
        // debug() << imie(status);

        if(status == "YES") {

            int moves = ouf.readInt();
            for(int i = 0; i < moves; i++) {
                int start = ouf.readInt();
                // debug() << imie(N) imie(K) imie(start);
                start--;
                ensuref(start + (1 << i) <= N, "Range exceeded");
                for(int j = start; j < start + (1 << i); j++) {
                    A[j] ^= 1;
                }
            }
            ouf.readString();
            // println(moves, N, K, A);
            ensuref(count(A.begin(), A.end(), 1) == 0, "Array still contains 1");
        }

        // cout << test << endl;
    }

    quitf(_ok, "All answers are valid");
}