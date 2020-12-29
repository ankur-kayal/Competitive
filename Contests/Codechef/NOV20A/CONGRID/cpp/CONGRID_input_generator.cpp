//Generator of CONGRID
//This generator provides 12 cases at once.

#include<bits/stdc++.h>

using namespace std;

struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int dx4[4]={1,-1,0,0};
int dy4[4]={0,0,1,-1};

int main(){
  int seed=1;//seed value
  mt19937 engine(seed);
  for(int cs=0;cs<12;cs++){
    int lim;
    if(cs%4==0){lim=8;}
    if(cs%4==1){lim=16;}
    if(cs%4==2){lim=32;}
    if(cs%4==3){lim=64;}
    int n=500;
    UnionFind uf(n*n);

    vector<int> v;//packed (x,y,d)
    for(int i=0;i<4*n*n;i++){v.push_back(i);}
    shuffle(v.begin(),v.end(),engine);

    vector<int> lc(n*n,0);//the number of connections for each cell
    for(int i=0;i<4*n*n;i++){
      //unpack v[i]
      int w=v[i];
      int x,y,d;
      d=(w%4);w/=4;
      y=(w%n);w/=n;
      x=(w%n);
      int dx,dy;
      dx=x+dx4[d];
      dy=y+dy4[d];

      //connect (x,y) & (dx,dy)
      if(dx<0||n<=dx){continue;}
      if(dy<0||n<=dy){continue;}
      if(lc[x*n+y]>=2 || lc[dx*n+dy]>=2){continue;}
      if(uf.size(x*n+y)+uf.size(dx*n+dy)>lim){continue;}
      uf.unionSet(x*n+y,dx*n+dy);
      lc[x*n+y]++;lc[dx*n+dy]++;
    }
    int idc=0;
    for(int i=0;i<n*n;i++){
      if(lc[i]==1){idc++;}
    }
    vector<int> id(idc);//the ids of each endpoint
    for(int i=0;i<idc;i++){id[i]=i+1;}
    shuffle(id.begin(),id.end(),engine);
    vector<int> inx(idc+1),iny(idc+1);
    idc=0;
    for(int i=0;i<n*n;i++){
      if(lc[i]==1){
        inx[id[idc]]=(i/n);
        iny[id[idc]]=(i%n);
        idc++;
      }
    }

    FILE *inp;
    char fn[64];
    sprintf(fn,"input_%02d.txt",cs);
    inp=freopen(fn,"wb",stdout);

    printf("%d %d\n",n,idc);
    for(int i=1;i<=idc;i++){
      //decide t
      int t=engine()%(min(8,lim/4)+1),siz;
      siz=uf.size(inx[i]*n+iny[i]);
      //decide [L_i,R_i]
      int cl,cr;
      while(1){
        cl=siz-(engine()%(t+1));
        cr=cl+t;
        if(2<=cl && cl<=siz && siz<=cr && cr<=lim){break;}
      }
      printf("%d %d %d %d\n",inx[i]+1,iny[i]+1,cl,cr);
    }
    fclose(inp);
  }
  return 0;
}
