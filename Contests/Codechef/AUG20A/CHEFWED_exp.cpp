#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ar array
#define ff first
#define ss second

int k;

int calculateScore(map<int,int>& table1, map<int,int>& table2) {
	ll initialScore = k + k;
	ll finalScore = k;
	map <int,int> table3;
	for(auto u: table1) {
		table3[u.ff] += u.ss;
		if(u.ss > 1) {
			initialScore += u.ss;
		}
	}
	for(auto u: table2) {
		table3[u.ff] += u.ss;
		if(u.ss > 1) {
			initialScore += u.ss;
		}
	}

	for(auto u: table3) {
		if(u.ss > 1) {
			finalScore += u.ss;
		}
	}
	if(finalScore <= initialScore) {
		return finalScore;
	}
	return -1;
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
    	// cout << "\nTest Case 1" << '\n';
    	int n;
    	cin >> n >> k;
    // 	assert(n * k < 100000);
    	int f[n];
    	for(int i=0;i<n;i++) {
    		cin >> f[i];
    	}

    	// divide into the maximum number of tables so that no conflicts occur
    	vector <map<int,int>> tables, tables_rev;
    	map <int,int> cnt;
            // vector <int> tables;
		for(int i=0;i<n;i++) {
			cnt[f[i]]++;
			if(cnt[f[i]] > 1) {
				cnt[f[i]]--;
				tables.pb(cnt);
				cnt.clear();
                cnt[f[i]]++;
			}
		}
		tables.pb(cnt);
		for(auto u: tables) {
			tables_rev.pb(u);
		}
		reverse(tables_rev.begin(),tables_rev.end());
		// for(int i=0;i<tables.size();i++) {
		// 	cout << "table " << i + 1 << '\n';
		// 	for(auto v : tables[i]) {
		// 		cout << v.ff << " " << v.ss << '\n';
		// 	}
		// }

		// merge tables so that the overall cost decreases
		int rot = 0;
		while(true) {
			rot++;
			int index1 = -1, index2 = -1;
			int minScore = 100000000;
			for(int i=0;i<tables.size() - 1;i++) {
				map <int,int> table1 = tables[i];
				map <int,int> table2 = tables[i+1];
				int score = calculateScore (table1, table2);
				if(score == -1) {
					continue;
				}
				if(score < minScore) {
					minScore = score;
					index1 = i;
					index2 = i + 1;
				}
			}
			if(index1 == -1 and index2 == -1) {
				break;
			}
			else {
				vector <map<int,int>> tempTables;
				for(int i=0;i<index1;i++) {
					tempTables.pb(tables[i]);
				}
				map <int,int> table3;
				for(auto u: tables[index1]) {
					table3[u.ff] += u.ss;
				}
				for(auto u: tables[index2]) {
					table3[u.ff] += u.ss;
				}
				tempTables.pb(table3);
				for(int i=index2 + 1;i<tables.size();i++) {
					tempTables.pb(tables[i]);
				}
				tables.clear();
				for(auto u: tempTables) {
					tables.pb(u);
				}

			}
			// if(rot > 500) {
			// 	break;
			// }
		}
		while(true) {
			rot++;
			int index1 = -1, index2 = -1;
			int minScore = 100000000;
			for(int i=0;i<tables_rev.size() - 1;i++) {
				map <int,int> table1 = tables_rev[i];
				map <int,int> table2 = tables_rev[i+1];
				int score = calculateScore (table1, table2);
				if(score == -1) {
					continue;
				}
				if(score <= minScore) {
					minScore = score;
					index1 = i;
					index2 = i + 1;
				}
			}
			if(index1 == -1 and index2 == -1) {
				break;
			}
			else {
				vector <map<int,int>> tempTables;
				for(int i=0;i<index1;i++) {
					tempTables.pb(tables_rev[i]);
				}
				map <int,int> table3;
				for(auto u: tables_rev[index1]) {
					table3[u.ff] += u.ss;
				}
				for(auto u: tables_rev[index2]) {
					table3[u.ff] += u.ss;
				}
				tempTables.pb(table3);
				for(int i=index2 + 1;i<tables_rev.size();i++) {
					tempTables.pb(tables_rev[i]);
				}
				tables_rev.clear();
				for(auto u: tempTables) {
					tables_rev.pb(u);
				}

			}
			// if(rot > 500) {
			// 	break;
			// }
		}
		// for(int i=0;i<tables.size();i++) {
		// 	cout << "table " << i + 1 << '\n';
		// 	for(auto v : tables[i]) {
		// 		cout << v.ff << " " << v.ss << '\n';
		// 	}
		// }

		// calculate the score from the final table arrangement
		ll ans1 = 0 ,ans2 = 0;
		for(auto u: tables) {
			ans1+=k;
			for(auto v : u) {
				if(v.ss > 1) {
					ans1 += v.ss;
				}
			}
		}
		for(auto u: tables_rev) {
			ans2+=k;
			for(auto v : u) {
				if(v.ss > 1) {
					ans2 += v.ss;
				}
			}
		}
		cout << min(ans1,ans2) << '\n';
    }
}