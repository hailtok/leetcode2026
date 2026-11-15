// Problem 1524: Number of Sub-arrays With Odd Sum
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution {
public:
    static constexpr int mod=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        long long odd=0,even=0,ans=0;
        for(int i=0;i<arr.size();++i){
            if(arr[i]%2==1){
                long long n_odd=even+1,n_even=odd;
                odd=n_odd;
                even=n_even;
            }
            else{
                ++even;
            }
            ans=(ans+odd)%mod;
        }
        return (int)ans;
    }
};