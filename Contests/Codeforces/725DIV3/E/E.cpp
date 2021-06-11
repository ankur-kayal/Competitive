#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int64_t count_haha(string s) {
    int64_t haha = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s.substr(i, 4) == "haha") {
            haha++;
        }
    }
    return haha;
}

struct variable {
    int64_t haha;
    string first, last;

    variable(string s = "") {
        haha = count_haha(s);
        first = s;
        last = s;
        trim();        
    }

    void trim() {
        while(first.length() > 3) {
            first.pop_back();
        }
        while(last.length() > 3) {
            last.erase(last.begin());
        }
    }
};


variable concat(variable a, variable b) {
    variable ans;
    ans.haha = a.haha + b.haha + count_haha(a.last + b.first);
    ans.first = a.first + b.first;
    ans.last = a.last + b.last;
    ans.trim();
    return ans;
}

void run_cases() {
    int N;
    cin >> N;
    map<string, variable> cache;

    string last_assigned = "";

    for(int i = 0; i < N; i++) {
        string name, type;
        cin >> name >> type;
        if(type == ":=") {
            string value;
            cin >> value;
            cache[name] = variable(value);
        } else {
            string v1, add, v2;
            cin >> v1 >> add >> v2;
            cache[name] = concat(cache[v1], cache[v2]);
        }
        last_assigned = name;
    }

    cout << cache[last_assigned].haha << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}