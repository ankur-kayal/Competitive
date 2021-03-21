#include <bits/stdc++.h>
using namespace std;

map<int, pair<int,int>> rev_mapping;
map<pair<int,int>, int> mapping;

const int inf = 1e9 + 100;

void build_ranges(vector<pair<int,int>>& ranges) {
    int n = ranges.size();
    vector<int> start, end;
    for(int i=0;i<n;i++) {
        int l,r;
        tie(l, r) = ranges[i];
        start.push_back(l);
        end.push_back(r);
    }

    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    vector<pair<int,int>> non_overlap;
    int l = 0, r = 0;   
    int prevr = inf;
    while(l < n or r < n) {
        pair<int,int> range;
        range.first = min(l < n ? start[l] : inf, prevr + 1);
        if(start[l] == range.first) {
            l++;
        }
        range.second = min(end[r], l < n ? start[l] - 1 : inf);
        if(range.second == end[r]) {
            r++;
        }
        prevr = range.second;
        if(range.first <= range.second)
                non_overlap.push_back(range);
    }

    for(auto u: non_overlap) {
        rev_mapping[u.first] = u;
    }
}

vector<pair<int,int>> simplify(pair<int,int> a) {
    vector<pair<int,int>> child;
    int l = a.first, r = a.second;
    while(l <= r) {
        pair<int,int> range = rev_mapping[l];
        child.push_back(range);
        l = range.second + 1;
    }
    return child;
}
void run_cases() {
    mapping.clear();
    rev_mapping.clear();
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<vector<int>> adj = vector<vector<int>>(1);
    vector<pair<int,int>> range_left, range_right, ranges;
    int index = 1;
    int root = -1, dest = -1;
    for(int i=0;i<m;i++) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        range_left.emplace_back(a,b);
        range_right.emplace_back(c,d);
        ranges.emplace_back(a,b);
        ranges.emplace_back(c,d);
        
    }

    if(x == y) {
        cout << 0 << '\n';
        return;
    }

    build_ranges(ranges);

    for(int i=0;i<m;i++) {
        vector<pair<int,int>> left = simplify(range_left[i]);
        vector<pair<int,int>> right = simplify(range_right[i]);

        for(auto p1: left) {
            for(auto p2: right) {
                int u,v;
                if(mapping.count(p1)) {
                    u = mapping[p1];
                }
                else {
                    u = index;
                    index++;
                    mapping[p1] = u;
                    adj.push_back(vector<int>());
                }
                if(mapping.count(p2)) {
                    v = mapping[p2];
                }
                else {
                    v = index;
                    index++;
                    mapping[p2] = v;
                    adj.push_back(vector<int>());
                }
                if(p1.first <= x and x <= p1.second) {
                    root = u;
                }
                if(p2.first <= x and x <= p2.second) {
                    root = v;
                }
                if(p1.first <= y and y <= p1.second) {
                    dest = u;
                }
                if(p2.first <= y and y <= p2.second) {
                    dest = v;
                }
                adj[u].push_back(v);
            }
        }
    }
    return;


    if(dest == -1 or root == -1) {
        cout << -1 << '\n';
        return;
    }
    vector<int> dist(index + 2, -1);
    vector<int> vis(index + 2, 0);
    dist[root] = 0;
    vector<int> q;
    q.push_back(root);
    for(int i=0;i<q.size();i++) {
        int u = q[i];
        vis[u] = 1;
        for(auto v: adj[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                q.push_back(v);
                dist[v] = dist[u] + 1;
            }
        }

    }
    cout << dist[dest] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}