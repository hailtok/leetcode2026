// Problem 1770: Maximum Score from Performing Multiplication Operations
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

class Solution {
public:
    vector<int>numbers;
    vector<int>mul;
    int dp[1000][1000];
    int recursion(int index,int left,int right){
        if(index==mul.size()){
            return 0;
        }
        if(dp[left][index]!=1e9){
            return dp[left][index];
        }
        int first=mul[index]*numbers[left]+recursion(index+1,left+1,right);
        int second=mul[index]*numbers[right]+recursion(index+1,left,right-1);
        dp[left][index]=max(first,second);
        return dp[left][index];
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
         for(int i=0; i<1000; i++){
             for(int j=0; j<1000; j++){
                 dp[i][j] = 1e9;
             }
         }
        for(int i=0;i<nums.size();i++){
            numbers.push_back(nums[i]);
        }
        for(int i=0;i<multipliers.size();i++){
            mul.push_back(multipliers[i]);
        }
        return recursion(0,0,nums.size()-1);
    }
};