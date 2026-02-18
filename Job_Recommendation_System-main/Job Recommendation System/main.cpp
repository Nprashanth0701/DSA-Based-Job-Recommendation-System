#include <iostream>
#include "src/RecommendationEngine.h"
using namespace std;

int main() {
    RecommendationEngine engine;

    // LOAD DATA FROM CSV FILES
    engine.loadUsersFromCSV("data/users.csv");
    engine.loadJobsFromCSV("data/jobs.csv");

    cout << "Users and Jobs loaded successfully.\n";

    int uid;
    cout << "\nEnter user ID to get recommendations:";
    cin >> uid;

    vector<Job> result = engine.recommendJobs(uid);

    cout << "\nTop Job Recommendations:\n";
    for (int i = 0; i < result.size() && i < 5; i++) {
        cout << result[i].company << " - " << result[i].role << endl;
    }

    return 0;
}

