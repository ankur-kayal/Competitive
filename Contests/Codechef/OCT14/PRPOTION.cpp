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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int r,g,b,m;
		cin >> r >> g >> b >> m;
		int x=-1,y=-1,z=-1;
		for(int i=0;i<r;i++) {
			int foo;
			cin >> foo;
			x = max(x,foo);
		}
		for(int i=0;i<g;i++) {
			int foo;
			cin >> foo;
			y = max(y,foo);
		}
		for(int i=0;i<b;i++) {
			int foo;
			cin >> foo;
			z = max(z,foo);
		}
		priority_queue<int> pq;
		pq.push(x);
		pq.push(y);
		pq.push(z);
		for(int i=0;i<m;i++) {
			int ele = pq.top();
			pq.pop();
			pq.push(ele/2);
		}
		cout << pq.top() << '\n';
	}
}