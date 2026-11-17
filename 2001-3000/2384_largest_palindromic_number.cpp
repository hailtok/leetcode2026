// Problem 2384: Largest Palindromic Number
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/largest-palindromic-number/

class Solution {
public:
    string largestPalindromic(string num) {
        vector<int>nums(10,0);
        for(int i=0;i<num.size();++i){
            ++nums[num[i]-'0'];
        }
        string ans="";
        int odd_max=INT_MIN;
        for(int i=9;i>=0;--i){
            for(int j=0;j<nums[i]/2;++j){
                ans+=(i+'0');
            }
            if(nums[9-i]%2==1){
                odd_max=9-i;
            }
        }
        int zero=0;
        while(zero<ans.size()){
            if(ans[zero]!='0'){
                break;
            }
            ++zero;
        }
        ans=ans.substr(zero);
        string t=ans;
        std::reverse(t.begin(),t.end());
        if(odd_max!=INT_MIN){
            t=(char)(odd_max+'0')+t;
        }
        ans=ans+t;
        if(ans.size()==0){
            return "0";
        }
        return ans;
    }
};