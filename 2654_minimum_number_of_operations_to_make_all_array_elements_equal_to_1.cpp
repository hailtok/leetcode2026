// Problem 2654: Minimum Number of Operations to Make All Array Elements Equal to 1
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int one_exist=count(nums.begin(),nums.end(),1);
        if(one_exist){
            return nums.size()-one_exist;
        }
        int answer=INT_MAX;
        for(int i=0;i<nums.size();++i){
            int temp=nums[i];
            for(int j=i+1;j<nums.size();++j){
                temp=__gcd(temp,nums[j]);
                if(temp==1){
                    answer=std::min(answer,j-i+int(nums.size()-1));
                    break;
                }
            }
        }
        if(answer==INT_MAX){
            return -1;
        }
        return answer;
    }
};