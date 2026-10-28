// Problem 2839: Check if Strings Can be Made Equal With Operations I
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        unordered_map<char,int>even,odd;
        for(int i=0;i<s1.size();++i){
            (i&1)==0?++even[s1[i]]:++odd[s1[i]];
        }
        for(int i=0;i<s2.size();++i){
            if((i&1)==0){
                --even[s2[i]];
                if(even[s2[i]]<0){
                    return false;
                }
            }
            else{
                --odd[s2[i]];
                if(odd[s2[i]]<0){
                    return false;
                }
            }
        }
        return true;
    }
};