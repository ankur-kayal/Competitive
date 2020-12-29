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

vector<int> a;
int n;
int cnt;

map<int,int> cache;

void process(vector<int>&res) {
    int tmp = 0;
    for(int i=0;i<n;i++) {
        tmp += res[i] * a[i];
    }
    if(tmp % 239 == 0) {
        // debug() << imie(tmp) imie(tmp / 239);
        cnt++;
        // debug() << imie(res);
        cache[tmp]++;
    } 

}

void recurse(vector<int>&res) {
    for(int i=0;i<239;i++){
        if(find(res.begin(), res.end(), i) != res.end()) continue;
        if(res.size() > 0 and res.back() > i) continue; 
        res.push_back(i);
        if(res.size() == n) {
            process(res);
        }
        else {
            recurse(res);
        }
        res.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n);
    int zeros = 0;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        if(a[i] == 0) {
            zeros++;
        }
    }

    // assert(zeros >= 5);

    vector<int> ans;
    recurse(ans);

    debug() << imie(cache);

    debug() << imie(cnt);


}