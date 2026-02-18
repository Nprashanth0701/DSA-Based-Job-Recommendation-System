#ifndef RECOMMENDATION_ENGINE_H
#define RECOMMENDATION_ENGINE_H
#include <unordered_map>
#include <vector>
#include "User.h"
#include "Job.h"
using namespace std;
class RecommendationEngine {
private:
    unordered_map<int, User> users;
    unordered_map<int, Job> jobs;
    unordered_map<string, vector<int>> skill_to_job_ids;
public:
    void addUser(User u);
    void addJob(Job j);
    vector<Job> recommendJobs(int userId);
    vector<Job> recommendJobsGraph(int userId);
    void loadUsersFromCSV(string filename);
    void loadJobsFromCSV(string filename);

};
#endif