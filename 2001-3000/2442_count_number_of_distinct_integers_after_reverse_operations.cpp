// Problem 2442: Count Number of Distinct Integers After Reverse Operations
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {        
        for(int i=nums.size()-1;i>=0;i--){
            int reverse=0,temp=nums[i];
            while(temp>0){
                reverse*=10;
                reverse+=temp%10;
                temp/=10;
            }
            nums.push_back(reverse);
        }
        sort(nums.begin(),nums.end());
        int answer=0;
        for(int i=0;i<nums.size();i++){
            while(i<nums.size()-1&&nums[i]==nums[i+1]){
                i++;
            }
            answer++;
        }
        return answer;
    }
};