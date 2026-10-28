// Problem 1758: Minimum Changes To Make Alternating Binary String
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/

class Solution {
public:
    int minOperations(string s) {
        int bucket=0;
        for(int i=0;i<s.size();++i){
            if(i%2==0){
                if(s[i]=='0'){
                    ++bucket;
                }
                
            }
            else{
                if(s[i]=='1'){
                    ++bucket;
                }
            }
        }
        return bucket*2>s.size()?s.size()-bucket:bucket;
    }
};