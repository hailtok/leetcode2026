// Problem 2610: Convert an Array Into a 2D Array With Conditions
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int>numbers(nums.size());
        for(int i=0;i<nums.size();i++){
            numbers[nums[i]-1]++;
        }
        vector<vector<int>>answer;
        for(int i=0;i<numbers.size();i++){
            if(numbers[i]>answer.size()){
                for(int j=0;j<answer.size();j++){
                    answer[j].push_back(i+1);
                }
                int count=numbers[i]-answer.size();
                for(int j=0;j<count;j++){
                    answer.push_back(vector<int>{i+1});
                }
            }
            else{
                for(int j=0;j<numbers[i];j++){
                    answer[j].push_back(i+1);
                }
            }
        }
        return answer;
    }
};