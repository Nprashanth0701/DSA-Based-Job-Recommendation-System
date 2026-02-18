#ifndef JOB_H
#define JOB_H
#include <string>
#include <set>
using namespace std;
struct Job {
    int id;
    string company;
    string role;
    double minCgpa;
    int stipend;
    set<string> skills;
};
#endif