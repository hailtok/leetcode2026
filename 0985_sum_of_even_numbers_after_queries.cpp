// Problem 985: Sum of Even Numbers After Queries
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>is_even(nums.size());
        vector<int>output;
        int even_sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                is_even[i]=true;
                even_sum+=nums[i];
            }
        }
        for(int i=0;i<queries.size();i++){
            if(is_even[queries[i][1]]){
                if(queries[i][0]%2==0){
                    nums[queries[i][1]]+=queries[i][0];
                    output.push_back(even_sum+queries[i][0]);
                    even_sum+=queries[i][0];
                }
                else{
                    is_even[queries[i][1]]=false;
                    output.push_back(even_sum-nums[queries[i][1]]);
                    even_sum-=nums[queries[i][1]];
                    nums[queries[i][1]]+=queries[i][0];
                }
            }
            else{
                if(queries[i][0]%2==0){
                    nums[queries[i][1]]+=queries[i][0];
                    output.push_back(even_sum);
                }
                else{
                    is_even[queries[i][1]]=true;
                    nums[queries[i][1]]+=queries[i][0];
                    output.push_back(even_sum+nums[queries[i][1]]);
                    even_sum+=nums[queries[i][1]];
                }
            }
        }
        return output;
    }
};