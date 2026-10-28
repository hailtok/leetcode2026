// Problem 1390: Four Divisors
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/four-divisors/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int all_total=0;
        for(int i=0;i<nums.size();i++){
            int divisor=0,total=0,j;
            for(j=1;j*j<nums[i];j++){
                if(nums[i]%j==0){
                    total+=nums[i]/j+j;
                    divisor+=2;
                }
                if(divisor>4){
                    total=0;
                    break;
                }
            }
            if(divisor==4&&j*j!=nums[i]){
                all_total+=total;
            }
        }
        return all_total;
    }
};