// Problem 324: Wiggle Sort II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/wiggle-sort-ii/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>temp(nums);
        sort(temp.begin(),temp.end());
        bool turn=true;
        for(int i=0,left=(temp.size()-1)/2,right=temp.size()-1;i<nums.size();i++){
            if(turn){
                nums[i]=temp[left];
                turn=false;
                left--;
            }
            else{
                nums[i]=temp[right];
                turn=true;
                right--;
            }
        }
        return;
    }
};