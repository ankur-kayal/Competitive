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

struct Role {
    string name;
    int skillLevel;

    void read() {
        cin >> name >> skillLevel;
    }
};

struct Contributor {
    string name;
    int numberOfSkills;
    vector<Role> roles;

    void read() {
        cin >> name >> numberOfSkills;
        for(int i = 0; i < numberOfSkills; i++) {
            Role tmp;
            tmp.read();
            roles.push_back(tmp);
        }
    }
};

struct Project {
    string name;
    int completionDays;
    int64_t score;
    int lastDay;
    int roleCount;
    vector<Role> roles;
    vector<string> contributors;

    void read() {
        cin >> name >> completionDays >> score >> lastDay >> roleCount;

        for(int i = 0; i < roleCount; i++) {
            Role tmp;
            tmp.read();
            roles.push_back(tmp);
        }
    }
};

struct Answer {
    vector<Project> projects;

    void write() {
        cout << projects.size() << '\n';
        for(auto u: projects) {
            cout << u.name << '\n';
            for(auto name: u.contributors) {
                cout << name << " ";
            }
            cout << '\n';
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);


    map<string, set<pair<int, string>>> skillBucket;
    map<string, vector<pair<string, int>>> contributorSkillMapping;

    vector<Contributor> contributors;
    vector<Project> projects;

    int numberOfContributors;
    cin >> numberOfContributors;
    int numberOfProjects;
    cin >> numberOfProjects;

    for(int i = 0; i < numberOfContributors; i++) {
        Contributor tmp;
        tmp.read();
        for(auto role: tmp.roles) {
            skillBucket[role.name].insert({role.skillLevel, tmp.name});
            contributorSkillMapping[tmp.name].push_back({role.name, role.skillLevel});
        }
    }

    for(int i = 0; i < numberOfProjects; i++) {
        Project tmp;
        tmp.read();
        projects.push_back(tmp);
    }


    sort(projects.begin(), projects.end(), [&](Project &project1, Project &project2) {
        return project1.score < project2.score;
    });

    Answer answer;

    int cutoff = 50;

    vector<Projects

    while(projects.size() > 0) {
        cutoff--;
        if(cutoff < 0) {
            break;
        }

        for(int i = 0; i < projects.size(); i++) {
            Project contributedProject = projects[i];
            bool fulfilled = true;

            for(Role role: contributedProject.roles) {
                bool contributorFound = false;
                vector<string> usedContributors;
                for(auto [skill, contributorName]: skillBucket[role.name]) {
                    if(skill >= role.skillLevel) {
                        contributorFound = true;
                        usedContributors.push_back(contributorName);
                        contributedProject.contributors.push_back(contributorName);
                        for(auto [skillName, skill]: contributorSkillMapping[contributorName]) {
                            skillBucket[skillName].erase({skill, contributorName});
                        }
                        break;
                    }
                }
                if(!contributorFound) {
                    fulfilled = false;
                    for(auto contributor: usedContributors) {
                        for(auto [skillName, skill]: contributorSkillMapping[contributor]) {
                            skillBucket[skillName].insert({skill, skillName});
                        }
                    }
                    break;
                }   
            }
            if(fulfilled) {
                answer.projects.push_back(contributedProject);
            }
        }
    }

    

    answer.write();

}