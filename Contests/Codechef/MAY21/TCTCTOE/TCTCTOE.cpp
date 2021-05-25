#include <bits/stdc++.h>
using namespace std;

/*
1: if the position is reachable, and the game has drawn or one of the players won.
2: if the position is reachable, and the game will continue for at least one more move.
3: if the position is not reachable.
*/

void run_cases() {
    vector<string> grid(3);
    for(auto &u: grid) {
        cin >> u;
    }
    // First check of validity
    int count_X = 0, count_O = 0, count_blanks = 0;
    for(auto u: grid) {
        for(auto v: u) {
            if(v == 'X') count_X++;
            if(v == 'O') count_O++;
            if(v == '_') count_blanks++;
        }
    }


    if(abs(count_X - count_O) <= 1 && count_O <= count_X) {

        int count_wins_X = 0, count_wins_O = 0;

        // row and column check
        for(int i=0;i<3;i++) {
            if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != '_') {
                if(grid[i][0] == 'X')
                    count_wins_X++;
                else
                    count_wins_O++;
            }
            if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != '_') {
                if(grid[0][i] == 'X')
                    count_wins_X++;
                else
                    count_wins_O++;
            }
        }

        // main diagonal check
        if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != '_') {
            if(grid[0][0] == 'X')
                count_wins_X++;
            else
                count_wins_O++;
        }

        // alternate main diagonal check
        if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[1][1] != '_') {
            if(grid[1][1] == 'X')
                count_wins_X++;
            else
                count_wins_O++;
        }

        count_wins_X = (count_wins_X + 1) / 2;
        count_wins_O = (count_wins_O + 1) / 2;

        int count_wins = count_wins_O + count_wins_X;

        if(count_wins == 0 && count_blanks > 0) {
            // There is not winner yet and the game can continue for atleast one more move
            cout << 2 << '\n';
            return;
        }
        if(count_wins > 1) {
            // there cannot be more than 2 winners
            cout << 3 << '\n';
            return;
        }

        // there is one winner, or the game is a draw
        if(count_wins_X == 1) {
            // X won
            if(count_X == count_O + 1) {
                cout << 1 << '\n';
            } else {
                // game cannot continue after winning
                cout << 3 << '\n';
            }
            return;
        } else if(count_wins_O == 1) {
            // O won
            if(count_X == count_O) {
                cout << 1 << '\n';
            } else {
                // game cannot continue after winning
                cout << 3 << '\n';
            }
            return;
        } else {
            // its a draw :(
            cout << 1 << '\n';
            return;

        }
    } else {
        // not reachable
        cout << 3 << '\n';
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}