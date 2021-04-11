#include<bits/stdc++.h>
using namespace std;

//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------


#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define all(x) (x).begin(), (x).end()

bool f;
vector<vector<int> >vec;

void Arr(vector<int> arr, int n){
    vec.push_back(arr);
}

int reversort(vector<int> arr, int n){
	int ans = 0;
	for(int i=0; i<n-1; ++i){
		int index = i;
		for(int j=i+1; j<n; ++j){
			if(arr[j] < arr[index]){
				index = j;
			}
		}
		for(int x = 0; x<(index - i + 1)/2; ++x){
			swap(arr[i+x], arr[index-x]);
		}
		ans += index-i+1;
	}
	return ans;
}

void Permutation(vector<int> arr, int size, int n){
    if (size == 1) {
        Arr(arr, n);
        return;
    }
 
    for (int i = 0; i < size; i++) {
        Permutation(arr, size - 1, n);
 
        if (size % 2 == 1)
            swap(arr[0], arr[size - 1]);
 
        else
            swap(arr[i], arr[size - 1]);
    }
}

int main(){
    FAST;
    int tests;
    cin >> tests;
    for(int tt=1; tt<=tests; ++tt){
        cout << "Case #" << tt << ": ";
        f = false;
        int n, c;
        cin >> n >> c;
        
    	vector<int>temp(n);
        for(int i=0; i<n; ++i){
        	temp[i] = i+1;
        }
        Permutation(temp, n, n);
        for(auto u: vec) {
            // debug() << imie(u);
        }
        int sz = vec.size();
        for(int i=0; i<sz; ++i){
        	if(c == reversort(vec[i], n)){
        		for(int j=0; j<n; ++j){
        			cout << vec[i][j] << " ";
        		}
        		f = true;
        		break;
        	}
        }
        if(!f){
        	cout << "IMPOSSIBLE";
        }
        vec.clear();
        
        cout << "\n";
    }
    return 0;
}