# 💼 Job Recommendation System – C++ (DSA Based)

![C++](https://img.shields.io/badge/C++-blue)
![DSA](https://img.shields.io/badge/Data%20Structures-green)
![Algorithms](https://img.shields.io/badge/Algorithms-orange)
![CSV](https://img.shields.io/badge/CSV-Data-lightgrey)

A **Data Structures & Algorithms based Job Recommendation System** built using **C++**, designed to recommend suitable jobs to users based on **strict CGPA eligibility and skill matching**.

This project focuses on **core software engineering fundamentals**, using efficient data structures to handle **large datasets (500+ users)** and produce **ranked job recommendations**.

---

## ✨ Key Features

### 👤 User Management
- Loads **500+ users** from `users.csv`
- Each user contains:
  - User ID
  - Name
  - CGPA
  - Domain
  - Skill set

### 💼 Job Management
- Loads **30 job listings** from `jobs.csv`
- Each job includes:
  - Company
  - Role
  - Minimum CGPA
  - Stipend
  - Required skills
- Includes **CGPA = 0 jobs** (internships / open roles) so that every user receives recommendations

---

## 🧠 Recommendation Logic (DSA)

1. **Strict CGPA Filtering**
   - `user.cgpa >= job.minCGPA`
2. **Skill Matching**
   - Each matched skill increases score
3. **Priority-Based Ranking**
   - Uses `priority_queue`
4. **Guaranteed Output**
   - Minimum 5 recommendations per user

---

## 🛠 Tools & Technologies
- C++
- STL (unordered_map, unordered_set, priority_queue, vector)
- CSV based storage

---

## 📁 Project Structure

```
Job_Recommendation_System/
│
├── src/
│   ├── RecommendationEngine.h
│   ├── RecommendationEngine.cpp
│   ├── User.h
│   ├── Job.h
│
├── data/
│   ├── users.csv
│   ├── jobs.csv
│
├── main.cpp
├── README.md
```

---

## 🚀 How to Run

```bash
g++ main.cpp src/RecommendationEngine.cpp -o app
./app
```

---

## 🙋‍♂ About Me

**Nethavath Prashanth**  
B.Tech, IIT Patna  
Aspiring Software Engineer  
GitHub:  https://github.com/Nprashanth0701
LinkedIn: https://www.linkedin.com/in/nethavath-prashanth-a5543925a/  
