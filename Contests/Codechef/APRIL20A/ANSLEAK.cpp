#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int score[500][5000], cheat[500][5000];
int n,k,m;
int req[500][500];
int minm[500];


void calculate(int index) {
    int mnm = 100000000;
    vector <int> indexes;
    unordered_map <int,int> count;
    int cheatD[n][k];
    for(int i=0;i<n;i++) {
        for(int j=0;j<k;j++) {
            score[i][j] = 0;
            cheatD[i][j] = cheat[i][j];
        }
    }
    for(int i=0;i<k;i++) {
        swap(cheatD[0][i],cheatD[index][i]);
    }
    // int req[n];
    req[index][0] = cheatD[0][0];
    for(int i=0;i<k;i++) {
        score[0][i] = (cheatD[0][i] == cheatD[0][0]);
    }
    for(int i=1;i<n;i++) {
        mnm = 100000000;
        indexes.clear();
        count.clear();
        for(int j=0;j<k;j++) {
            mnm = min(mnm,score[i-1][j]);
        }
        // cout << "i -> " << i << '\n';
        // // finding the minimum score
        // for(int l=0;l<n;l++) {
        //     for(int j=0;j<k;j++) {
        //         // score[i][j] = 0;
        //         cout << score[l][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << i << " " << mnm << '\n';
        // finding the indexes with the minimum score
        for(int j=0;j<k;j++) {
            if(score[i-1][j] == mnm) {
                indexes.push_back(j);
                count[cheatD[i][j]]++;
            }
        }
        // finding the answer among the minimum score indexes and finding the maximum frequency of them
        int maxC = 0;
        int correct = 0;
        for(auto u: count) {
            if(u.second > maxC) {
                maxC = u.second;
                correct = u.first;
            }
        }
        // updating the score
        for(int j=0;j<k;j++) {
            if(cheatD[i][j] == correct) {
                score[i][j] = score[i-1][j] + 1;
                // cout << "HI" << score[i][j] <<'\n';

            }
            else {
                score[i][j] = score[i-1][j];
            }
        }
        req[index][i] = correct;
        
    }
    minm[index] = 1000000;
    for(int i=0;i<k;i++) {
        minm[index] = min(minm[index],score[n-1][i]);
    }
    swap(req[index][index],req[index][0]);
    // cout << "index -> " << index << '\n';
    // for(int i=0;i<n;i++) {
    //     cout << minm[i] << " " ;
    // }
    // cout << '\n';
    // cout << "score -> " << '\n';
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<k;j++) {
    //         cout << score[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
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
        clock_t start = clock();
        // int n,m,k;
        cin >> n >> m >> k;
        // int score[n][k], cheat[n][k];
        // int ans[n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                score[i][j] = 0;
                cin >> cheat[i][j];
            }
        }
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<k;j++) {
        //         // score[i][j] = 0;
        //         cout << cheat[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        int index = 0;
        for(;index<n;index++) {
            calculate(index);
            double time = (double)(clock() - start) / CLOCKS_PER_SEC;
            if(time > 0.80) {
                break;
            }
        }
        int ind;
        int minM = -1;
        
        for(int i=0;i<index;i++) {
            if(minm[i] > minM) {
                ind = i;
                minM = minm[i];
            }
        }
        // cout << ind << '\n';
        for(int i=0;i<n;i++) {
            cout << req[ind][i] << " ";
        }
        cout << '\n';
    }
}