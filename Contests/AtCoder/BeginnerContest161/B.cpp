#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	/*#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
	#endif*/

    int n,m;
    cin >> n >> m;
    int tot = 0;
    vector <int> a(n);
    for(int i=0;i<n;i++) {
    	cin >> a[i];
    	tot+=a[i];
    }
    int mxm = ceil((double)tot / (4 * m));
    int count = 0;
    for(int i=0;i<n;i++) {
    	if(a[i] >= mxm) {
    		count++;
    	}
    }
    if(count >= m) {
    	cout << "Yes" << '\n';
    }
    else {
    	cout << "No" << '\n';
    }

}