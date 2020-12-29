#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

char ch;

int findIndex(string s) {
	int n = s.length();
	for(int i=0;i<n-2;i++) {
		map <char, int> count;
		count[s[i]]++;
		count[s[i+1]]++;
		count[s[i+2]]++;
		if(count['A'] != 0 and count['B'] != 0) {
			ch = (count['A'] > count['B'] ? 'A' : 'B');
			bool exists = true;
			if(i-1 >= 0 and i+3 < n) {
				if(s[i] == ch and s[i+3] == ch) {
					exists = false;
				}
			}
			if(exists) {
				return i;
			}
		}
	}
	return -1;
}

string modifyStone(string s, int index) {
	string updated;
	updated = s.substr(0,index) + ch + (index + 3 < s.size() ? s.substr(index+ 3) : "");
	return updated;
}

void solve() {
	int n;
	cin >> n;
	string stone;
	cin >> stone;
	bool exists = true;
	while(stone.length() != 1) {
		int index = findIndex(stone);
		if(index == -1) {
			exists = false;
			break;
		}
		stone = modifyStone(stone, index);
		// cout << stone << '\n';
	}
	cout << (exists ? 'Y' : 'N') << '\n';

}

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
    for(int i=1;i<=t;i++) {
    	cout << "Case #" << i << ":" << '\n';
    	solve();
    }
}