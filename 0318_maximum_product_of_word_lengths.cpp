// Problem 318: Maximum Product of Word Lengths
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/maximum-product-of-word-lengths/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int>value(words.size());
        for(int i=0;i<words.size();++i){
            int val=0;
            for(int j=0;j<words[i].size();j++){
                val=val|(1<<(words[i][j]-'a'));
            }
            value[i]=val;
        }
        int answer=0;
        for(int i=0;i<value.size()-1;++i){
            for(int j=i+1;j<value.size();++j){
                if((value[i]&value[j])==0){
                    answer=max((int)(words[i].size()*words[j].size()),answer);
                }
            }
        }
        return answer;
    }
};