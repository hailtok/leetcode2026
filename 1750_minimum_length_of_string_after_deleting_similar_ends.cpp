// Problem 1750: Minimum Length of String After Deleting Similar Ends
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

class Solution {
public:
    int minimumLength(string s) {
        int left=0,right=s.size()-1;
        while(left<right){
            if(s[left]!=s[right]){
                break;
            }
            char temp=s[left];
            while(s[left]==temp&&left<=right){
                left++;
            }
            while(s[right]==temp&&right>=left){
                right--;
            }
        }
        return right-left+1;
    }
};