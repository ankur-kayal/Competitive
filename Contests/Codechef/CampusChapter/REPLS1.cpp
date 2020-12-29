#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

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
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

int bs = sqrtl(int(1e5)) + 1;

struct Query {
    int l,r,index;
    int64_t order;
    Query() {
        l = -1;
        r = -1;
        index = -1;
    }
    Query(int _l, int _r, int _index) {
        l = _l;
        r = _r;
        index = _index;
        order = gilbertOrder(l,r,21,0);
    }

    inline pair<int, int> toPair() const {
        return make_pair(l / bs, ((l / bs) & 1) ? -r : +r);
    } 
};



// bool comp(Query &a, Query &b) {
//     if(a.l / bs != b.l / bs) {
//         return a.l / bs < b.l / bs;
//     }
//     return a.r < b.r;
// }

// bool comp(Query &a, Query &b) {
//     return a.order < b.order;
// }

bool comp(Query &a, Query &b) {
    return a.toPair() < b.toPair();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int bs = sqrtl(n);
    vector<int> block(n);
    for(int i=0;i<n;i++) {
        block[i] = n / bs;
    }


    vector<int> ans(q);
    vector<Query> query(q);
    for(int i=0;i<q;i++) {
        int l,r;
        cin >> l >> r;
        --l;--r;
        query[i] = Query(l,r,i);
    }
 
    sort(query.begin(), query.end(), comp);

    // cerr << "done" << '\n';
    // exit(0);

    gp_hash_table<int,int> count;
    int cnt = 0;

    function<void(int)> add = [&](int val) {
        count[val]++;
        if(count[val] == val) cnt++;
        if(count[val] == val + 1) cnt--;
    };

    function<void(int)> remove = [&](int val) {
        count[val]--;
        if(count[val] == val) cnt++;
        if(count[val] == val - 1) cnt--;
    };

    int curL = 0;
    int curR = -1;


    for(int i=0;i<q;i++) {
        while(curR < query[i].r) curR++, add(a[curR]);
        while(curL > query[i].l) curL--, add(a[curL]);
        while(curR > query[i].r) remove(a[curR]), curR--;
        while(curL < query[i].l) remove(a[curL]), curL++;

        ans[query[i].index] = cnt;
        // cout << ans[i] << '\n';
    }

    for(int i=0;i<q;i++) {
        cout << ans[i] << '\n';
    }
}