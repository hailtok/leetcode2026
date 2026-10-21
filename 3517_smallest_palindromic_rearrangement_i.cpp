// Problem 3517: Smallest Palindromic Rearrangement I
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/

class Solution {
public:
    string smallestPalindrome(string s) {
        string ans;
        vector<int>arr(26);
        for(int i=0;i<s.size();++i){
            ++arr[s[i]-'a'];
        }
        char mid='\0';
        for(int i=0,j=0;i<arr.size();++i){
            j=arr[i]/2;
            if(arr[i]%2!=0){
                mid=i+'a';
            }
            while(j>0){
                ans+=(i+'a');
                --j;
            }
        }
        string temp=ans;
        std::reverse(ans.begin(),ans.end());
        if(mid!='\0'){
            return temp+mid+ans;
        }
        return temp+ans;
    }
};