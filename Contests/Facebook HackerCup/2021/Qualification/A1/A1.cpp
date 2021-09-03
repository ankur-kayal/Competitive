#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string S;
    cin >> S;

    string vowels = "AEIOU";

    int minimumSeconds = 1e9;

    for(char i = 'A'; i <= 'Z'; i++) {
        bool target_consonant = !count(vowels.begin(), vowels.end(), i);
        int ans = 0;
        for(auto u: S) {
            bool consonant = !count(vowels.begin(), vowels.end(), u);
            if(u != i) {
                if(target_consonant == consonant) {
                    ans += 2;
                } else {
                    ans++;
                }
            }
        }
        minimumSeconds = min(ans, minimumSeconds);
    }

    cout << minimumSeconds << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    /*For validation*/
    // freopen("a1_validation_input.txt", "r", stdin);
    // freopen("a1_validation_output.txt", "w", stdout);

    /*For final submit*/
    freopen("a1_final_input.txt", "r", stdin);
    freopen("a1_final_output.txt", "w", stdout);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        cout << "Case #" << test << ": "; 
        run_cases();
    }
}