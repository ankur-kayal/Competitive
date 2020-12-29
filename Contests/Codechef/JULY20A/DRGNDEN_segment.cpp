#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
// #define ff first
// #define ss second

const int mxN = 2e5 + 10;

struct node {
	set <ll> range;
	set <ll> height;
	ll sum;
};

ll st[4 * mxN];

node decr[4 * mxN], incr[4*mxN];
node qrange;

vector <ll> h(mxN), a(mxN);

vector <ll> pos(4 * mxN);

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


void buildDecr(int si, int ss, int se) {
	// cout << si << '\n';
	if( ss == se ) { // this represents the base case
		decr[si].sum = a[ss];
		decr[si].range.insert(ss);
		decr[si].height.insert(h[ss]);
		pos[ss] = si;
		return;
	}

	int mid = ( ss + se ) / 2; // dividing the existing segment into two child segments
	buildDecr( 2 * si + 1, mid + 1, se ); // calculate the value of the right child
	buildDecr( 2 * si, ss, mid ); // calculate the value of the left child
	ll leftLargest = *decr[2 * si].height.rbegin();

	decr[si].sum = decr[2 * si].sum + decr[2 * si + 1].sum;
	for(auto u: decr[2 * si + 1].range) {
		if(h[u] < leftLargest) {
			decr[si].sum-=a[u];
		}
		else {
			decr[si].range.insert(u);
			decr[si].height.insert(h[u]);
		}
	}
	for(auto u: decr[2 * si].range) {
		decr[si].range.insert(u);
		decr[si].height.insert(h[u]);
	}
}

void buildIncr(int si, int ss, int se) {
	// cout << si << '\n';
	if( ss == se ) { // this represents the base case
		decr[si].sum = a[ss];
		decr[si].range.insert(ss);
		decr[si].height.insert(h[ss]);
		pos[ss] = si;
		return;
	}

	int mid = ( ss + se ) / 2; // dividing the existing segment into two child segments
	buildIncr( 2 * si + 1, mid + 1, se ); // calculate the value of the right child
	buildIncr( 2 * si, ss, mid ); // calculate the value of the left child
	ll rightLargest = *decr[2 * si + 1].height.rbegin();

	decr[si].sum = decr[2 * si].sum + decr[2 * si + 1].sum;
	for(auto u: decr[2 * si].range) {
		if(h[u] < rightLargest) {
			decr[si].sum-=a[u];
		}
		else {
			decr[si].range.insert(u);
			decr[si].height.insert(h[u]);
		}
	}
	for(auto u: decr[2 * si + 1].range) {
		decr[si].range.insert(u);
		decr[si].height.insert(h[u]);
	}
}

void queryDecr(int si, int ss, int se, int qs, int qe) {
	// cout << si << '\n';
	if(qs > se || qe < ss) // if the segment [se,ss] is completely outside the answer segment [qs,qe], return something that doesn't change the answer
	return ;

	if(qs <= ss and se <= qe) { //if the segment [se,ss] is completely inside the answer segment [qs,qe], return the answer stored in the si index of the segment tree
		// cout << si << " o" << ' ';
		qrange.sum += decr[si].sum;
		if(qrange.range.size() == 0) {
			for(auto u: decr[si].range) {
				qrange.range.insert(u);
				qrange.height.insert(h[u]);
			}
		}
		else {
			ll leftLargest = *decr[si].height.rbegin();
			// cout << leftLargest << " ";
			for(auto u: qrange.range) {
				if(h[u] < leftLargest) {
					qrange.sum-=a[u];
					qrange.range.erase(u);
					qrange.height.erase(h[u]);
				}
				else {
					qrange.range.insert(u);
					qrange.height.insert(h[u]);
				}
			}
			for(auto u: decr[si].range) {
				qrange.range.insert(u);
				qrange.height.insert(h[u]);
			}
		}
		// for(auto u: qrange.range) {
	 //    	cout << u << ' ';
	 //    }
	 //    cout << '\n';
		return;
	}

	//if the segment [se,ss] is completely inside the answer segment [qs,qe], 
	// divide it into left and right child segments and call the query fucntion recursively to calculate the answer

	int mid = (ss + se) / 2; // find the mid of the segment
	queryDecr( 2 * si + 1, mid + 1, se, qs, qe); // right query
	queryDecr( 2 * si, ss, mid, qs, qe ); // left query

	// return (max(query( 2 * si, ss, mid, qs, qe ), query( 2 * si + 1, mid + 1, se, qs, qe)));
}

