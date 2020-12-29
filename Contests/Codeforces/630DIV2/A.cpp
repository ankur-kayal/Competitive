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
    	int a,b,c,d;
    	cin >> a >> b >> c >> d;
    	int x,y,x1,y1,x2,y2;
    	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    	int xd = abs(x1 - x2);
    	int yd = abs(y1 - y2);
    	int xup = max(x1,x2);
    	int xdow = min(x1,x2);
    	int yup = max(y1,y2);
    	int ydow = min(y1,y2);
    	int ab = abs(a-b);
    	int cd = abs(c-d);
    	if(ab <= xd and cd <= yd){
    	// if(a <= xd and b <= xd and c <= yd and d <= yd and x <= xup and xdow <= x and y <= yup and ydow <= y) {
    		cout << "YES" << '\n';
    	}
    	else {
    		cout << "NO" << '\n';
    	}
    }

}