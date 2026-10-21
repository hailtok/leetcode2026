// Problem 167: Two Sum II - Input Array Is Sorted
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right=numbers.size()-1;
        vector<int>output(2);
        while(left!=right){
            int total=numbers[left]+numbers[right];
            if(total>target){
                right--;
            }
            else if(total<target){
                left++;
            }
            else{
                output[0]=left+1;
                output[1]=right+1;
                break;
            }
        }
        return output;
    }
};