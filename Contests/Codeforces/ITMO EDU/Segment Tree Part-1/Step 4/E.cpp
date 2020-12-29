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
	int sum;
};

debug & operator << (debug & dd, item p) { dd << "(" << p.sum  << ")"; return dd; }

struct segtree {
	int size;
	int ans;

	item NEUTRAL_ELEMENT = {INT_MAX};


	vector<item> values;

	void init(int n) {
		size = 1;
		ans = 0;
		while(size < n) {
			size *= 2;
		}
		values.assign(2 * size,{INT_MAX});
	}

	item single(int v) {
		return {v};
	}

	item merge(item &a, item &b) {
		return {min(a.sum,b.sum)};
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

	void find(int l,int r,int v,int &j,int x,int lx,int rx) { 
		if(l>=rx || lx>=r || values[x].sum>v)return; 
		if(rx-lx==1) { 
			values[x].sum=INT_MAX; 
			j++; 
			return; 
		} 
		int m=(lx+rx)/2; 
		find(l,r,v,j,2*x+1,lx,m); 
		find(l,r,v,j,2*x+2,m,rx); 
		values[x]=merge(values[2*x+1],values[2*x+2]); 
	} 

	void find(int l,int r,int v,int &j) { 
		find(l,r,v,j,0,0,size); 
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;
	cin >> n >> m;
	segtree st;
	st.init(n);

	while(m--) {
		int op;
		cin >> op;
		if(op == 1) {
			int i,v;
			cin >> i >> v;
			st.set(i,v);
			debug() << imie(st.values);
		}
		else {
			int l,r,p;
			cin >> l >> r >> p;
			int ans = 0;
			st.find(l,r,p,ans);
			debug() << imie(st.values);
			cout << ans << '\n';
		}
	}

}