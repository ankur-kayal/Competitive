#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	const int mxN = 1e8;
	if(n < 1 or n > mxN) {
		cout << "Wrong Input";
		exit(0);
	}
	set<int> divs;
	for(int i=1;i*i<=n;i++) {
		if(n % i == 0) {
			divs.insert(i);
			divs.insert(n / i);
		}
	}
	for(int u: divs) {
		cout << u << " ";
	}
}