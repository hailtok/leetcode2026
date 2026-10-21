// Problem 1359: Count All Valid Pickup and Delivery Options
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/

class Solution {
public:
    int countOrders(int n) {
        int mod=1e9+7;
        long long ans=1;
        for(int i=1;i<=n;++i){
            ans=(ans*(i*(2*i-1)%mod))%mod;
        }
        return ans;
    }
};