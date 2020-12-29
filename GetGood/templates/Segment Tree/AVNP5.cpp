// problem link -> https://www.codechef.com/problems/AVNP5

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array

const int mxN = 1e6+10;

int st[4 * mxN];
string s;


void build(int si, int ss, int se) {
	if(ss == se) {
		if(s[ss] == 'e' || s[ss] == 'a' || s[ss] == 'i' || s[ss] == 'o' || s[ss] == 'u') {
			st[si] = 1;
		}
		else {
			st[si] = 0;
		}
		return;
	}

	int mid = (ss + se) / 2;
	build(2 * si, ss, mid);
	build(2 * si + 1, mid + 1, se);

	st[si] = st[2 * si] + st[2 * si + 1];
}

int query(int si, int ss, int se, int qs, int qe) {
	if(qe < ss or qs > se) {
		return 0;
	}

	if(qe >= se and qs <= ss) {
		return st[si];
	}

	int mid = (ss + se) / 2;
	return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}

void update(int si, int ss, int se, int qi, char ch) {
	if(ss == se) {
		if(ch ==  'e' || ch ==  'a' || ch ==  'i' || ch ==  'o' || ch ==  'u') {
			st[si] = 1;
		}
		else {
			st[si] = 0;
		}
		return;
	}

	int mid = (ss + se) / 2;

	if(qi <= mid) update(2 * si, ss, mid, qi, ch);
	else update(2 * si + 1, mid + 1, se, qi, ch);

	st[si] = st[2 * si] + st[2 * si + 1];
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
    while(t--) {
    	cin >> s;
    	int n = s.length();
    	s = '#' + s;
    	build(1,1,n);
    	int q;
    	cin >> q;
    	while(q--) {
    		char sw,ch;
    		int qi,l,r;
    		cin >> sw;
    		if(sw == 'F') {
    			cin >> l >> r;
    			cout << query(1,1,n,l,r) << '\n';
    		}
    		else if(sw == 'U') {
    			cin >> qi >> ch;
    			update(1,1,n,qi,ch);
    		}
    	}
    }
}