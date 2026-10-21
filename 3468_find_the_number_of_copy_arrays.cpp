// Problem 3468: Find the Number of Copy Arrays
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/find-the-number-of-copy-arrays/

class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int ans=0,min=bounds[0][0],max=bounds[0][1];
        for(int i=1;i<original.size();++i){
            min+=original[i]-original[i-1];
            max+=original[i]-original[i-1];
            if(max<bounds[i][0]||min>bounds[i][1]){
                return 0;
            }
            max=std::min(max,bounds[i][1]);
            min=std::max(min,bounds[i][0]);
        }
        return max-min+1;
    }
};