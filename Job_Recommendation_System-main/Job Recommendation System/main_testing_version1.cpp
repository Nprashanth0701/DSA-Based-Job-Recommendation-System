#include <iostream>
#include "src/RecommendationEngine.h"
using namespace std;
int main() {
    RecommendationEngine engine;
    // create user
    User u;
    u.id = 1;
    u.name = "Prashanth";
    u.cgpa = 6.90;
    u.domain = "Software";
    u.skills.insert("C++");
    u.skills.insert("DSA");
    u.skills.insert("OOPS");
    engine.addUser(u);
    // create job 1
    Job j1;
    j1.id = 101;
    j1.company = "Tescra";
    j1.role = "Software Engineer Intern";
    j1.minCgpa = 6.5;
    j1.stipend = 20000;
    j1.skills.insert("C++");
    j1.skills.insert("DSA");
    engine.addJob(j1);
    // create job 2
    Job j2;
    j2.id = 102;
    j2.company = "Stackroot";
    j2.role = "Backend Developer";
    j2.minCgpa = 7.5;
    j2.stipend = 15000;
    j2.skills.insert("C++");
    j2.skills.insert("OOPS");
    engine.addJob(j2);
    // get recommendations
    vector<Job> rec = engine.recommendJobs(1);
    cout << "Recommended Jobs:\n";
    for (auto j : rec) {
        cout << j.company << " - " << j.role << endl;
    }
    return 0;
}

