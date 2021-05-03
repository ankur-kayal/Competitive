struct centroid {
  vector<vector<int>> edges;
  vector<bool> vis;
  vector<int> par;
  vector<int> sz;
  int n;
 
  void init(int s) {
    n = s;
    edges = vector<vector<int>>(n, vector<int>());
    vis = vector<bool>(n, 0);
    par = vector<int>(n);
    sz = vector<int>(n);
  }
 
  void edge(int a, int b) {
    edges[a].pb(b);
    edges[b].pb(a);
  }
 
  int findSize(int v, int p = -1) {
    if (vis[v]) return 0;
    sz[v] = 1;
 
    for (int x: edges[v]) {
      if (x != p) {
        sz[v] += findSize(x, v);
      }
    }
 
    return sz[v];
  }
 
  int findCentroid(int v, int p, int n) {
    for (int x: edges[v]) {
      if (x != p) {
        if (!vis[x] && sz[x] > n / 2) {
          return findCentroid(x, v, n);
        }
      }
    }
 
    return v;
  }
 
  void initCentroid(int v = 0, int p = -1) {
    findSize(v);
 
    int c = findCentroid(v, -1, sz[v]);
    vis[c] = true;
    par[c] = p;
 
    for (int x: edges[c]) {
      if (!vis[x]) {
        initCentroid(x, c);
      }
    }
  }
};