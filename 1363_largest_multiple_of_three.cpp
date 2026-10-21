// Problem 1363: Largest Multiple of Three
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/largest-multiple-of-three/

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<int>nums(10);
        vector<int>rem1{1,4,7,2,5,8},rem2{2,5,8,1,4,7};
        string ans="";
        int sum=0;
        for(int i=0;i<digits.size();++i){
            ++nums[digits[i]];
            sum+=digits[i];
        }
        while(sum%3!=0){
            for(int i=0;i<6;++i){
                if(sum%3==1&&nums[rem1[i]]){
                    sum-=rem1[i];
                    --nums[rem1[i]];
                }
                else if(sum%3==2&&nums[rem2[i]]){
                    sum-=rem2[i];
                    --nums[rem2[i]];
                }
            }
        }
        for(int i=9;i>=0;--i){
            ans+=string(nums[i],i+'0');
        }
        return ans.size()&&ans[0]=='0'?"0":ans;
    }
};