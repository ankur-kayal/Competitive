#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    int n;
    cin >> n;
    vector <int> count(100001),s(n);
    set <pair<int,int>> freq;
    for(int i=0;i<n;i++) {
    	cin >> s[i];
    }
    map <int,int> cnt;
    for(int i=0;i<n;i++) {
    	count[s[i]]++;
    }
    for(int i=1;i<=100000;i++) {
    	if(count[i] > 0) {
    		freq.insert(mp(count[i],i));
    	}
    }
    int q;
    cin >> q;
    while(q--) {
    	char ch; int x;
    	cin >> ch >> x;
    	if(ch == '+') {
    		if(count[x] > 0) {
    			freq.erase(mp(count[x],x));
    		}
    		count[x]++;
    		freq.insert(mp(count[x],x));
    	}
    	else {
    		freq.erase(mp(count[x],x));
    		count[x]--;
    		if(count[x] > 0) {
    			freq.insert(mp(count[x],x));
    		}
    	}
    	set<pair<int,int>>::reverse_iterator rit;
    	int square = 0, rect = 0;
    	bool exists = false;
    	for(rit = freq.rbegin();rit!=freq.rend();rit++) {
    		pair <int,int> ele = *rit;
    		if(ele.ff > 4) {
    			square++;
    			if(ele.ff - 4 >= 4) {
    				square++;
    			}
    			else if(ele.ff - 4 >= 2) {
    				rect++;
    			} 
    		}
    		else if(ele.ff == 4) {
    			if(square == 0) {
    				square++;
    			}
    			else {
    				rect+=2;
    			}
    		}
    		else if(ele.ff >= 2) {
    			rect++;
    		}
    		if(square >= 2) {
    			exists = true;
    			break;
    		}
    		else if(square == 1 and rect >= 2) {
    			exists = true;
    			break;
    		}
    		else if(ele.ff < 4 and square == 0) {
    			break;
    		}
    		else if(ele.ff < 2) {
    			break;
    		}

    	}
    	// cout << square << " " << rect << '\n';
    	cout << (exists ? "YES" : "NO") << '\n';
    }

}