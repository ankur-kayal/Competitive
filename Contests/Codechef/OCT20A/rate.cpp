#include <bits/stdc++.h>
using namespace std;

int main() {
	int d,s;
	cin >> d >> s;
	long long pac = 0;
	long long ptot = 0;
	for(int i=0;i<d;i++) {
		long long tot = 0, ac = 0;
		for(int i=0;i<s;i++) {
			long long foo;
			cin >> foo;
			tot += foo;
		}
		for(int i=0;i<s;i++) {
			long long foo;
			cin >> foo;
			ac += foo;
		}
		if(i == 0) {
			pac = ac;
			ptot = tot; 
		}
		else {
			if(tot * pac == ptot * ac) {
				cout << "Same\n";
			}
			else if(tot * pac < ptot * ac) {
				cout << "Increasing\n";
			}
			else {
				cout << "Decreasing\n";
			}
			pac = ac;
			ptot = tot; 
		}
	}
}