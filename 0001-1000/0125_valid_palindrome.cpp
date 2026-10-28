// Problem 125: Valid Palindrome
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<=right){
            if(!isalpha(s[left])&&!isdigit(s[left])){
                left++;
                continue;
            }
            if(!isalpha(s[right])&&!isdigit(s[right])){
                right--;
                continue;
            }
            if(tolower(s[right])!=tolower(s[left])){
                cout<<s[right]<<endl;
                cout<<s[left]<<endl;
                return false;
            }
            else{
                right--;
                left++;
            }
        }
        return true;
    }
};