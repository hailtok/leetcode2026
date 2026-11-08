// Problem 1497: Check If Array Pairs Are Divisible by k
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>nums(k,0);
        for(int i=0;i<arr.size();++i){
            if(arr[i]<0){
                ++nums[((arr[i]%k)+k)%k];
            }
            else{
                ++nums[arr[i]%k];
            }
        }
        bool check=true;
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=nums[k-i]){
                check=false;
                break;
            }
        }
        if(nums[0]%2!=0){
            check=false;
        }
        return check;
    }
};