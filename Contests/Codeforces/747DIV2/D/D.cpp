#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

void run_cases() {
    // imposter == 0, crewmate == 1

    int n, m;
    cin >> n >> m;

    vector<vector<int>> comments;

    vector<vector<pair<int,int>>> inwards(n + 1);
    vector<vector<pair<int,int>>> outwards(n + 1);

    vector<bool> marked(n + 1);
    vector<int> player_type(n + 1, -1); // -1 denotes unassigned

    bool possible = true;

    int imposters = 0;

    for(int i = 0; i < m; i++) {
        int u, v;
        string c;
        cin >> u >> v >> c;
        if(c == "imposter") {
            inwards[v].push_back({u, 0});
            outwards[u].push_back({v, 0});
        } else {
            inwards[v].push_back({u, 1});
            outwards[u].push_back({v, 1});
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!possible) {
            break;
        }
        if(player_type[i] == -1) {
            vector<int> q = {i};
            int current_imposters = 0, current_crewmates = 0;
            player_type[i] = 0;
            for(int j = 0; j < q.size(); j++) {
                if(!possible) {
                    break;
                }
                int x = q[j];
                if(player_type[x] == 0) {
                    current_imposters++;
                } 
                else {
                    current_crewmates++;
                }
                for(auto [node, w]: inwards[x]) {
                    if(w == 0) {
                        // x is an imposter and node tells x is an imposter, node is crewmate
                        if(player_type[x] == 0) {
                            if(player_type[node] == -1) {
                                player_type[node] = 1;
                                q.push_back(node);
                            } 
                            else {
                                if(player_type[node] == 0) {
                                    possible = false;
                                    break;
                                }
                            }
                        } 
                        else {
                            // x is a crewmate and node tells x is an imposter, node is imposter
                            if(player_type[node] == -1) {
                                player_type[node] = 0;
                                q.push_back(node);
                            } 
                            else {
                                if(player_type[node] == 1) {
                                    possible = false;
                                    break;
                                }
                            }
                        }
                    } else {
                        // x is imposter, but node tells x is crewmate
                        if(player_type[x] == 0) {
                            if(player_type[node] == -1) {
                                player_type[node] = 0;
                                q.push_back(node);
                            } else {
                                if(player_type[node] == 1) {
                                    possible = false;
                                    break;
                                }
                            }
                        } else {
                            // x is crewmate, but node tells x is crewmate
                            if(player_type[node] == -1) {
                                player_type[node] = 1;
                                q.push_back(node);
                            } else {
                                if(player_type[node] == 0) {
                                    possible = false;
                                    break;
                                }
                            }
                        }
                    }
                }


                for(auto [node, w]: outwards[x]) {
                    if(w == 0) {
                        if(player_type[x] == 0) {
                            // x is an imposter, and x tells node is an imposter, so node is crewmate
                            if(player_type[node] == -1) {
                                player_type[node] = 1;
                                q.push_back(node);
                            } 
                            else {
                                if(player_type[node] == 0) {
                                    possible = false;
                                    break;
                                }
                            }
                        }
                        else {
                            // x is a crewmate and x tells node is an imposter, so node is an imposter

                            if(player_type[node] == -1) {
                                player_type[node] = 0;
                                q.push_back(node);
                            } else {
                                if(player_type[node] == 1) {
                                    possible = false;
                                    break;
                                }
                            }
                        }
                    }
                    else {
                        if(player_type[x] == 0) {
                            // x is an imposter and x tells node is an crewmate, node is imposter
                            if(player_type[node] == -1) {
                                player_type[node] = 0;
                                q.push_back(node);
                            } else {
                                if(player_type[node] == 1) {
                                    possible = false;
                                    break;
                                }
                            }
                        }
                        else {
                            // x is an crewmate and x tells node is an crewmate, so node is an crewmate
                            if(player_type[node] == -1) {
                                player_type[node] = 1;
                                q.push_back(node);
                            } else {
                                if(player_type[node] == 0) {
                                    possible = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }

            imposters += max(current_imposters, current_crewmates);
        }
    }

    if(possible) {
        cout << imposters << '\n';
    } else {
        cout << -1 << '\n';
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