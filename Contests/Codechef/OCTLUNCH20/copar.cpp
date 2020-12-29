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
const int maxN = 1e5+10;
vector<int> seive(maxN), spf(maxN);
vector<int> primes;

void init() {
	seive.assign(maxN,1);
	seive[0] = 0;
	seive[1] = 0;
	for(int i=1;i*i<=100000;i++) {
		if(seive[i] == 1) {
			for(int j=i*i;j<=100000;j+=i) {
				seive[j] = 0;
			}
		}
	}
	for(int i=2;i<=100000;i++) {
		if(seive[i] == 1) {
			primes.push_back(i);
		}
	}

	spf[1] = 1; 
    for (int i=2; i<maxN; i++) 
        spf[i] = i; 
    for (int i=4; i<maxN; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<maxN; i++) { 
        if (spf[i] == i) { 
            for (int j=i*i; j<maxN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

vector<int> getFactorization(int x) { 
    vector<int> ret; 
    while (x != 1) { 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    auto ip = unique(ret.begin(), ret.end());
    ret.resize(distance(ret.begin(),ip));
    return ret; 
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();


	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i=0;i<n;i++) {
			cin >> a[i];
		}

		vector<int> left(maxN,0);
		vector<int> right(maxN,0);
		for(int i=0;i<n;i++) {
			vector<int> factors = getFactorization(a[i]);
			for(auto u: factors) {
				right[u]++;
			}
		}

		bool exists = true;
		vector<int> l;

		for(int i=0;i<n;i++) {
			exists = true;
			vector<int> factors = getFactorization(a[i]);
			for(auto u: factors) {
				right[u]--;
				if(left[u] == 0) {
					l.push_back(u);
				}
				left[u]++;	
			}
			for(auto u : l) {
				if(right[u] != 0) {
					exists = false;
				}
			}
			if(exists) {
				cout << i+1 << '\n';
				break;
			}
		}
	}
}