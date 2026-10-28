// Problem 75: Sort Colors
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>count(3);
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        int start=0;
        for(int i=0,j=0;i<nums.size();i++){
            if(count[j]!=0){
                nums[i]=j;
                count[j]--;
            }
            else{
                j++;
                i--;
            }
        }
    }
};