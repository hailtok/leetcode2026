// Problem 91: Decode Ways
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        vector<int>dp={1,1};
        unsigned output=1,length=0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='0'&&s[i-1]!='2'&&s[i-1]!='1'){
                return 0;
            }
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'||s[i]=='2'){
                length++;
            }
            else if(length!=0){
                while(dp.size()<=length){
                    int temp=dp.size();
                    dp.push_back(dp[temp-1]+dp[temp-2]);
                }
                if(s[i]=='0'){
                    output*=dp[length-1];
                }
                else if (s[i-1]=='2'&&s[i]>'6'){
                    output*=dp[length];
                }
                else{
                    output*=dp[length]+dp[length-1];
                }
                length=0;
            }
        }
        if(length!=0){
            while(dp.size()<=length){
                int temp=dp.size();
                dp.push_back(dp[temp-1]+dp[temp-2]);
            }
            output*=dp[length];
        }
        return output;
    }
};