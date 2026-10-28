// Problem 3151: Special Array I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/special-array-i/

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool check=nums[0]%2==0?true:false;
        for(int i=1;i<nums.size();++i){
            if(nums[i]%2==0){
                if(check){
                    return false;
                }
                else{
                    check=true;
                }
            }
            else{
                if(!check){
                    return false;
                }
                else{
                    check=false;
                }
            }
        }
        return true;
    }
};