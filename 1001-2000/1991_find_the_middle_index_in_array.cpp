// Problem 1991: Find the Middle Index in Array
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/find-the-middle-index-in-array/

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int left=0,middle_index=-1,right=0;
        for(int i=0;i<nums.size();++i){
            right+=nums[i];
        }
        for(int i=0;i<nums.size();++i){
            right-=nums[i];
            if(left==right){
                middle_index=i;
                break;
            }    
            left+=nums[i];
        }
        return middle_index;
    }
};