#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

/*
Strategies:
for each k find the following:
1. number of values in place
2. number of values out of place

Edge Case: 1 2 3

1 5 4 3 2

*/

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void run_cases() {
    int N, M;
    cin >> N >> M;
    vector<int> P(N);
    for(auto &u: P) 
        cin >> u;
    for(auto &u: P) 
        --u;
    vector<int> in_position(N);
    for(int i = 0; i < N; i++) {
        int original_position = P[i];
        int current_position = i;
        if(current_position >= original_position) {
            in_position[current_position - original_position]++;
        } else {
            in_position[current_position + N - original_position]++;
        }
    }

    vector<int> position(N);
    for(int i = 0; i < N; i++) {
        position[P[i]] = i;
    }
    

    vector<int> K;

    for(int i = 0; i < N; i++) {
        if(in_position[i] >= N / 3) {
            // brute force swaps needed
            int swaps = 0;
            vector<int> rotated(N);
            iota(rotated.begin(), rotated.end(), 0);
            rotate(rotated.begin(), rotated.begin() + N - i, rotated.end());            
            vector<bool> used(N + 1, false);
            for(int j = 0; j < N; j++) {
                if(!used[rotated[j]]) {
                    int group_size = 0;
                    int val = rotated[j];
                    used[val] = true;
                    while(j != position[val]) {
                        val = rotated[position[val]];
                        used[val] = true;
                        group_size++;
                    }
                    swaps += group_size;
                }
            }
            if(swaps <= M) {
                K.push_back(i);
            }
        }
    }

    cout << K.size() << " ";
    output_vector(K);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}