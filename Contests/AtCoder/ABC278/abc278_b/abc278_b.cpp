#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

bool valid(int h, int m) {
	int top_left, top_right, bottom_left, bottom_right;
	top_left = h / 10;
	bottom_left = h % 10;

	top_right = m / 10;
	bottom_right = m % 10;

	swap(top_right, bottom_left);

	int nh = top_left * 10 + bottom_left;
	int nm = top_right * 10 + bottom_right;

	if (0 <= nh && nh <= 23 && 0 <= nm && nm <= 59) {
		return true;
	} 
	return false;
}

void run_cases() {
	int H, M;
	cin >> H >> M;

	vector<pair<int,int>> times;

	for(int h = 0; h <= 23; h++) {
		for(int m = 0; m <= 59; m++) {
			if (valid(h, m)) {
				times.push_back({h, m});
			}
		}
	}


	for(int i = 0; i < times.size(); i++) {
		if(times[i] >= make_pair(H, M)) {
			cout << times[i].first << " " << times[i].second << '\n';
			return;
		}
	}

	cout << times[0].first << " " << times[0].second << '\n';


}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}