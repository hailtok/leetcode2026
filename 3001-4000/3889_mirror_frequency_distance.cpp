// Problem 3889: Mirror Frequency Distance
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/mirror-frequency-distance/

class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int>f1(10),f2(26);
        for(int i=0;i<s.size();++i){
            if(isdigit(s[i])){
                ++f1[s[i]-'0'];
            }
            else{
                ++f2[s[i]-'a'];
            }
        }
        int ans=0;
        for(int i=0;i<5;++i){
            ans+=std::abs(f1[i]-f1[9-i]);
        }
        for(int i=0;i<13;++i){
            ans+=std::abs(f2[i]-f2[25-i]);
        }
        return ans;
    }
};