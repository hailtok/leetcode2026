// Problem 45: Jump Game II
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/jump-game-ii/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size() ; 
        if(n == 1 ) return 0 ; 
        if(nums[0] >= n - 1 ) return 1; 
        int jumps = 0 ; 
        int maxreach = nums[0] ; 
        ++jumps ; 
        int initial_track = nums[0] ; 
        for(int i = 1 ; i < n ; ++i){
            if(i == n - 1 ) break ; 
            maxreach = max(maxreach , nums[i] + i) ; 
            if(i == initial_track){
                initial_track = maxreach ; 
                ++jumps ;
            }
            
        }
        return jumps ; 
    }
};