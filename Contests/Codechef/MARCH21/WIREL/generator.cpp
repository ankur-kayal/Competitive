#include<bits/stdc++.h>
using namespace std;
typedef long long int uli;

//integer to string
string itos(int v){
  if(v == 0) return "0";   
  string ans = "";
  for(; v != 0; v /= 10) ans = string(1, '0' + (v % 10)) + ans;
  return ans;
}
int randInt (int l, int r){
  return l + rand() % (r - l + 1);
}
int main(){
  srand(time(NULL));
  int N = 1e4;
  int M = 2500;
  int mxc = 1e6;
  int tc = 0;
  for(int tt = 0; tt < 2; tt++){
    for(int L : {8000, 10000, 12000, 14000 , 16000}){
      string fname = itos(tc) + ".in";
      auto fl = freopen(fname.c_str(), "w", stdout);
      printf("%d %d\n", N, M);
      for(int i = 0; i < N; i++){
        printf("%d %d\n", randInt(0, mxc), randInt(0, mxc));
      }
      for(int i = 0; i < M; i++){
        int r = rand() % L + 1;
        int s = rand() % L + 1;
        if (rand() % 2) r = -r;
        if (rand() % 2) s = -s;

        int a = randInt(max(0, -r), min(mxc, mxc - r));
        int b = randInt(max(0, -s), min(mxc, mxc - s));
        printf("%d %d %d %d\n", a, b, a + r, b + s);
      }
      fclose(fl);
      tc++;
    }
  }
  return 0;
}
