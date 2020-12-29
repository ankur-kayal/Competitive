#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r+", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w+", stdout);
#endif

    int n,m;
    cin >> n >> m;
    map <string,string> country;
    for(int i=0;i<n;i++) {
    	string c,name;
    	cin >> name  >> c;
    	country[name] = c;
    }
    map <string,int> num;
    map <string,int> wc;
    for(int i=0;i<m;i++) {
    	string name;
    	cin >> name;
    	num[name]++;
    	wc[country[name]]++;
    }
    int maxV = 0;
    string winner;
    string cont;
    for(auto u: num) {
    	string name = u.first;
    	int votes = u.second;
    	if(maxV == 0) {
    		winner = name;
    		maxV = votes;
    	}
    	else {
    		if(votes > maxV) {
    			winner = name;
    			maxV = votes;
    		}
    		if(votes == maxV and name < winner) {
    			winner = name;
    		}
    	}
    }
    maxV = 0;
    for(auto u: wc) {
    	string name = u.first;
    	int votes = u.second;
    	if(maxV == 0) {
    		cont = name;
    		maxV = votes;
    	}
    	else {
    		if(votes > maxV) {
    			cont = name;
    			maxV = votes;
    		}
    		if(votes == maxV and name < cont) {
    			cont = name;
    		}
    	}
    }
    cout << cont << "\n" << winner << '\n';
}