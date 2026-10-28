// Problem 2498: Frog Jump II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/frog-jump-ii/

class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans=stones[1]-stones[0];
        for(int i=2;i<stones.size();++i){
            ans=std::max(ans,stones[i]-stones[i-2]);
        }
        return ans;
    }
};