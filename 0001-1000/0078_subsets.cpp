// Problem 78: Subsets
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>output;
        vector<bool>nums_check(nums.size());
        int power=int(pow(2,nums.size()));
        for(int i=0;i<power;i++){
            vector<int>temp;
            for(int j=0;j<nums.size();j++){
                if(nums_check[j]){
                    temp.push_back(nums[j]);
                }
            }
            output.push_back(temp);
            for(int j=nums_check.size()-1;j>=0;j--){
                if(nums_check[j]){
                    for(int k=j-1;k>=0;k--){
                        if(nums_check[k]){
                           nums_check[k]=false; 
                        }
                        else{
                            nums_check[k]=true;
                            break;
                        }
                    }
                    nums_check[j]=false;
                }
                else{
                    nums_check[j]=true;
                }
            }
        }
        return output;
    }
};