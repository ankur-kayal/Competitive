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
const int maxN = 1e6 + 100;
vector<bool> seive(maxN, true);
queue<int> primes;

void init() {
    seive[0] = seive[1] = false;
    for(int i=2;i*i<maxN;i++) {
        if(seive[i] == true) {
            for(int j=i*i;j<maxN;j+=i) {
                seive[j] = false;
            }
        }
    }
    for(int i=2;i<maxN;i++) {
        if(seive[i]) {
            primes.push(i);
        }
    }

}

void brute(int n) {
    vector<int> lonely;
    vector<bool> friends(n + 1, false);
    for(int i=1;i<=n;i++) {
        if(!friends[i]) {
            bool friends_found = false;
            for(int j=1;j<=n;j++) {
                if(i == j) continue;
                int hcf = gcd(i, j);
                int a = hcf, b = i / hcf, c = j / hcf;
                if(a + b > c and a + c > b and b + c > a) {
                    friends_found = true;
                    friends[j] = true;
                }
                if(i == 10) {
                }
            }
            if(!friends_found) {
                lonely.push_back(i);
            }
        }
        
    }
    // debug() << imie(lonely);
    cout << lonely.size() << '\n';
}

vector<int> cache = {0,1,2,3,2,3,3,4,4,3,3};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    init();

    vector<int> prime_count(maxN, 0);
    for(int i=0;i<maxN;i++) {
        if(primes.empty()) {
            break;
        }

        if(primes.front() == i) {
            prime_count[i] = prime_count[i-1] + 1;
            primes.pop();
            if(i < 210) {
                // cerr << i << " ";
            }
        }
        else {
            prime_count[i] = prime_count[i-1];
        }
    }

    // cerr << '\n';

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        // brute(n);
        if(n == 5) {
            cout << 3 << '\n';
            continue;
        }
        int start = int(sqrtl(n));
        cout << prime_count[n] - prime_count[start] + 1 << '\n';
        // debug() << imie(start);
    }
}