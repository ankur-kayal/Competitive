#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cout << "\nEnter n: ";
	cin >> n;
	cout << "\nEnter values of the array: \n";
	vector <int> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}

	while(true) {
		cout << "\nEnter choice: ";
		int ch;
		cin >> ch;
		if(ch == -1) goto end;
		int ans = 0;
		for(int i=0;i<n;i++) {
			ans += a[i] xor ch;
		}
		cout << ans << '\n';
	}
	end: ;
}