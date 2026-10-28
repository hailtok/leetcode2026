// Problem 2160: Minimum Sum of Four Digit Number After Splitting Digits
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

class Solution {
public:
    int minimumSum(int num) {
        vector<int>arr;
        while(num>0){
            arr.push_back(num%10);
            num/=10;
        }
        std::sort(arr.begin(),arr.end());
        return arr[0]*10+arr[2]+arr[1]*10+arr[3];
    }
};