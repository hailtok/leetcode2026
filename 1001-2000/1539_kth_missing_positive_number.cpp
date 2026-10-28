// Problem 1539: Kth Missing Positive Number
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/kth-missing-positive-number/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans=1;
        for(int i=0;i<arr.size();++i,++ans){
            if(arr[i]!=ans){
                k=k-arr[i]+ans;
                ans=arr[i];
                cout<<k<<endl;
                if(k<=0){
                    break;
                } 
            }
        }
        return ans+k-1;
    }
};