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

    vector <ll> lunlun(100005);
    int arr[3] = {1,1,9};
    for(int i=1;i<=10;i++) {
    	lunlun[i] = i;
    }
    int index = 0;
    for(int i=11;i<=100000;i++) {
    	ll d1 = lunlun[i-1] % 10;
    	ll d2 = (lunlun[i-1] / 10) % 10;
    	if(abs(d2 - d1 - 1) <= 1) {
    		lunlun[i] = lunlun[i-1] + 1;
    	}
    	else {
    		lunlun[i] = lunlun[i-1] + 9;
    	}
    	
    }
    for(auto i: lunlun) {
    	cout << i << '\n';
    }
    int n;
    cin >> n;
    cout << lunlun[n];
}