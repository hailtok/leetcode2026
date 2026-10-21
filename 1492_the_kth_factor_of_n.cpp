// Problem 1492: The kth Factor of n
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/the-kth-factor-of-n/

class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int>factor,end;
        int i,track=0,back;
        for(i=1;i*i<=n;i++){
            if(n%i==0){
                track++;
                factor.push_back(i);
                end.push_back(i);
            }
            if(track==k){
                return i;
            }
        }
        if((i-1)*(i-1)==n){
            back=track-1;
        }
        else{
            back=track;
        }
        if(k-back>factor.size()){
            return -1;
        }
        reverse(factor.begin(),factor.end());
        return n/factor[k-factor.size()-1];
    }
};