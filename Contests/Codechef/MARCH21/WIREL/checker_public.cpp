#include<bits/stdc++.h>

using namespace std;
// #define PIN "secret/2.in"
// #define POUT "secret/2.bad"
// #define TOUT "secret/2.bad"
// #define SCORE "secret/2.scr"

string PIN,POUT,TOUT,SCORE;

void file_name_init(string index) {
  PIN = "secret/" + index + ".in";
  POUT = "secret/" + index + ".bad";
  TOUT = "secret/" + index + ".bad";
  SCORE = "secret/" + index + ".scr";
}

FILE *spoj_p_in, *spoj_p_out, *spoj_t_out, *spoj_score;
void spoj_init(){
  spoj_p_in=fopen(PIN.c_str(), "r");
  spoj_p_out=fopen(POUT.c_str(), "r");
  spoj_t_out=fopen(TOUT.c_str(), "r");
  spoj_score=fopen(SCORE.c_str(), "w");
}

#define spoj_assert assert

using namespace std;

typedef long long int ll;

//Geometry functions
//https://cp-algorithms.com/geometry/check-segments-intersection.html
struct pt {
  ll x, y;
  pt() {}
  pt(ll _x, ll _y) : x(_x), y(_y) {}
  pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
  ll cross(const pt& p) const { return x * p.y - y * p.x; }
  ll cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};
ll d2(pt a, pt b){
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;
  return dx * dx + dy * dy;
}
int sgn(const ll& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(ll a, ll b, ll c, ll d) {
  if (a > b)
    swap(a, b);
  if (c > d)
    swap(c, d);
  return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
  if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
    return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
  return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
    sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}
//End Geometry functions

const ll mxc = 1000000;
const int mxn = 2e4 + 10;
const int mxm = 5e3 + 10;

//wire i is positive if sgn[i] = 1
//wire i is negative if sgn[i] = -1
int sign[mxm];
int main(int argc, char* argv[]){
  file_name_init(string(argv[1]));
  // cerr << file_index;
  spoj_init();
  int n, m;
  fscanf(spoj_p_in, "%d %d", &n, &m); 
  vector<pt> cities(n);
  vector<vector<pt> > wires(m);
  for (int i = 0; i< n; i++){
    int x, y;
    fscanf(spoj_p_in, "%d %d", &x, &y); 
    cities[i].x = x;
    cities[i].y = y;
  }
  for (int i = 0; i < m; i++){
    ll x, y;
    fscanf(spoj_p_in, "%lld %lld", &x, &y);
    wires[i].push_back({ll(x), ll(y)});
    fscanf(spoj_p_in, "%lld %lld", &x, &y);
    wires[i].push_back({ll(x), ll(y)});
  }
  //positive plate
  wires.push_back({{-1, 0}, {0, -1}});
  sign[m] = 1;
  //negative plate
  wires.push_back({{mxc + 1, mxc},{mxc, mxc+1}});
  sign[m + 1] = -1;

  //move wires 
  ll P = 0;
  for (int i = 0; i < m; i++){
    ll di, vi;
    spoj_assert(fscanf(spoj_t_out, "%lld %lld", &di, &vi) == 2);
    spoj_assert(-mxc <= di && di <= mxc);
    spoj_assert(-mxc <= vi && vi <= mxc);
    for (int j = 0; j < 2; j++){
      wires[i][j].x += di;
      wires[i][j].y += vi;
    }
    P += (di*di + vi*vi);
  }

  //pn[0] = all positive wires, pn[1] = all negative wires
  vector<int> pn[2];
  for (int it = 0; it < 2; it++){
    queue<int> q;
    //bfs starting from the plate
    q.push(m + it);
    while (!q.empty()){
      int u = q.front();
      q.pop();
      if (u < m) pn[it].push_back(u);
      pt a = wires[u][0];
      pt b = wires[u][1];
      for (int v = 0; v < m; v++){
        //sgn[v]=0 or there is short-circuit
        if (sign[v] != sign[u]){
          pt c = wires[v][0];
          pt d = wires[v][1];
          if (check_inter(a, b, c, d)){
            //no short-circuits
            spoj_assert(sign[v] != -sign[u]);
            spoj_assert(sign[v] == 0);
            sign[v] = sign[u];
            q.push(v);
          }
        }
      }
    }
  }
  //at least one positive/negative wire
  spoj_assert(!pn[0].empty());
  spoj_assert(!pn[1].empty());

  ll Q = 0;
  for (int i = 0; i < n; i++){
    pt city = cities[i];
    for(int it = 0; it < 2; it++){
      ll best = -1;
      for (int j : pn[it]){        
        ll better = min(d2(wires[j][0], city), d2(wires[j][1], city));
        if (best == -1 || better < best){
          best = better;
        }
      }
      Q += best;
    }
  }
  ll score = P + Q;
  fprintf(spoj_score, "%lld", score);
  cerr << "score = " << score << endl;
  return 0;
}
