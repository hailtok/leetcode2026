// Problem 49: Group Anagrams
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/group-anagrams/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<map<char,int>>alphabet;
        vector<vector<string>>output;
        for(int i=0;i<strs.size();i++){
            map<char,int>temp;
            for(int j=0;j<strs[i].size();j++){
                temp[strs[i][j]]++;
            }
            bool check=false;
            for(int j=0;j<alphabet.size();j++){
                if(output[j][0].size()==strs[i].size()){
                    check=true;
                    for(auto k=alphabet[j].begin(),l=temp.begin();k!=alphabet[j].end();k++,l++){
                        if(k->first!=l->first||k->second!=l->second){
                            check=false;
                            break;
                        }
                    }
                    if(check){
                        output[j].push_back(strs[i]);
                        break;
                    }
                }
            }
            if(!check){
                output.push_back({strs[i]});
                alphabet.push_back(temp);
            }
        }
        return output;
    }
};