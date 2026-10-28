// Problem 1665: Minimum Initial Energy to Finish Tasks
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]-a[0]>b[1]-b[0];
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);
        int answer=0,energy=0;
        for(int i=0;i<tasks.size();++i){
            if(energy<tasks[i][1]){
                answer+=tasks[i][1]-energy;
                energy=tasks[i][1]-tasks[i][0];
            }
            else{
                energy-=tasks[i][0];
            }
        }
        return answer;
    }
};