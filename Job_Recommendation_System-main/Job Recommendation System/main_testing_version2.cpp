#include <iostream>
#include "src/RecommendationEngine.h"
using namespace std;
int main() {
    RecommendationEngine engine;
    int userCount;
    cout << "Enter number of users: ";
    cin >> userCount;
    for (int i = 0; i < userCount; i++) {
        User u;
        int skillCount;
        cout << "\nUser ID: ";
        cin >> u.id;
        cout << "Name: ";
        cin >> u.name;
        cout << "CGPA: ";
        cin >> u.cgpa;
        cout << "Domain: ";
        cin >> u.domain;
        cout << "Number of skills: ";
        cin >> skillCount;
        for (int j = 0; j < skillCount; j++) {
            string skill;
            cin >> skill;
            u.skills.insert(skill);
        }
        engine.addUser(u);
    }
    int jobCount;
    cout << "\nEnter number of jobs: ";
    cin >> jobCount;
    for (int i = 0; i < jobCount; i++) {
        Job j;
        int skillCount;
        cout << "\nJob ID: ";
        cin >> j.id;
        cout << "Company: ";
        cin >> j.company;
        cout << "Role: ";
        cin >> j.role;
        cout << "Minimum CGPA: ";
        cin >> j.minCgpa;
        cout << "Stipend: ";
        cin >> j.stipend;
        cout << "Number of required skills: ";
        cin >> skillCount;
        for (int k = 0; k < skillCount; k++) {
            string skill;
            cin >> skill;
            j.skills.insert(skill);
        }
        engine.addJob(j);
    }
    int uid;
    cout << "\nEnter user ID to get recommendations: ";
    cin >> uid;
    vector<Job> result = engine.recommendJobs(uid);
    cout << "\nTop Job Recommendations:\n";
    for (int i = 0; i < result.size() && i < 3; i++) {
        cout << result[i].company << " - " << result[i].role << endl;
    }
    return 0;
}