void queryIncr(int si, int ss, int se, int qs, int qe) {
	// cout << si << '\n';
	if(qs > se || qe < ss) // if the segment [se,ss] is completely outside the answer segment [qs,qe], return something that doesn't change the answer
	return ;

	if(qs <= ss and se <= qe) { //if the segment [se,ss] is completely inside the answer segment [qs,qe], return the answer stored in the si index of the segment tree
		// cout << si << " o" << ' ';
		qrange.sum += decr[si].sum;
		if(qrange.range.size() == 0) {
			for(auto u: decr[si].range) {
				qrange.range.insert(u);
				qrange.height.insert(h[u]);
			}
		}
		else {
			ll rightLargest = *decr[si].height.rbegin();
			// cout << leftLargest << " ";
			for(auto u: qrange.range) {
				if(h[u] < rightLargest) {
					qrange.sum-=a[u];
					qrange.range.erase(u);
					qrange.height.erase(h[u]);
				}
				else {
					qrange.range.insert(u);
					qrange.height.insert(h[u]);
				}
			}
			for(auto u: decr[si].range) {
				qrange.range.insert(u);
				qrange.height.insert(h[u]);
			}
		}
		// for(auto u: qrange.range) {
	 //    	cout << u << ' ';
	 //    }
	 //    cout << '\n';
		return;
	}

	//if the segment [se,ss] is completely inside the answer segment [qs,qe], 
	// divide it into left and right child segments and call the query fucntion recursively to calculate the answer

	int mid = (ss + se) / 2; // find the mid of the segment
	queryIncr( 2 * si, ss, mid, qs, qe ); // left query
	queryIncr( 2 * si + 1, mid + 1, se, qs, qe); // right query

	// return (max(query( 2 * si, ss, mid, qs, qe ), query( 2 * si + 1, mid + 1, se, qs, qe)));
}

void updateDecr(int qi, ll val) {
	ll child = pos[qi];
	decr[child].sum = decr[child].sum - a[qi] + val;
	// cout << decr[child].sum << "child \n";
	while(child != 0) {
		ll parent = child / 2;
		child = parent;
		if(decr[parent].range.find(qi) != decr[parent].range.end()) {
			decr[parent].sum = decr[parent].sum - a[qi] + val;
			// cout << decr[parent].sum << "o \n";
		}
		else {
			break;
		}
	}
	return;	
}

void updateIncr(int qi, ll val) {
	ll child = pos[qi];
	incr[child].sum = incr[child].sum - a[qi] + val;
	// cout << incr[child].sum << "child \n";
	while(child != 0) {
		ll parent = child / 2;
		child = parent;
		if(incr[parent].range.find(qi) != incr[parent].range.end()) {
			incr[parent].sum = incr[parent].sum - a[qi] + val;
			// cout << incr[parent].sum << "o \n";
		}
		else {
			break;
		}
	}
	return;	
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
    buildDecr(1,1,n);
    // for(int i=1;i<=4 * n;i++) {
    // 	cout << i << " " << decr[i].sum << " uuu ";
    // 	for(auto u: decr[i].range) {
    // 		cout << u << " ";
    // 	}
    // 	cout << '\n';
    // }
    // queryDecr(1,1,n,3,7);
    // // cout << qrange.sum << '\n';
    // updateDecr(3,10);
    // qrange.sum = 0;
    // qrange.range.clear();
    // qrange.height.clear();
    // queryDecr(1,1,n,3,7);
    // cout << qrange.range.size() << '\n';
    // for(auto u: qrange.range) {
    // 	cout << u << " 00 " << h[u] << '\n';
    // }
    // cout << '\n';
    // cout << qrange.sum << '\n';
    // buildIncr(n);
    while(q--) {
    	qrange.sum = 0;
	    qrange.range.clear();
	    qrange.height.clear();
    	ll ch, start,end,value;
    	cin >> ch;
    	if(ch == 1) {
    		cin >> start >> value;
    		a[start] = value;
    		// update(1,1,n,start,value);
    		updateDecr(start,value);
    		updateIncr(start,value);
    	}
    	else if(ch == 2) {
    		cin >> start >> end;
    		
    		if(end < start) {
    			if(query(1,1,n,end + 1,start - 1) < h[start] and h[end] < h[start]) {
    				queryDecr(1,1,n, end, start);
    				cout << qrange.sum << '\n';
    			}
    			else {
    				cout << -1 << '\n';
    				// cout << query(1,1,n,end,start) << '\n';
    			}
    		}
    		else if(end > start) {
    			if(query(1,1,n,start + 1,end - 1) < h[start] and h[end] < h[start]) {
    				queryDecr(1,1,n, start, end);
    				cout << qrange.sum << '\n';
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