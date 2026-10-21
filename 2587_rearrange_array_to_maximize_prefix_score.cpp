// Problem 2587: Rearrange Array to Maximize Prefix Score
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int answer=0;
        long long sum=0;
        for(int i=nums.size()-1;i>=0;--i){
            sum+=nums[i];
            if(sum>0){
                answer++;
            }
            else{
                break;
            }
        }
        return answer;
    }
};