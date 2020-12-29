#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    int t;
    cin >> t;
    while(t--) {
    	int n,m,k;
    	cin >> n >> m >> k;
    	ll ans = 0;
    	map <pair<int,int>,int> plants;
    	for(int i=0;i<k;i++) {
    		int r,c;
    		cin >> r >> c;
    		ans+=4;
    		if(plants[{r-1,c}] == 1) ans-=2;
    		if(plants[{r+1,c}] == 1) ans-=2;
    		if(plants[{r,c+1}] == 1) ans-=2;
    		if(plants[{r,c-1}] == 1) ans-=2;
    		plants[{r,c}] = 1;
    	}
    	cout << ans << '\n';
    }
}