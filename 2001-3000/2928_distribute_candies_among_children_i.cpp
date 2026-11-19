// Problem 2928: Distribute Candies Among Children I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/distribute-candies-among-children-i/

class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans=0;
        for(int i=0;i<=limit;++i){
            for(int j=0;j<=limit;++j){
                if(n-i-j<=limit&&n-i-j>=0){
                    ++ans;
                }
            }
        }
        return ans;
    }
};