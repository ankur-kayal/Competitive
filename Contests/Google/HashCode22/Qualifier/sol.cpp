#include "testlib.h"
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

#define nl '\n'
#define all(x) x.begin(), x.end()
#define ll int64_t
#define deb(x) cout<<#x<<"="<<x<<endl
#define deb2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl



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
    int64_t numberOfSkills,daysWorked=0;
    vector<Role> roles;

    void read() {
        cin >> name >> numberOfSkills;
        for(int i = 0 ; i < numberOfSkills; i++) {
            Role tmp;
            tmp.read();
            roles.push_back(tmp);
        }
    }
    int findSkill(string roleName){
        for(int i=0;i<roles.size();i++){
            if(roles[i].name==roleName){
                return roles[i].skillLevel;
            }
        }
        return 0;
    }
};


struct Project {
    string name;
    int64_t completionDays;
    int64_t score;
    int64_t lastDay;
    int64_t roleCount;
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
    int64_t score = 0;

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
int no_of_contributors,no_of_projects;
ll score=0;
bool comp(Project p1, Project p2){
    int sz1,sz2;
    sz1 = p1.score;
    sz2 = p2.score;
    return sz1>=sz2;
}
int main(int argc, char*argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    registerGen(argc, argv, 1);

    cin>>no_of_contributors>>no_of_projects;
    vector<Contributor> originalContributors(no_of_contributors);
    for(int i=0;i<no_of_contributors;i++){
        originalContributors[i].read();
    }

    vector<Project> originalProjects(no_of_projects);
    for(int i=0;i<no_of_projects;i++){
        originalProjects[i].read();
    }

    Answer bestAnswer;

    int iterations = 50;

    while(true) {

        iterations--;
        if(iterations < 0) {
            break;
        }

        vector<Contributor> contributors = originalContributors;
        vector<Project> projects = originalProjects;

        shuffle(projects.begin(), projects.end());
        shuffle(contributors.begin(), contributors.end());

        Answer answer;
        int64_t score = 0;
        for(int i=0;i<no_of_projects;i++){
            set<int> conts;
            vector<string> name;
            for(Role role : projects[i].roles){
                for(int j=0;j<no_of_contributors;j++){
                    if(contributors[j].findSkill(role.name)>=role.skillLevel && contributors[j].daysWorked+projects[i].completionDays <  projects[i].lastDay + projects[i].score / 0.38 && conts.find(j)==conts.end()){
                        conts.insert(j);
                        name.push_back(contributors[j].name);
                        break;
                    }
                }
            }
            
            if(conts.size()== projects[i].roles.size()){
                ll max_day=0,minus;
                for(auto it : conts){
                    contributors[it].daysWorked += projects[i].completionDays ;
                    max_day = max(1LL*max_day,1LL*contributors[it].daysWorked);
                }
                minus=max(max_day-projects[i].lastDay,int64_t(0));
                score += projects[i].score-min(minus,projects[i].score);
                projects[i].contributors = name;
                answer.projects.push_back(projects[i]);
            }
        }



        if(score > bestAnswer.score) {
            bestAnswer = answer;
            bestAnswer.score = score;
            cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
            debug() << imie(score);
        }
    }   
    
    bestAnswer.write();

    // cout<<score<<nl;

}