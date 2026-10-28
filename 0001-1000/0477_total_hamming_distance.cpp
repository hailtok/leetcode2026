// Problem 477: Total Hamming Distance
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int output=0;
        for(int i=0;i<32;i++){
            int zero=0,one=0;
            for(int j=0;j<nums.size();j++){
                if((nums[j]>>i)&1){
                    one++;
                } else {
                    zero++;
                }
            }
            output+=zero*one;
        }
        return output;
    }
};