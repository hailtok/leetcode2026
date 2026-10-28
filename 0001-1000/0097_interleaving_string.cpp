// Problem 97: Interleaving String
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()){
            return false;
        }
        vector<vector<bool>>check(s1.size()+1,vector<bool>(s2.size()+1));
        for(int i=0;i<s1.size()+1;++i){
            for(int j=0;j<s2.size()+1;++j){
                if(i==0&&j==0){
                    check[i][j]=true;
                }
                else if(i==0){
                    check[i][j]=(check[i][j-1]&&s2[j-1]==s3[i+j-1]);
                }
                else if(j==0){
                    check[i][j]=(check[i-1][j]&&s1[i-1]==s3[i+j-1]);
                }
                else{
                    check[i][j]=(check[i][j-1]&&s2[j-1]==s3[i+j-1])||(check[i-1][j]&&s1[i-1]==s3[i+j-1]);
                }
            }
        }
        return check[s1.size()][s2.size()];
    }
};