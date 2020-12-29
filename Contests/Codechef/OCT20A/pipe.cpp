#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,m,r;
	cin >> n >> m >> r;

	long long sum1 = 0, sum2 = 0;
	for(int i=0;i<n;i++) {
		long long foo;
		cin >> foo;
		sum1 += (foo - r);
	}

	for(int i=0;i<m;i++) {
		long long foo;
		cin >> foo;
		sum2 += (foo - r);
	}

	if(sum1 == sum2) {
		cout << "BALANCED";
	}
	else if(sum1 > sum2) {
		cout << -1LL * (sum1 - sum2 + r);
	}
	else {
		cout << (sum2 - sum1 + r);
	}
}