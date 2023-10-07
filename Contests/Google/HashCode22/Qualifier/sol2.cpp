#include <bits/stdc++.h>
using namespace std;

#define nl '\n'
#define all(x) x.begin(), x.end()
#define ll long long
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
    ll numberOfSkills,daysWorked=0;
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
    int completionDays;
    ll score;
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
int no_of_contributors,no_of_projects;
ll score=0;
bool comp(Project a, Project b){
    return a.lastDay<b.lastDay;
}
ll calculateScore(Answer answer){
    ll score=0;
    for(int i=0;i<answer.projects.size();i++){
        score+=answer.projects[i].score;
    }
    return score;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    cin>>no_of_contributors>>no_of_projects;
    vector<Contributor> contributors(no_of_contributors);
    for(int i=0;i<no_of_contributors;i++){
        contributors[i].read();
    }

    vector<Project> projects(no_of_projects);
    for(int i=0;i<no_of_projects;i++){
        projects[i].read();
    }

    sort(all(projects),comp);

    Answer answer;

    
    for(int i=0;i<no_of_projects;i++){
        set<int> conts;
        vector<string> name;
        for(Role role : projects[i].roles){
            for(int j=0;j<no_of_contributors;j++){
                if(contributors[j].findSkill(role.name)>=role.skillLevel && contributors[j].daysWorked+projects[i].completionDays<  projects[i].lastDay+projects[i].score/2 && conts.find(j)==conts.end()){
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
            minus=max(max_day-projects[i].lastDay,0LL);
            score += projects[i].score-min(minus,projects[i].score);
            projects[i].contributors = name;
            answer.projects.push_back(projects[i]);
        }


    }
    
    debug() << imie(score);
    answer.write();

}