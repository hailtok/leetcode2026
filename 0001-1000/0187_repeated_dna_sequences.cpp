// Problem 187: Repeated DNA Sequences
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/repeated-dna-sequences/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> answer;
        unordered_map<string,int> mp;
        for(int i=0;i+10 <= s.length();i++){
            mp[s.substr(i,10)]++;
        }
        for(auto& i:mp){
            if(i.second > 1){
                answer.push_back(i.first);
            }
        }
        return answer;
    }
};