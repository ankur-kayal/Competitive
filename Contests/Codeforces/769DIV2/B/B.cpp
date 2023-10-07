#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

/*
4 : 0100
6 : 0110
3 : 0011
2 : 0010
0 : 0000
8 : 1000
9 : 1001
1 : 0001
7 : 0111
5 : 0101
*/


template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


void run_cases() {
    int N;
    cin >> N;

    int highest_bit_set = 0;
    for(int i = 30; i >= 0; i--) {
        if((N - 1) >> i & 1) {
            highest_bit_set = i;
            break;
        }
    }

    vector<int> answer;
    vector<bool> vis(N);
    answer.push_back(N - 1);
    for(int i = 0; i < N - 1; i++) {
        if(i >> highest_bit_set & 1) {
            answer.push_back(i);
            vis[i] = true;
        }
    }
    int mirror = (N - 1) ^ (1 << highest_bit_set);

    reverse(answer.begin(), answer.end());
    if(!vis[mirror]) {
        answer.push_back(mirror);
        vis[mirror] = true;
    }

    for(int i = 0; i < N - 1; i++) {
        if(!vis[i]) {
            answer.push_back(i);
        }
    }

    output_vector(answer);

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}