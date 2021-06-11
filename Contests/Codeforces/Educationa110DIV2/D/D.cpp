#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int N = (1 << (k + 1)) - 1;
    vector<int64_t> winners(N);
    vector<int> map_index(N);
    vector<int> rev_map(N);
    vector<vector<int>> levels(k);
    int lvl = 0;
    int max_num = 1;
    for(int i = 0; i < (1 << k) - 1; i++) {
        levels[lvl].push_back(i);
        if(levels[lvl].size() == max_num) {
            lvl++;
            max_num *= 2;
        }
    }
    lvl--;
    int rev = 0;
    int ind = 0;
    for(int i = lvl; i >= 0; i--) {
        for(auto u: levels[i]) {
            map_index[u] = ind;
            rev_map[ind] = u;
            ind++;
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < N && right < N) {
            if(s[map_index[i]] == '?') {
                winners[i] = winners[left] + winners[right];
            } else if(s[map_index[i]] == '0') {
                winners[i] = winners[left];
            } else {
                winners[i] = winners[right];
            }
        } else {
            winners[i] = 1;
        }
    }


    int Q;
    cin >> Q;
    while(Q--) {
        int index;
        char ch;
        cin >> index >> ch;
        index--;
        s[index] = ch;
        index = rev_map[index];
        while(true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            if(s[map_index[index]] == '?') {
                winners[index] = winners[left] + winners[right];
            } else if(s[map_index[index]] == '0') {
                winners[index] = winners[left];
            } else {
                winners[index] = winners[right];
            }
            if(index == 0) {
                break;
            }
            index = (index - 1) / 2;
        }

        cout << winners[0] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}