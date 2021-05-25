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

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto &u: A)
        cin >> u;

    int negs = 0, zeros = 0;
    int max_difference = -1;
    for(auto u: A) {
        if(u < 0) {
            negs++;
        } else if(u == 0) {
            zeros++;
        }
    }

    if(zeros > 1) {
        cout << negs + zeros << '\n';
    } else {
        sort(A.begin(), A.end());
        vector<int> diffs;
        int ans = negs + zeros;
        for(int i=1;i<N;i++) {
            if(A[i] > 0) {
                break;
            }
            diffs.push_back(A[i] - A[i-1]);
        }
        sort(diffs.begin(), diffs.end());
        debug() << imie(diffs);
        if(diffs.empty() && ans != N) {
            ans++;
        } else {
            for(int i=0;i<N;i++) {
                if(A[i] > 0 && A[i] <= diffs[0]) {
                    ans++;
                    break;
                }
            }
        }
        
        
        cout << min(N, ans) << '\n';
    }

    /*
    sort(A.begin(), A.end());
    debug() << imie(A);

    int max_till_now  = A[0];

    int cnt = 1;
    for(int i=1;i<N;i++) {
        if(A[i] == 0) {
            cnt++;
            continue;
        }


    }*/
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}