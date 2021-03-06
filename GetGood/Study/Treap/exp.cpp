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

unsigned seed = chrono::system_clock::now().time_since_epoch().count();

mt19937 rnd (seed);

struct Treap {
	int data;
	long long priority;
	vector<Treap*> kids;
	int subTreeSize;
	Treap(){};
	Treap(int data);
};

void print(Treap *me) {
	cout << me->data << '\n';
	cout << me->priority << '\n';
	cout << me->subTreeSize << '\n';
}

Treap::Treap(int _data) {
	data = _data;
	priority = rnd();
	subTreeSize = 1;
	kids = {NULL,NULL};
	print(this);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Treap *a = new Treap(5);
	print(a);
}