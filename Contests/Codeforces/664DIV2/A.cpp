#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

bool check(int a,int b, int c, int d) {
	int s = a+b+c+d;
	bool val;
	if(s % 2 == 0) {
		if(a % 2 == 0 and b % 2 == 0 and c % 2 == 0 and d % 2 == 0) {
			val = true;
		}
		else {
			val = false;
		}
	}
	else {
		int q = 0;
		if(a % 2 == 1) q++;
		if(b % 2 == 1) q++;
		if(c % 2 == 1) q++;
		if(d % 2 == 1) q++;
		if(q == 1) {
			val =  true;
		}
		else {
			val = false;
		}
	}
	return val;
}

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
    	bool exists;
    	exists = check(a,b,c,d);
    	if(exists == true) {
    		cout << "Yes" << '\n';
    		continue;
    	}
    	if(a != 0 and b != 0 and c != 0) {
    		a--;
    		b--;
    		c--;
    		d+=3;
    		exists = check(a,b,c,d);
	    	if(exists == true) {
	    		cout << "Yes" << '\n';
	    		continue;
	    	}
    	}
    	cout << "No" << '\n';
    }
}