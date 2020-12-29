#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

const int mxN = 1e7 + 10;
vector <int> primes(mxN);

void seive() {
	for(int i=1;i<mxN;i++) {
		primes[i] = i;
	}
	for(int i=2;i*i<mxN;i++) {
		if(primes[i] == i) {
			for(int j=i*i;j<mxN;j+=i) {
				primes[j] = min(primes[j],i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    int n;
    cin >> n;
    int d1[n];
    int d2[n];
    int a[n];
    for(int i=0;i<n;i++) {
    	cin >> a[i];
    }
    seive();
    // for(auto u: primes) {
    // 	cout << u << '\n';
    // }
    for(int i=0;i<n;i++) {
    	int ele = a[i];
    	set <int> fact;
    	while(primes[ele] != 1) {
    		fact.insert(primes[ele]);
    		ele/=primes[ele];
    	}
    	// cout << fact.size() << '\n';
    	// for(auto u: fact) {
    	// 	cout << u << " ";
    	// }
    	// cout << '\n';
    	if(fact.size() > 1) {
    		d1[i] = *fact.begin();
    		fact.erase(d1[i]);
    	// 	for(auto u: fact) {
    	// 	cout << u << " ";
    	// }
    	// cout << '\n';
    		int mul =1;
    		while(fact.size() != 0) {
    			mul*=*fact.begin();
    			fact.erase(*fact.begin());
    		}
    		d2[i] = mul;
    	}
    	else {
    		d1[i] = -1;
    		d2[i] = -1;
    	}
    }
    for(int i=0;i<n;i++) {
    	cout << d1[i] << " ";
    }
    cout << '\n';
    for(int i=0;i<n;i++) {
    	cout << d2[i] << " ";
    }
}