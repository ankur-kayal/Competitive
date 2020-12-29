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

struct segtree {
	int size;

	vector<long long> values;

	void init(int n) {
		size = 1;
		while(size < n) {
			size*=2;
		}
		values.assign(2*size,0);
	}

	long long operation(long long a, long long b) {
		return max(a , b);
	}

	void add(int l, int r, int v, int x, int lx, int rx) {
		if(lx >= r or rx <= l) return;
		if(lx >= l and rx <= r) {
			values[x] = operation(values[x],v);
			return;
		}

		int m = (rx + lx) / 2;
		add(l, r, v, 2 * x + 1, lx, m);
		add(l, r, v, 2 * x + 2, m, rx);
	}

	void add(int l, int r, int v) {
		add(l,r,v,0,0,size);
	}

	long long calc(int i, int x, int lx, int rx) {
		if(rx == lx + 1) {
			return values[x];
		}

		int m = (rx + lx) / 2;
		long long res;

		if(i < m) {
			res = calc(i, 2 * x + 1, lx, m);
		}
		else {
			res = calc(i, 2 * x + 2, m, rx);
		}

		return operation(res, values[x]);
	}

	long long calc(int i) {
		return calc(i,0,0,size);
	}

};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	segtree st;
	int n,m;
	cin >> n >> m;
	st.init(n);
	debug() << imie(st.size);
	while(m--) {
		debug() << imie(st.values);
		int op;
		cin >> op;
		if(op == 1) {
			int l,r,v;
			cin >> l >> r >> v;
			st.add(l,r,v);
		}
		else {
			int i;
			cin >> i;
			cout << st.calc(i) << '\n';
		}
	}
}