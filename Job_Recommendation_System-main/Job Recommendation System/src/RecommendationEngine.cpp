#include "RecommendationEngine.h"
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
void RecommendationEngine::addUser(User u) {
    users[u.id] = u;
}
void RecommendationEngine::addJob(Job j) {
    jobs[j.id] = j;
    for (auto skill : j.skills) {
        skill_to_job_ids[skill].push_back(j.id);
    }
}

void RecommendationEngine::loadUsersFromCSV(string filename) {
    ifstream file(filename);
    string line;

    getline(file, line); // skip header

    while (getline(file, line)) {
        stringstream ss(line);
        User u;
        string temp, skillsStr;

        getline(ss, temp, ','); u.id = stoi(temp);
        getline(ss, u.name, ',');
        getline(ss, temp, ','); u.cgpa = stof(temp);
        getline(ss, u.domain, ',');
        getline(ss, skillsStr);

        stringstream skillStream(skillsStr);
        while (getline(skillStream, temp, ';')) {
            u.skills.insert(temp);
        }

        addUser(u);
    }
    file.close();
}

void RecommendationEngine::loadJobsFromCSV(string filename) {
    ifstream file(filename);
    string line;

    getline(file, line); // skip header

    while (getline(file, line)) {
        stringstream ss(line);
        Job j;
        string temp, skillsStr;

        getline(ss, temp, ','); j.id = stoi(temp);
        getline(ss, j.company, ',');
        getline(ss, j.role, ',');
        getline(ss, temp, ','); j.minCgpa = stof(temp);
        getline(ss, temp, ','); j.stipend = stoi(temp);
        getline(ss, skillsStr);

        stringstream skillStream(skillsStr);
        while (getline(skillStream, temp, ';')) {
            j.skills.insert(temp);
        }

        addJob(j);
    }
    file.close();
}

vector<Job> RecommendationEngine::recommendJobsGraph(int userId) {
    vector<Job> result;

    if (users.find(userId) == users.end()) {
        return result;
    }

    unordered_map<int, int> jobScore;
    User u = users[userId];

    for (auto skill : u.skills) {
        for (int jobId : skill_to_job_ids[skill]) {
            jobScore[jobId]++;
        }
    }

    priority_queue<pair<int, int>> pq;

    for (auto it : jobScore) {
        pq.push({it.second, it.first});
    }

    while (!pq.empty()) {
        int jobId = pq.top().second;
        pq.pop();
        result.push_back(jobs[jobId]);
    }

    return result;
}

vector<Job> RecommendationEngine::recommendJobs(int userId) {
    vector<Job> ans;

    if (users.find(userId) == users.end()) {
        return ans;
    }

    User u = users[userId];
    priority_queue<pair<int, int>> pq; // score, jobId

    for (auto it : jobs) {
        Job j = it.second;

        if (u.cgpa < j.minCgpa) {
            continue;
        }

        int skillMatch = 0;
        for (auto s : u.skills) {
            if (j.skills.count(s)) {
                skillMatch++;
            }
        }

        if (skillMatch > 0) {
            pq.push({skillMatch, j.id});
        }
    }

    while (!pq.empty()) {
        ans.push_back(jobs[pq.top().second]);
        pq.pop();
    }

    return ans;
}