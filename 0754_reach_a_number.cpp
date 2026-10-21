// Problem 754: Reach a Number
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/reach-a-number/

class Solution {
public:
    int reachNumber(int target) {
        target=std::abs(target);
        int ans=1,cur=ans*(ans+1);
        while(true){
            if(ans*ans+ans-2*target>=0&&(ans*ans+ans-2*target)%4==0){
                break;
            }
            ++ans;
        }
        return ans;
    }
};