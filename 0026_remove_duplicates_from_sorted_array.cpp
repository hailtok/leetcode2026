// Problem 26: Remove Duplicates from Sorted Array
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>new_arr;
        int num=INT_MIN,ans=0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]!=num){
                cout<<nums[i]<<endl;
                new_arr.push_back(nums[i]);
                num=nums[i];
                ++ans;
            }
        }
        nums=new_arr;
        cout<<ans<<endl;
        return ans;
    }
};