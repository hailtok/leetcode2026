// Problem 3411: Maximum Subarray With Equal Products
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/maximum-subarray-with-equal-products/

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=1;
        for(int i=0;i<nums.size();++i){
            long long prod=nums[i],g=nums[i],l=nums[i];
            for(int j=i+1;j<nums.size();++j){
                prod*=nums[j];
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);
                if(prod>g*l){
                    break;
                }
                if(prod==g*l){
                    ans=std::max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};