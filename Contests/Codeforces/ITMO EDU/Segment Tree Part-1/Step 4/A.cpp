#include <bits/stdc++.h>
using namespace std;

#define ll long long

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

struct item {
	ll sum;
};

struct segtree {
	int size;

	item NEUTRAL_ELEMENT = {0};

	vector<item> values;

	void init(int n) {
		size = 1;
		while(size < n) {
			size *= 2;
		}
		values.assign(2 * size,{0});
	}

	item single(ll v) {
		return {v};
	}

	item merge(item &a, item &b) {
		return  {a.sum + b.sum};
	}

	void build(vector<int> &a, int x, int lx, int rx) {
		if(rx - lx == 1) {
			if(lx < (int)a.size()) {
				values[x] = single(a[lx]);
			}
			return;
		}
		int m = (rx + lx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}

	void build(vector<int> &a) {
		build(a,0,0,size);
	}

	void set(int i, int v, int x, int lx, int rx) {
		if(rx - lx == 1) {
			values[x] = single(v);
			return;
		}

		int m = (rx + lx) / 2;
		if(i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}

		values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
	}

	void set(int i, int v) {
		set(i, v, 0, 0, size);
	}

	item calc(int l, int r, int x, int lx, int rx) {
		if(lx >= r or l >= rx) {
			return NEUTRAL_ELEMENT;
		}

		else if(lx >= l and rx <= r) return values[x];

		int m = (rx + lx) / 2;

		item s1 = calc(l, r, 2 * x + 1, lx, m);
		item s2 = calc(l, r, 2 * x + 2, m, rx);
		return merge(s1, s2);
	}

	item calc(int l, int r) {
		return calc(l, r, 0, 0, size);
	}

	int find(int val, int l, int x, int lx, int rx) {
		if(values[x].sum < val) {
			return -1;
		}

		if(rx <= l) return -1;

		if(rx - lx == 1) {
			return lx;
		}
		int m = (lx + rx) / 2;;
		int res = find(val, l, 2 * x + 1, lx, m);
		if(res == -1) {
			res = find(val, l, 2 * x + 2, m , rx);
		}
		return res;
	}

	int find(int k, int l) {
		return find(k, l, 0,0,size);
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<int> odd(n,0);
	vector<int> even(n,0);

	for(int i=0;i<n;i++) {
		if(i % 2 == 0) {
			cin >> even[i];
		}
		else {
			cin >> odd[i];
		}
	}

	segtree ste, sto;

	ste.init(n);
	sto.init(n);
	ste.build(even);
	sto.build(odd);

	int m;
	cin >> m;
	while(m--) {
		int ch;
		cin >> ch;
		if(ch == 0) {
			int i,j;
			cin >> i >> j;
			--i;
			if(i % 2 == 0) {
				ste.set(i,j);
			}
			else {
				sto.set(i,j);
			}
		}
		else {
			int l,r;
			cin >> l >> r;
			--l;
			int ans = ste.calc(l,r).sum - sto.calc(l,r).sum;
			if(l % 2 == 0) {
				cout << ans << '\n';
			}
			else {
				cout << -ans << '\n';
			}
		}
	}

}