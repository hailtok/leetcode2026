// Problem 1925: Count Square Sum Triples
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/count-square-sum-triples/

class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for(int i=2;i<=n;++i){
            for(int j=1;j<n;++j){
                for(int k=1;k<n;++k){
                    if(j*j+k*k==i*i){
                        ++ans;
                    }
                    if(j*j+k*k>i*i){
                        break;
                    }
                }
            }
        }
        return ans;
    }
};