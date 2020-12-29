#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<int> sums(7);
    for(int i=0;i<7;i++) {
        cin >> sums[i];
    }
    vector<int> indices = {0,1,2,3,4,5,6};
    do {
        int a = sums[indices[0]];
        int b = sums[indices[1]];
        int c = sums[indices[2]];

        if(a <= b and b <= c) {
            if(a + b == sums[indices[3]] and b + c == sums[indices[4]] and c + a == sums[indices[5]] and a + b + c == sums[indices[6]]) {
                cout << a << " " << b << " " << c;
                exit(0);
            }
        }
    }while(next_permutation(indices.begin(), indices.end())); 
}