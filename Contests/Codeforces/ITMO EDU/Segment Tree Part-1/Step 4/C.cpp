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

//----------------------------------- END DEBUG --------------------------------

struct item {
	vector<long long> uni;
	vector<long long> cnt;
	long long inv;
	void init() {
		uni.assign(42,0);
		cnt.assign(42,0);
		inv = 0;
	}
};
debug & operator << (debug & dd, item p) { dd << "(" << p.uni << ", "<< '\n' << p.cnt << '\n' << p.inv << ")" << '\n'; return dd; }
// debug & operator << (debug & dd, item p) { dd << "(" << p.inv << ")" ; return dd; }

struct segtree {
	int size;

	item NEUTRAL_ELEMENT;


	vector<item> values;

	void init(int n) {
		NEUTRAL_ELEMENT.init();
		size = 1;
		while(size < n) {
			size *= 2;
		}
		values.resize(2 * size);
		for(int i=0;i<2*size;i++) {
			values[i].init();
		}
	}

	item single(int v) {
		item tmp;
		tmp.init();
		tmp.uni[v]++;
		for(int i=1;i<=40;i++) {
			tmp.cnt[i] += tmp.uni[i];
		}
		for(int i=40;i>=1;i--) {
			tmp.cnt[i] = tmp.cnt[i] + tmp.cnt[i+1];
		}
		return tmp;
	}

	item merge(item &a, item &b) {

		// a represents the left part
		// b represents the right part

		item tmp;
		// cerr << a.uni.size() << " " << b.uni.size() << '\n';
		// assert(a.uni.size() == 41 and b.uni.size() == 41);
		tmp.init();
		tmp.inv = a.inv + b.inv;
		long long c = 0; // counts the extra inversions from the left part

		for(int i=1;i<=40;i++) {
			if(b.uni[i] > 0) {
				c += b.uni[i]*a.cnt[i+1];
			}
			tmp.uni[i] = a.uni[i] + b.uni[i];
			tmp.cnt[i] += tmp.uni[i];
		}
		tmp.inv += c;
		for(int i=40;i>=1;i--) {
			tmp.cnt[i] = tmp.cnt[i] + tmp.cnt[i+1];
		}
		return tmp;
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

	long long calc(int l, int r) {
		item res = calc(l, r, 0, 0, size);
		return res.inv;
	}

	/*int find(int val, int l, int x, int lx, int rx) {
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
	}*/
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}

	segtree st;
	st.init(n);

	st.build(a);

	debug()<<imie(st.size);
	debug()<<imie(st.values);

	while(q--) {
		int ch;
		cin >> ch;
		if(ch == 1) {
			int l,r;
			cin >> l >> r;
			l--;
			cout << st.calc(l,r) << '\n';
		}
		else {
			int i,v;
			cin >> i >> v;
			st.set(i-1,v);
		}
	}
}