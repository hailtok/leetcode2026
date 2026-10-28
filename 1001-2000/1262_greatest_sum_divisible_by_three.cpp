// Problem 1262: Greatest Sum Divisible by Three
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/greatest-sum-divisible-by-three/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int output=0,temp_output=0,one1=50000,one2=50000,two1=50000,two2=50000;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3==0){
                output+=nums[i];
            }
            else if(nums[i]%3==1){
                temp_output+=nums[i];
                if(one1>nums[i]){
                    one1=nums[i];
                    if(one2>one1){
                        swap(one1,one2);
                    }
                }
            }
            else{
                temp_output+=nums[i];
                if(two1>nums[i]){
                    two1=nums[i];
                    if(two2>two1){
                        swap(two1,two2);
                    }
                }
            }
        }
        if(temp_output%3==1){
            if(one2>two1+two2){
                temp_output=temp_output-two1-two2;
            }
            else{
                temp_output-=one2;
            }
        }
        else if(temp_output%3==2){
            if(two2>one1+one2){
                temp_output=temp_output-one1-one2;
            }
            else{
                temp_output-=two2;
            }
        }
        return output+temp_output;
    }
};