#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10; // the maximum number of elements in the array on which segment tree is to be build
const int maximum = 1e9;
const int minimum = -1e9;
// change the value types of arrays and segment trees according to the questions to avoid overflow for large numbers
int arr[maxN]; // original elements of the array is stored
pair<int,int> st[4 * maxN]; // declaring the segment tree as an array as segment tree contains a maximum of 4 * number of elements of the array

// the build function is used to build the segment tree
// si -> segment tree index
// ss -> segment starting index
// se -> segment ending index
void build( int si, int ss, int se ) {
	if( ss == se ) { // this represents the base case
		st[si] = {arr[ss],arr[ss]};
		return;
	}

	int mid = ( ss + se ) / 2; // dividing the existing segment into two child segments
	build( 2 * si, ss, mid ); // calculate the value of the left child
	build( 2 * si + 1, mid + 1, se ); // calculate the value of the right child
	st[si].first = min(st[si*2].first, st[si*2+1].first); // this is the logic of the segment tree, here it is used to build a min segment tree, change this according to the needs of the question
	st[si].second = max(st[si*2].second, st[si*2+1].second);
}

// the query function is used to return the answer of the segment arr[qs,qe]
// qs -> query range starting index
// qe -> query range ending index
// si -> segment tree index
// ss -> segment starting index
// se -> segment ending index
pair<int,int> query( int si, int ss, int se, int qs, int qe ) {
	if(qs > se || qe < ss) // if the segment [se,ss] is completely outside the answer segment [qs,qe], return something that doesn't change the answer
	return {maximum, minimum};

	if(qs <= ss and se <= qe) { //if the segment [se,ss] is completely inside the answer segment [qs,qe], return the answer stored in the si index of the segment tree
		return st[si];
	}

	//if the segment [se,ss] is completely inside the answer segment [qs,qe], 
	// divide it into left and right child segments and call the query fucntion recursively to calculate the answer

	int mid = (ss + se) / 2; // find the mid of the segment
	pair<int,int> left, right, temp;
	left = query( 2 * si, ss, mid, qs, qe );
	right = query( 2 * si + 1, mid + 1, se, qs, qe);
	temp = {min(left.first, right.first), max(left.second, right.second)};
	return temp; // use the value of the left and right child to find the value of the required range
}


// the update function updates point updates
// qi  -> the index value where the value is to be updated to the value val
// val -> the new value
// si -> segment tree index
// ss -> segment starting index
// se -> segment ending index
// void update( int si, int ss, int se, int qi, int val) {
// 	if(ss == se) { // when we reach the index which needs to be updated 
// 		st[si] = val; // we update with the new value val
// 		return;
// 	}

// 	int mid = ( ss + se ) / 2; // finding the middle of the segment

// 	if(qi <= mid) // if qi is in the left segment update the left segment
// 		update( 2 * si, ss, mid, qi, val);
// 	else // if qi is in the left segment update the right segment segment
// 		update(2 * si + 1, mid + 1, se, qi, val); 
// 	st[si] = min(st[si*2],st[si*2+1]); // finally update the tree using the left and right segment values
// }


//implementation and calling details
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> arr[i];
	}
	build(1,1,n);
	int q;
	cin >> q;
	while(q--) {
		int l,r;
		cin >> l >> r;
		pair <int,int> left, middle, right;
		left = {0,0};
		right = {0,0};
		if(l != 0) {
			left = query(1,1,n,1,l);
		}
		if(r != n-1) {
			right = query(1,1,n,r+2,n);
		}
		middle = query(1,1,n,l+1,r+1);
		int fast = middle.first;
		double ans = max(left.second, right.second) + fast;
		ans = max(ans, (double) (middle.second - fast) / 2 + fast);
		cout << fixed << setprecision(1) << ans << '\n';
	}
}