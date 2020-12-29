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

mt19937 rnd;

struct Treap {
	long long data, priority;
	vector<Treap *> kids;
	int subTreeSize;
	Treap() {};
	Treap(long long data);
};

Treap *root;

int size(Treap *me) {
	return (me == NULL ? 0 : me->subTreeSize);
}

void recalc(Treap *me) {
	if(me == NULL) return;
	me->subTreeSize = 1;
	for(Treap *t : me->kids) {
		if(t != NULL) {
			me->subTreeSize += t->subTreeSize;
		}
	}
}

Treap *merge(Treap *left, Treap *right) {
	if(left == NULL) return right;
	if(right == NULL) return left;

	if(left->priority < right->priority) {
		left->kids[1] = merge(left->kids[1], right);
		recalc(left);
		return left;
	}
	else {
		right->kids[0] = merge(left, right->kids[0]);
		recalc(right);
		return right;
	}
}

vector<Treap *> split(Treap *me, int nInLeft) {
	if(me == NULL) return {NULL,NULL};

	// check if the split line is in the left side of me
	if(size(me->kids[0]) >= nInLeft) {
		vector<Treap *> leftRes = split(me->kids[0], nInLeft);
		me->kids[0] = leftRes[1];
		recalc(me);
		return {leftRes[0], me};
	}
	else {
		nInLeft = nInLeft - size(me->kids[0]) - 1;
		vector<Treap *> rightRes = split(me->kids[1],nInLeft);
		me->kids[1] = rightRes[0];
		recalc(me);
		return {me, rightRes[1]};
	}
	return {NULL,NULL};
}

Treap::Treap(long long _data) {
	this->data = _data;
	this->priority = rnd();
	this->kids = {NULL, NULL};
	recalc(this);
}

Treap* exchange(Treap *t, int al, int ar, int bl, int br) {
	debug() << imie(al) imie(ar) imie(bl) imie(br);
	vector<Treap *> a1 = split(t,al), a2 = split(a1[1], ar-al+1);
	bl = bl - ar - 1;
	br = br - ar - 1;
	debug() << imie(bl) imie(br);
	vector<Treap *> b1 = split(a2[1],bl), b2 = split(b1[1], br-bl+1);

	return merge(merge(merge(merge(a1[0], b2[0]), b1[0]), a2[0]), b2[1]);
}

long long extractElement(Treap *t, int l) {
	int ans;
	vector<Treap *> a = split(t,l), b = split(a[1],1);
	ans = b[0]->data;
	root = merge(a[0], merge(b[0],b[1]));
	return ans;
}

void init(vector<long long>&a) {
	root = NULL;
	for(auto u: a) {
		Treap *tmp = new Treap(u);
		root = merge(root, tmp);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i=0;i<n;i++) {
		a[i] = (i+1);
	}
	init(a);
	// cout << root->kids[1]->data;
	for(int i=0;i<n;i++) {
		int u,v;
		cin >> u >> v;
		if(v > u) {
			int length = min(n-v, v-u-1);
			--u, --v;

			root = exchange(root, u,u+length,v,v+length);
		}
	}

	for(int i=0;i<n;i++) {
		a[i] = extractElement(root, i);
	}
	for(auto u: a) {
		cout << u << " ";
	}
	cout << '\n';
}