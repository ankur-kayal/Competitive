#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
// #define ff first
// #define ss second

const int mxN = 2e5 + 10;

ll st[4 * mxN];

vector <ll> h(mxN), a(mxN), decr(mxN), incr(mxN);

map <ll,ll> pos;

const ll mxm = 2e9;

void build( int si, int ss, int se ) {
	if( ss == se ) { // this represents the base case
		st[si] = h[ss];
		return;
	}

	int mid = ( ss + se ) / 2; // dividing the existing segment into two child segments
	build( 2 * si, ss, mid ); // calculate the value of the left child
	build( 2 * si + 1, mid + 1, se ); // calculate the value of the right child
	st[si] = max(st[si*2], st[si*2+1]); // this is the logic of the segment tree, here it is used to build a min segment tree, change this according to the needs of the question
}

// the query function is used to return the answer of the segment arr[qs,qe]
// qs -> query range starting index
// qe -> query range ending index
// si -> segment tree index
// ss -> segment starting index
// se -> segment ending index
ll query( int si, int ss, int se, int qs, int qe ) {
	if(qs > se || qe < ss) // if the segment [se,ss] is completely outside the answer segment [qs,qe], return something that doesn't change the answer
	return -1;

	if(qs <= ss and se <= qe) { //if the segment [se,ss] is completely inside the answer segment [qs,qe], return the answer stored in the si index of the segment tree
		return st[si];
	}

	//if the segment [se,ss] is completely inside the answer segment [qs,qe], 
	// divide it into left and right child segments and call the query fucntion recursively to calculate the answer

	int mid = (ss + se) / 2; // find the mid of the segment
	return (max(query( 2 * si, ss, mid, qs, qe ), query( 2 * si + 1, mid + 1, se, qs, qe))); // use the value of the left and right child to find the value of the required range
}


// the update function updates point updates
// qi  -> the index value where the value is to be updated to the value val
// val -> the new value
// si -> segment tree index
// ss -> segment starting index
// se -> segment ending index
void update( int si, int ss, int se, int qi, ll val) {
	if(ss == se) { // when we reach the index which needs to be updated 
		st[si] = val; // we update with the new value val
		return;
	}

	int mid = ( ss + se ) / 2; // finding the middle of the segment

	if(qi <= mid) // if qi is in the left segment update the left segment
		update( 2 * si, ss, mid, qi, val);
	else // if qi is in the left segment update the right segment segment
		update(2 * si + 1, mid + 1, se, qi, val); 
	st[si] = max(st[si*2],st[si*2+1]); // finally update the tree using the left and right segment values
}


void buildDecr(int n) {
	pos.clear();
	set <ll> unique;
	pos[mxm] = n+1;
	unique.insert(mxm);
	decr[n+1] = 0;
	for(int i=n;i>=1;i--) {
		ll Greater = *unique.upper_bound(h[i]);
		decr[i] = a[i] + decr[pos[Greater]];
		pos[h[i]] = i;
		unique.insert(h[i]);
		while(*unique.begin() < h[i]) {
			unique.erase(*unique.begin());
		}
	}
	// for(int i=1;i<=n;i++) {
	// 	cout << decr[i] << " ";
	// }
	// cout << '\n';
}

void buildIncr(int n) {
	pos.clear();
	set <ll> unique;
	pos[mxm] = 0;
	unique.insert(mxm);
	incr[0] = 0;
	for(int i=1;i<=n;i++) {
		ll Greater = *unique.upper_bound(h[i]);
		incr[i] = a[i] + incr[pos[Greater]];
		pos[h[i]] = i;
		unique.insert(h[i]);
		while(*unique.begin() < h[i]) {
			unique.erase(*unique.begin());
		}

	}
	// for(int i=1;i<=n;i++) {
	// 	cout << incr[i] << " ";
	// }
	// cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    ll n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) {
    	cin >> h[i];
    }
    for(int i=1;i<=n;i++) {
    	cin >> a[i];
    }
    h[n+1] = mxm;
    a[n+1] = 0;
    build(1,1,n);
    buildDecr(n);
    buildIncr(n);
    while(q--) {
    	ll ch, start,end,value;
    	cin >> ch;
    	if(ch == 1) {
    		cin >> start >> value;
    		a[start] = value;
    		// update(1,1,n,start,value);
    		buildDecr(n);
    		buildIncr(n);
    	}
    	else if(ch == 2) {
    		cin >> start >> end;
    		
    		if(end < start) {
    			if(query(1,1,n,end + 1,start - 1) < h[start] and h[end] < h[start])
    				cout << decr[end] - decr[start] + a[start] << '\n';
    			else {
    				cout << -1 << '\n';
    				// cout << query(1,1,n,end,start) << '\n';
    			}
    		}
    		else if(end > start) {
    			if(query(1,1,n,start + 1,end - 1) < h[start] and h[end] < h[start]) {
    				cout << incr[end] - incr[start] + a[start] << '\n';
    			}
    			else {
    				cout << -1 << '\n';
    				// cout << query(1,1,n,start,end) << '\n';
    			}
    		}
    		else {
    			cout << a[start] << '\n';
    		}
    	}
    }
}