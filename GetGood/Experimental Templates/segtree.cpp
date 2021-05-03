struct segtree {
  int n, depth;
  ll tree[2100000], lazy[2100000];
 
  void init(int s, long long* arr) {
    n = s;
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
    init(0, 0, n - 1, arr);
  }
 
  ll init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];
 
    int mid = (l + r) / 2;
    ll a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = min(a, b);
  }
 
  void update(int l, int r, ll v) {
	if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }
 
  ll update(int i, int tl, int tr, int ql, int qr, ll v) {
    eval_lazy(i, tl, tr);
	
	if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] += v;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    if (tl == tr) return tree[i];
 
    int mid = (tl + tr) / 2;
    ll a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = min(a, b);
  }
 
  ll query(int l, int r) {
	if (l > r) return 0;
    return query(0, 0, n-1, l, r);
  }
 
  ll query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
	    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return 0;
 
    int mid = (tl + tr) / 2;
    ll a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return min(a, b);
  }
 
  void eval_lazy(int i, int l, int r) {
    tree[i] += lazy[i];
    if (l != r) {
      lazy[i * 2 + 1] += lazy[i];
      lazy[i * 2 + 2] += lazy[i];
    }
 
    lazy[i] = 0;
  }
  
  ll q(ll i, ll tl, ll tr, ll v) {
	 eval_lazy(i, tl, tr);
	 if (tl == tr) return tl;
	 
	 int mid = (tl + tr) / 2;
	 eval_lazy(2 * i + 1, tl, mid);
	 if (tree[2 * i + 1] < v) return q(2 * i + 1, tl, mid, v);
	 return q(2 * i + 2, mid + 1, tr, v);
  }
};