// Problem 944: Delete Columns to Make Sorted
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        for(int i=0;i<strs[0].size();++i){
            for(int j=1;j<strs.size();++j){
                char pre=strs[j-1][i];
                if(pre>strs[j][i]){
                    ++ans;
                    break;
                }
            }
        }
        return ans;
    }
};