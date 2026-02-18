#ifndef USER_H
#define USER_H
#include <string>
#include <set>
using namespace std;
struct User {
    int id;
    string name;
    set<string> skills;
    float cgpa;
    string domain;
};
#endif