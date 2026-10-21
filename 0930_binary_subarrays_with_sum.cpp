// Problem 930: Binary Subarrays With Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/binary-subarrays-with-sum/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum1=0,sum2=0,left1=0,left2=0,answer=0;
        for(int i=0;i<nums.size();i++) {
            sum1 += nums[i];
            sum2 += nums[i];
            while(sum2 > goal){
                sum2 -= nums[left2++];
            }
            while(sum1 >= goal && left1<=i){
                sum1 -= nums[left1++];
            }
            answer += left1-left2;                    
        }
        return answer;
    }
};