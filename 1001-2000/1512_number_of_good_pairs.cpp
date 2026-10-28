// Problem 1512: Number of Good Pairs
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/number-of-good-pairs/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int>temp(100);
        for(int i=0;i<nums.size();i++){
            temp[nums[i]-1]++;
        }
        int answer=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]>1){
                answer+=(temp[i]*(temp[i]-1)/2);
            }
        }
        return answer;
    }
};