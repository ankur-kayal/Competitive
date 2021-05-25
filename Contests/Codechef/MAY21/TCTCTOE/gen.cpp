#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

vector<vector<string>> combinations;

vector<string> grid(3, "***");

void generate_tic_tac_toe() {
    // find an empty box, * represents empty
    int row = -1, col = -1;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(grid[i][j] == '*') {
                row = i, col = j;
                goto found_empty;
            }
        }
    }

    assert(row == -1 && col == -1);
    combinations.push_back(grid);
    return;

    found_empty:

    assert(grid[row][col] == '*');

    vector<char> vals{'_', 'X', 'O'};
    for(auto u: vals) {
        grid[row][col] = u;
        generate_tic_tac_toe();
        grid[row][col] = '*';
    }
}

void run_cases() {
    generate_tic_tac_toe();
    cout << combinations.size() << '\n';
    for(auto u: combinations) {
        for(auto v: u) {
            cout << v<< '\n';
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}