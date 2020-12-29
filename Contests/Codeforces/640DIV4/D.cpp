#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array

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
    	int n;
    	cin >> n;
    	list <int> a;
    	for(int i=0;i<n;i++) {
    		int tmp;
    		cin >> tmp;
    		a.pb(tmp);
    	}
    	int moves = 0, A = 0, B = 0;
    	bool ch = 0;
    	int tmp1 = 0,tmp2 = 0;
    	while(a.size() != 0) {
    		if(ch == 0) {
    			tmp1 = 0;
    			while(tmp1 <= tmp2 and a.size() != 0){
    				tmp1 += a.front();
    				a.pop_front();
    			}
    			A+=tmp1 ;
    			ch = !ch;
    			moves++;
    			continue;
    		}
    		if(ch == 1) {
    			tmp2 = 0;
    			while(tmp2 <= tmp1 and a.size() != 0) {
    				tmp2 += a.back();
    				a.pop_back();
    			}
    			B+=tmp2 ;
    			ch = !ch;
    			moves++;
    			continue;

    		}
    		// moves++;
    		// cout << tmp1 + 1 << " " << tmp2 + 1 << '\n';
    		// break;
    	}
    	cout << moves << " " << A << " " << B << '\n';
    }
}