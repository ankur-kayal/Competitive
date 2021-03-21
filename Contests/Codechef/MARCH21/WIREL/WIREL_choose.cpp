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

    vector<pair<int,int>> posend, negend;
    posend={{-1, 0}, {0, -1}};
    negend = {{maxN + 1, maxN}, {maxN, maxN + 1}};

    vector<int> used(n, 0);
    set<int> not_used;
    int left = m;
    // for(int i=0;i<m;i++) {
    //     not_used.insert(i);
    // }

    int prob;
    bool weighted = false;
    bool nega = false, posi = false;
    vector<pair<int,int>> ans(n);
    bool one_neg = false, one_pos = false;
    int over = 0;
    while(left) {
        if(over > 10000) {
            // shuffle(posend.begin(), posend.end(), rng);
            posend.pop_back();
            pos = posend.back();
            // shuffle(negend.begin(), negend.end(), rng);
            negend.pop_back();
            neg = negend.back();
            // break;
        }
        int index;
        int prob = uid(1, 100);
        // cerr << prob;
        if(prob < 50) {
            one_pos = true;
            int64_t best_score = 1e18;
            pair<int,int> best_answer;
            
            for(int i=0;i<m;i++) {
                if(used[i]) {
                    continue;
                }
                pair<int64_t,int64_t> tmp = calculate_shift(pos, wires[i].first);
                int64_t score = tmp.first * tmp.first + tmp.second * tmp.second;
                
                if(score < best_score) {
                    best_score = score;
                    best_answer = tmp;
                    index = i;
                }

            }
            ans[index] = best_answer;
            // debug() << imie(best_answer) imie(index);
            int hi, vi;
            tie(hi, vi) = ans[index];
            if(abs(hi) > maxN or abs(vi) > maxN) {
                over++;
                nega = true;
                weighted = true;
                ans[index] = {0 , 0};
                continue;
            }
            pos = wires[index].second;
            pos.first += ans[index].first;
            pos.second += ans[index].second;
            posend.push_back(pos);
        }
        else {
            one_neg = true;
            int64_t best_score = 1e18;
            pair<int,int> best_answer;

            for(int i=0;i<m;i++) {
                if(used[i]) {
                    continue;
                }
                pair<int64_t,int64_t> tmp = calculate_shift(neg, wires[i].second);
                int64_t score = tmp.first * tmp.first + tmp.second * tmp.second;
                if(score < best_score) {
                    best_score = score;
                    best_answer = tmp;
                    index = i;
                }

            }
            ans[index] = best_answer;
            // debug() << imie(best_answer) imie(index);
            int hi, vi;
            tie(hi, vi) = ans[index];
            if(abs(hi) > maxN or abs(vi) > maxN) {
                over++;
                nega = true;
                weighted = true;
                ans[index] = {0 , 0};
                continue;
            }
            neg = wires[index].first;
            neg.first += ans[index].first;
            neg.second += ans[index].second;
            negend.push_back(neg);
        }

        cerr << "index = [ " << index << " ]" << '\n';
        left--;
        // if(not_used.size() < 9000) break;
        // if(one_neg and one_pos) break;
        used[index] = 1;
        cerr << "left = [ " << left << " ]" << '\n';

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