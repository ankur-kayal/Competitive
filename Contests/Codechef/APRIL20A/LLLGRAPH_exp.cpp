#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

#include<bits/stdc++.h>
using namespace std;
#define max 5005
//array to store graph
bool arr[max][max];
bool vis[max][max];
//check if minimum vertex cover exists
bool check_cover(int V, int k, int E) {
   int set = (1 << k) - 1;
   int limit = (1 << V);
   //to mark the edges of size 'k'
   // bool vis[max][max];
   while (set < limit) {
      //resetting the vertex cover for each iteration
      memset(vis, 0, sizeof vis);
      int count = 0;
      //checking the values which has a high value
      for (int j = 1, v = 1 ; j < limit ; j = j << 1, v++) {
         if (set & j) {
            //marking the edges visited
            for (int k = 1 ; k <= V ; k++) {
               if (arr[v][k] && !vis[v][k]) {
                  vis[v][k] = 1;
                  vis[k][v] = 1;
                  count++;
               }
            }
         }
      }
      //if all the edges are covered
      if (count == E)
         return true;
      int c = set & -set;
      int r = set + c;
      set = (((r^set) >> 2) / c) | r;
   }
   return false;
}
//to find minimum vertex cover
int find_cover(int n, int m) {
   //performing binary search
   int left = 1, right = n;
   while (right > left){
      int mid = (left + right) >> 1;
      if (check_cover(n, mid, m) == false)
         left = mid + 1;
      else
         right = mid;
   }
   return left;
}
//inserting edge in the graph
void add_edge(int u, int v) {
   arr[u][v] = 1;
   arr[v][u] = 1;
}
// int main() {
//    memset(arr, 0, sizeof arr);
//    int V = 6, E = 5;
//    add_edge(2, 3);
//    add_edge(2, 4);
//    add_edge(3, 5);
//    add_edge(4, 5);
//    add_edge(4, 6);
//    cout << "Size of Minimum Vertex Cover : " << find_cover(V, E) << endl;
//    return 0;
// }

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
	#endif


    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<=n;i++) {
		for(int j=0;j<=n;j++) {
			arr[i][j] = 0;
		}
	}
    
    assert(k == 1);
    // edge arr[m];
    int a,b;
    for(int i=0;i<m;i++) {
    	cin >> a >> b;
    	add_edge(a,b);
    }
    cout << find_cover(n, m) << '\n';

}