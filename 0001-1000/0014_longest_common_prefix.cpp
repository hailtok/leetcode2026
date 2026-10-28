// Problem 14: Longest Common Prefix
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/longest-common-prefix/

class Solution {
public
    string longestCommonPrefix(vectorstring& strs) {
        string answer=;
        int min_length=INT_MAX;
        for(int i=0;istrs.size();++i){
            min_length=min(min_length,(int)strs[i].size());
        }
        for(int i=0;imin_length;++i){
            bool check=true;
            char prefix=strs[0][i];
            for(int j=1;jstrs.size();++j){
                if(prefix!=strs[j][i]){
                    check=false;
                    break;
                }
            }
            if(check){
                answer+=prefix;
            }
            else{
                break;
            }
        }
        return answer;
    }
};