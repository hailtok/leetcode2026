// Problem 3660: Jump Game IX
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/jump-game-ix/

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        vector<int>prefix(nums.size()),suffix(nums.size());
        prefix[0]=nums[0];
        for(int i=1;i<prefix.size();++i){
            prefix[i]=std::max(nums[i],prefix[i-1]);
        }
        suffix.back()=nums.back();
        for(int i=nums.size()-2;i>=0;--i){
            suffix[i]=std::min(nums[i],suffix[i+1]);
        }
        vector<int>ans(nums.size());
        ans.back()=prefix.back();
        for(int i=nums.size()-2;i>=0;--i){
            if(prefix[i]>suffix[i+1]){
                ans[i]=ans[i+1];
            }
            else{
                ans[i]=prefix[i];
            }
        }
        return ans;
    }
};