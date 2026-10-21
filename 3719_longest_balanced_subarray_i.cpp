// Problem 3719: Longest Balanced Subarray I
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-balanced-subarray-i/

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();++i){
            unordered_set<int>odd,even;
            for(int j=i;j<nums.size();++j){
                if(nums[j]%2==1){
                    odd.insert(nums[j]);
                }
                else{
                    even.insert(nums[j]);
                }
                if(odd.size()==even.size()){
                    ans=std::max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};