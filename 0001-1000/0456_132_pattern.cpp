// Problem 456: 132 Pattern
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>stack;
        int kth=INT_MIN;
        for(int i=nums.size()-1;i>=0;--i){
            if(nums[i]<kth){
                return true;
            }
            else{
                while(!stack.empty()&&nums[i]>stack.top()){
                    kth=stack.top();
                    stack.pop();
                }
            }
            stack.push(nums[i]);
        }
        return false;
    }
};