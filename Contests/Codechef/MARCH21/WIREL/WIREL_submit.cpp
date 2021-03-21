#include <bits/stdc++.h>
#include <ios>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

const int maxN = 1e6;

pair<int,int> calculate_shift(pair<int,int> a, pair<int,int> b) {
    return {a.first - b.first, a.second - b.second};
}
void run_cases() {
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> cities;
    for(int i=0;i<n;i++) {
        int x,y;
        cin >> x >> y;
        cities.emplace_back(x,y);
    }
    vector<pair<pair<int,int>, pair<int,int>>> wires;
    for(int i=0;i<m;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(make_pair(a,b) > make_pair(c,d)) {
            swap(a,c);
            swap(b,d);
        }
        wires.push_back(make_pair(make_pair(a,b), make_pair(c,d)));
    }

    pair<int,int> pos = {-1, 0};
    pair<int,int> neg = {maxN + 1, maxN};

    vector<int> used(n, 0);
    set<int> not_used;
    int left = m;
    for(int i=0;i<m;i++) {
        not_used.insert(i);
    }

    int prob;
    bool weighted = false;
    bool nega = false, posi = false;
    vector<pair<int,int>> ans(n);
    bool one_neg = false, one_pos = false;
    while(left) {
        int index = uid(0, m - 1);
        while(used[index]) {
            index = uid(0, m - 1);
        }
        if(!weighted){
            prob = uid(1, 100);
            if(prob < uid(1,100)) {
                nega = false;
            }
            else {
                nega = true;
            }
        } else {
            weighted = false;
        }

        if(not_used.size() == 1 and !one_neg) {
            nega = true;
        }
        if(not_used.size() == 1 and !one_pos) {
            nega = false;
        }

        if(!nega) {
            nega = false;
            ans[index] = calculate_shift(pos, wires[index].first);
            int hi, vi;
            tie(hi, vi) = ans[index];
            if(abs(hi) > maxN or abs(vi) > maxN) {
                nega = true;
                weighted = true;
                ans[index] = {0 , 0};
                continue;
            }
            one_pos = true;
            pos = wires[index].second;
            pos.first += ans[index].first;
            pos.second += ans[index].second;
   
            pos = wires[index].second;
            // pos = wires[index].second;
        }
        else {
            nega = false;
            ans[index] = calculate_shift(neg, wires[index].second);
            int hi, vi;
            tie(hi, vi) = ans[index];
            if(abs(hi) > maxN or abs(vi) > maxN) {
                posi = true;
                weighted = true;
                ans[index] = {0 , 0};
                continue;
            }
            one_neg = true;
            neg = wires[index].first;
            neg.first += ans[index].first;
            neg.second += ans[index].second;
            // neg = wires[index].first;
        }
        cerr << "index = [ " << index << " ]" << '\n';
        // not_used.erase(index);
        left--;
        // if(not_used.size() < 9000) break;
        // if(one_neg and one_pos) break;
        used[index] = 1;

    }
    for(int i=0;i<m;i++) {
        cout << ans[i].first << " " << ans[i].second << '\n';
    }
    cerr << boolalpha << one_neg << " " << one_pos << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}