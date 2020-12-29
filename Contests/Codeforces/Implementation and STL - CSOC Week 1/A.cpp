#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array

int findIndex(char ch) {
	int val;
	switch(ch) {
		case '2':
			val = 0;
			break;
		case '3':
			val = 1;
			break;
		case '4':
			val = 2;
			break;
		case '5':
			val = 3;
			break;
		case '6':
			val = 4;
			break;
		case '7':
			val = 5;
			break;
		case '8':
			val = 6;
			break;
		case '9':
			val = 7;
			break;
		case 'T':
			val = 8;
			break;
		case 'J':
			val = 9;
			break;
		case 'Q':
			val = 10;
			break;
		case 'K':
			val = 11;
			break;
		case 'A':
			val = 12;
			break;
		default:
			val = 13;		
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

    string table;
    cin >> table;
    bool ok = 0;
    string tmp;
    vector <int> vals = {2,3,4,5,6,7,8,9,10,11,12,13,14};
    for(int i=0;i<5;i++) {
    	cin >> tmp;
    	if(tmp[1] == table[1] or findIndex(tmp[0]) == findIndex(table[0])) {
    		ok = 1;
    		// cout << tmp << " " << table << '\n';
    		break;
    	}
    }
    cout << (ok == 1 ? "YES" : "NO") << '\n';
}