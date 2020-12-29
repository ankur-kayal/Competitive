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

long long p,q;
map<long long, long long> cnt;

void verify(vector<long long>&a, vector<long long> &lock){
	// debug() << imie(lock);
	int n = a.size();
	long long score = 1e9;
	for(int i=0;i<n;i++) {
		score = min({score, lock[i] - 0, a[i] - lock[i]});
	}
	// debug() << imie(score);
	cnt[score]++;
	p += score;
	q++;
}

void calculate(vector<long long> &a, vector<long long> &lock, int index) {
	for(int i=0;i<=a[index];i++) {
		lock.push_back(i);
		if(a.size() == lock.size()) {
			verify(a,lock);
		}
		else {
			calculate(a,lock,index + 1);
		}
		lock.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<long long> a(n);
	for(auto &u: a) {
		cin >> u;
	}
	vector<long long> lock;
	calculate(a,lock,0);

	cout << p << " " << q << '\n';
	debug() << imie(cnt);
}