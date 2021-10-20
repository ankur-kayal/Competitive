#include <bits/stdc++.h>
#include <locale>
using namespace std;

#define nl '\n'


void run_cases() {
    int N;
    cin >> N;

    int R, C, K;

    cin >> R >> C >> K;

    vector<vector<char>> original(R, vector<char>(C));

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> original[i][j];
        }
    }

    vector<vector<int>> columns(C);
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(original[i][j] == 'X') {
                columns[j].push_back(i);
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < C; i++) {
        if(original[K - 1][i] == 'X') {
            ans++;
        }
    }


    // move up, calculate total moves and take maximum for each column

    int up = 0;
    int waste = 0;

    for(int col = 0; col < C; col++) {
        int total = columns[col].size() - 1;

        up = max(columns[col].back() - total, up);
        if(total + 1 == K) {
            waste++;
        }
    }

    ans = min(ans, up + waste);



}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("b_validation_input.txt", "r", stdin);
    // freopen("b_validation_output.txt", "w", stdout);

    /*For final submit*/
    freopen("c1_final_input.txt", "r", stdin);
    freopen("c1_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}