// Problem 1248: Count Number of Nice Subarrays
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>odd_index;
        odd_index.push_back(-1);
        int output=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                odd_index.push_back(i);
            }
        }
        odd_index.push_back(nums.size());
        int begin=1,end=k;
        while(end+1<odd_index.size()){
            output+=((odd_index[end+1]-odd_index[end])*(odd_index[begin]-odd_index[begin-1]));
            begin++;
            end++;
        }
        return output;
    }
};