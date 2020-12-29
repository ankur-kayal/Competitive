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

//----------------------------------- END DEBUG --------------------------------

struct Query {
	int vertex1, vertex2, depth, index;

	Query(int _vertex1, int _vertex2, int _depth, int _index) {
		vertex1 = _vertex1;
		vertex2 = _vertex2;
		depth = _depth;
		index = _index;
	}

	bool operator<(const Query& q) const {
		return depth > q.depth;
	}
};

debug & operator << (debug & dd, Query q) { dd << "(" << q.vertex1 << ", " << q.vertex2 << ", " << q.depth <<  ")"; return dd; }
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 rng(seed);

long long myRand(long long a, long long b) {
	return a + (rng() % (b - a));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<Query> query;
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int u,v;
		cin >> u >> v;
		int d = (int)myRand(1, 50);
		Query tmp(u,v,d,i);
		query.push_back(tmp);
	}
	sort(query.begin(), query.end());
	debug() << imie(query);
}