// Problem 207: Course Schedule
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int>degree(numCourses,0);
        for(int i=0;i<prerequisites.size();++i){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i) {
            if(degree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int course = q.front(); 
            q.pop();
            for(int i=0;i<graph[course].size();++i) {
                if(--degree[graph[course][i]] == 0){
                    q.push(graph[course][i]);
                }
            }
            ++count;
        }
        return count==numCourses;
    }
};