#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    int n;
    int q;
    srand(time(NULL));
    cin >> n >> q;
    cout << n << " " << q << '\n';
    ll height[n], taste[n];
    for(int i=0;i<n;i++) {
    	height[i] = (rand() % 1000) + 1;
    	cout << height[i] << " ";
    }
    cout << '\n';
    for(int i=0;i<n;i++) {
    	taste[i] = (rand() % 100000) + 1;
    	cout << taste[i] << " ";
    }
    cout << '\n';
    // int flip = (rand() % 2) + 1;
    int flip = 2;
    while(q--) {
    	if(flip == 1) {
    		cout << flip << " " <<  (rand() % n) + 1 << " " << (rand() % 100000) + 1  << '\n';
    	}
    	else {
    		cout << flip << " " << (rand() % n) + 1 << " " << (rand() % n) + 1 << '\n'; 
    	}
    	// flip = (rand() % 2) + 1;
    }

}