// Problem 982: Triples with Bitwise AND Equal To Zero
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        vector<int>count(1<<16,0);
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<nums.size();++j){
                ++count[nums[i]&nums[j]];
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();++i){
            for(int mask=0;mask<count.size();++mask){
                if((mask&nums[i])==0){
                    ans+=count[mask];
                }
            }
        }
        return ans;
    }
};