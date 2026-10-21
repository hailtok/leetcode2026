// Problem 241: Different Ways to Add Parentheses
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/different-ways-to-add-parentheses/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>nums;
        vector<char>opera;
        int temp=0;
        for(int i=0;i<expression.size();++i){
            if(isdigit(expression[i])){
                temp*=10;
                temp+=expression[i]-'0';
            }
            else{
                nums.push_back(temp);
                temp=0;
                opera.push_back(expression[i]);
            }
        }
        nums.push_back(temp);
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(nums.size()));
        for(int window=1;window<=nums.size();++window){
            for(int i=0;i<=nums.size()-window;++i){
                int j=i+window-1;
                if(window==1){
                    dp[i][j].push_back(nums[i]);
                    continue;
                }
                for(int k=i;k<j;++k){
                    char op=opera[k];
                    for (int leftVal:dp[i][k]) {
                        for (int rightVal:dp[k + 1][j]) {
                            if (op=='+') dp[i][j].push_back(leftVal+rightVal);
                            else if (op=='-') dp[i][j].push_back(leftVal-rightVal);
                            else if (op=='*') dp[i][j].push_back(leftVal*rightVal);
                        }
                    }
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};