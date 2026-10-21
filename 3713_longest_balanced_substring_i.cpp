// Problem 3713: Longest Balanced Substring I
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-balanced-substring-i/

class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.size();++i){
            vector<int>alpha(26,-1);
            for(int j=i,count=0;j<s.size();++j){
                ++alpha[s[j]-'a'];
                count=std::max(count,alpha[s[j]-'a']);
                bool check=true;
                for(int k=0;k<alpha.size();++k){
                    if(alpha[k]!=-1){
                        if(count!=alpha[k]){
                            check=false;
                            break;
                        }
                    }
                }
                if(check){
                    ans=std::max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};