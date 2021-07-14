#include <bits/stdc++.h>
#include <queue>
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
vector<vector<int64_t>> build_ranges(vector<pair<int64_t,int64_t>>& ranges) {
    int64_t n = ranges.size();
    map<int64_t, int64_t> cntl;
    map<int64_t, int64_t> cntr;
    vector<int64_t> start, end;
    for(int64_t i=0;i<n;i++) {
        int64_t l,r;
        tie(l, r) = ranges[i];
        cntl[l]++;
        cntr[r]++;
        start.push_back(l);
        end.push_back(r);
    }
    // sort(all(ranges));
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    vector<vector<int64_t>> non_overlap;
    int64_t l = 0, r = 0;   
    int64_t prevr = INF64;
    int64_t prev_cnt = 0;
    // debug() << imie(cntl) imie(cntr);
    while(l < n or r < n) {
        int64_t times = 0;
        pair<int64_t,int64_t> range;
        range.first = min(l < n ? start[l] : INF64, prevr + 1);
        if(start[l] == range.first) {
            l++;
        }
        times = cntl[range.first] + prev_cnt;
        range.second = min(end[r], l < n ? start[l] - 1 : INF64);
        if(range.second == end[r]) {
            r++;
        }
        prevr = range.second;
        if(range.first <= range.second) {
            non_overlap.push_back({range.first, range.second, times});
            prev_cnt = times - cntr[range.second];
        }
    }
    // debug() << imie(non_overlap);
    return non_overlap;
}

bool valid(vector<int64_t> a) {
    return a[0] <= a[1];
}

void run_cases() {
    int64_t N, C;
    cin >> N >> C;
    int64_t ans = N;

    vector<pair<int64_t, int64_t>> ranges;
    map<int64_t, int64_t> cnt;
    for(int i = 0; i < N; i++) {
        int64_t L, R;
        cin >> L >> R;
        cnt[L]++;
        cnt[R]++;
        ranges.emplace_back(L, R);
    }
    sort(ranges.begin(), ranges.end());

    auto non_overlap = build_ranges(ranges);
    set<vector<int64_t>> no(non_overlap.begin(), non_overlap.end());
    vector<pair<int64_t, int64_t>> pts(cnt.begin(), cnt.end());
    debug() << imie(pts);
    debug() << imie(no);
    for(auto u: pts) {
        auto it = no.lower_bound({u.first, u.first, 0});
        if(it == no.end() || (*it)[0] > u.first) {
            it = prev(it);
            debug() << imie(u) imie(*it);
            vector<int64_t> left = *it;
            vector<int64_t> right = *it;
            no.erase(it);
            left[1]--;
            right[0] = right[1];
            right[2] -= u.second;
            if(valid(left)) {
                no.insert(left);
            }
            if(valid(right)) {
                no.insert(right);
            }
            debug() << imie(left) imie(right);

        } else {
            debug() << imie(u) imie(*it);
            vector<int64_t> left = *it;
            vector<int64_t> right = *it;
            no.erase(it);
            left[1] = left[0];
            left[2] -= u.second;
            right[0]++;
            if(valid(left)) {
                no.insert(left);
            }
            if(valid(right)) {
                no.insert(right);
            }
            debug() << imie(left) imie(right);
        }
        debug() << imie(no);
    }

    debug() << imie(no);

    priority_queue<pair<int64_t, int64_t>> pq;
    for(auto u: no) {
        pq.push({u[2], u[1] - u[0] + 1});
        debug() << imie(vector<int64_t>{u[2], u[1] - u[0] + 1});
    }

    while(C > 0 && !pq.empty()) {
        debug() << imie(pq.top());
        ans += pq.top().first * min(C, pq.top().second);
        C -= pq.top().second;
        pq.pop();
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": ";
        run_cases();
    }
}