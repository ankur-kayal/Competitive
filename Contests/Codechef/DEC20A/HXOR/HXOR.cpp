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
template<class T>
debug & operator <<  (debug & dd, queue<T> q) {
    dd << "[";
    while(!q.empty()) {
        dd << q.front() << ",";
        q.pop();
    }

    dd << "]";
    return dd;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n,x;
        cin >> n >> x;
        vector<int> a(n);
        vector<queue<int>> bitpos(32);
        vector<int> bitcnt(32,0);
        for(int i=0;i<n;i++) {
            cin >> a[i];
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<32;j++) {
                if((a[i] &(1LL << j)) != 0) {
                    bitcnt[j]++;
                    bitpos[j].push(i);
                }
            }
        }
        // debug() << imie(bitpos);
        bool over = false;
        for(int i=0;i<n-1;i++) {
            if(a[i] == 0) continue;
            for(int bit=31;bit>=0;bit--) {
                if((a[i] & (1LL << bit)) != 0) {
                    if(bitcnt[bit] > 1) {
                        bitpos[bit].pop();
                        int ind = bitpos[bit].front();
                        bitpos[bit].pop();
                        a[i] = a[i] ^ (1LL << bit);
                        a[ind] = a[ind] ^ (1LL << bit);
                        bitcnt[bit]-=2;
                    }
                    else {
                        a[i] = a[i] ^ (1LL << bit);
                        a[n-1] = a[n-1] ^ (1LL << bit);
                        bitpos[bit].pop();
                        bitpos[bit].push(n-1);
                    }
                    --x;
                    if(x == 0) {
                        over = true;
                    }
                }
                if(over) {
                    break;
                }
            }
            if(over) {
                break;
            }
        }
        // assert(n != 2);
        if(x == 1 or(n == 2 and x % 2 == 1)) {
            // find the lowest set bit in a[n-1];
            int lowest = 0;
            a[n-1] = a[n-1] ^ (1LL << lowest);
            a[n-2] = a[n-2] ^ (1LL << lowest);
        }
        // debug() << imie(bitpos);

        for(int i=0;i<n;i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        // debug() << imie(bitcnt);
        // debug() << imie(bitpos);
        // int test = 0;
        // test = test ^ (1LL << 31);
        // debug() << imie(test);
    }
}