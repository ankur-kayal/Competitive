#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
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

const long long INF = 1LL << 60;

using Pt = pair<long long, long long>;
#define x first
#define y second

long long cross(const Pt &a, const Pt &b, const Pt &o = Pt(0, 0)) {
  return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

template <class It>
vector<Pt> convex_hull(It lo, It hi) {
  int k = 0;
  if (hi - lo <= 1) {
    return vector<Pt>(lo, hi);
  }
  vector<Pt> res(2 * distance(lo, hi));
  sort(lo, hi);
  for (It it = lo; it != hi; ++it) {
    while (k >= 2 && cross(res[k - 1], *it, res[k - 2]) >= 0) {
      k--;
    }
    res[k++] = *it;
  }
  int t = k + 1;
  for (It it = hi - 2; it != lo - 1; --it) {
    while (k >= t && cross(res[k - 1], *it, res[k - 2]) >= 0) {
      k--;
    }
    res[k++] = *it;
  }
  res.resize(k - 1);
  return res;
}

int N;
long long K, D;

long long solve() {
  cin >> N >> K >> D;
  vector<Pt> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i].x >> P[i].y;
  }
  auto hull = convex_hull(P.begin(), P.end());
  sort(hull.begin(), hull.end());
  debug() << imie(hull);
  int V = hull.size();
  // Find start/end.
  int start = -1, dest = -1;
  for (int i = 0; i < V; i++) {
    if (hull[i] == P[0]) {
      start = i;
    } else if (hull[i] == P[N - 1]) {
      dest = i;
    }
  }
  // Dijkstra in O(V^2) time / O(V) space.
  vector<bool> vis(V);
  vector<long long> dist(V, INF);
  dist[start] = 0;
  while (true) {
    int u = -1;
    long long mindist = INF;
    for (int i = 0; i < V; i++) {
      if (!vis[i] && mindist > dist[i]) {
        u = i;
        mindist = dist[i];
      }
    }
    if (mindist == INF || u == dest) {
      break;
    }
    vis[u] = true;
    for (int v = 0; v < V; v++) {
      long long d = (hull[u].x - hull[v].x) * (hull[u].x - hull[v].x) +
                    (hull[u].y - hull[v].y) * (hull[u].y - hull[v].y);
      if (!vis[v] && d <= D*D && dist[v] > dist[u] + max(K, d)) {
        dist[v] = dist[u] + max(K, d);
      }
    }
  }
  return dist[dest] < INF ? dist[dest] : -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("c_final_input.txt", "r", stdin);
  // freopen("c_final_output2.txt", "w", stdout);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
