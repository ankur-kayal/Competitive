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

static const int64_t INF64 = 1e18;

void run_cases() {
    int N;
    cin >> N;
    vector<int> A(N);

    for(auto &u: A)
        cin >> u;

    // debug() << imie(A);

    vector<int> tmp = A;

    vector<multiset<int>> pos(2);
    for(int i = 0; i < N; i++) {
        pos[A[i] % 2].insert(i);
    }

    // debug() << imie(pos);

    int l1 = pos[0].size();
    int l2 = pos[1].size();

    // debug() << imie(l1) imie(l2);

    if(abs(l1 - l2) > 1) {
        cout << -1 << '\n';
        return;
    }

    // 101010

    int64_t ans = INF64;

    int parity = 1;

    int64_t res = 0;

    for(int i = 0; i < N; i++) {
        // debug() << imie(parity) imie(i);
        if(pos[tmp[i] % 2].size() == 0) {
            res = INF64;
            break;
        }
        pos[tmp[i] % 2].erase(pos[tmp[i] % 2].begin());
        if(tmp[i] % 2 != parity) {
            if(pos[parity].size() == 0) {
                res = INF64;
                break;
            }
            int ind = *pos[parity].begin();
            swap(tmp[ind], tmp[i]);
            pos[parity].erase(pos[parity].begin());
            res += ind - i;
            pos[!parity].insert(ind);
        }
        parity = !parity;
        // debug() << imie(pos);
    }

    ans = min(ans, res);

    // debug() << imie(ans);

    // 0101010

    res = 0;

    pos[0].clear();
    pos[1].clear();
    for(int i = 0; i < N; i++) {
        pos[A[i] % 2].insert(i);
    }

    parity = 0;

    tmp = A;

    for(int i = 0; i < N; i++) {
        // debug() << imie(parity) imie(i) imie(pos) imie(tmp);
        if(pos[tmp[i] % 2].size() == 0) {
            res = INF64;
            break;
        }
        pos[tmp[i] % 2].erase(pos[tmp[i] % 2].begin());
        if(tmp[i] % 2 != parity) {
            if(pos[parity].size() == 0) {
                res = INF64;
                break;
            }
            int ind = *pos[parity].begin();
            swap(tmp[ind], tmp[i]);
            pos[parity].erase(pos[parity].begin());
            res += ind - i;
            pos[!parity].insert(ind);
        }
        parity = !parity;
    }

    ans = min(ans, res);

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}