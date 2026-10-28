// Problem 58: Length of Last Word
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int output=0,index;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                index=i;
                break;
            }
        }
        for(int i=index;i>=0;i--){
            if(s[i]==' '){
                break;
            }
            else{
                output++;
            }
        }
        return output;
    }
};