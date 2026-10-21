// Problem 2226: Maximum Candies Allocated to K Children
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int left=0,right=1e7+1;
        while(left<right){
            int mid=(right-left)/2+left;
            long long sum=0;
            if(mid==0){
                return 0;
            }
            for(int i=0;i<candies.size();++i){
                sum+=candies[i]/mid;
            }
            if(k>sum){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }  
        return left-1;
    }
};