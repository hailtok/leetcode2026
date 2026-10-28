// Problem 90: Subsets II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int,int> um;
        vector<int> numbers;
        vector<vector<int>> ans_vec;
        for(auto num:nums)
            um[num]++;
        for(auto ele:um)
            numbers.push_back(ele.first);
        vector<int> vec;
        ans_vec.push_back(vec);
        solve(um,numbers,0,ans_vec);
        return ans_vec;
    }
        void solve(unordered_map<int,int>& um,vector<int>& numbers,int cur_index,vector<vector<int>>& ans_vec){
        if(cur_index == numbers.size())return;
        int size = ans_vec.size();
        for(int i = 0 ; i < size ; i++){
            vector<int> cur_vec = ans_vec[i];
            for(int i = 0 ; i < um[numbers[cur_index]] ; i++){
                cur_vec.push_back(numbers[cur_index]);
                ans_vec.push_back(cur_vec);
            }
        }
        solve(um,numbers,cur_index+1,ans_vec);
        return;
    }
};