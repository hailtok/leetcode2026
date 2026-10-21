// Problem 974: Subarray Sums Divisible by K
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int>divide(k);
        divide[0]++;
        int answer=0,temp=0;
        for(int i=0;i<nums.size();i++){
            temp=(nums[i]+temp)%k;
            if(temp<0){
                temp+=k;
            }           
            answer+=divide[temp];
            divide[temp]++;
        }
        return answer;
    }
};