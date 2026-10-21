// Problem 1255: Maximum Score Words Formed by Letters
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/maximum-score-words-formed-by-letters/

class Solution {
public:
    unordered_map<int,int>mp;
    vector<unordered_map<int,int>>count;
    vector<int>values;
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(int i=0;i<letters.size();i++){
            mp[letters[i]-'a']++;
        }
        for(int i=0;i<words.size();i++){
            unordered_map<int,int>temp;
            int val=0;
            bool check=true;
            for(int j=0;j<words[i].size();j++){
                temp[words[i][j]-'a']++;
                val+=score[words[i][j]-'a'];
                if(mp[words[i][j]-'a']<temp[words[i][j]-'a']){
                    check=false;
                }
            }
            count.push_back(temp);
            if(check){
                values.push_back(val);
            }
            else{
                values.push_back(0);
            }       
        }
        unordered_map<int,int>t;
        return recursion(t,0,0);
    }
    int recursion(unordered_map<int,int>ump,int index,int value){
        if(index==count.size()){
            return value;
        }
        unordered_map<int,int> cur_count=count[index];
        for(auto it=ump.begin();it!=ump.end();it++){
            cur_count[it->first]+=it->second;
            if(cur_count[it->first]>mp[it->first]){
                return recursion(ump,index+1,value);
            }
        }
        return max(recursion(ump,index+1,value),recursion(cur_count,index+1,value+values[index]));
    }
};