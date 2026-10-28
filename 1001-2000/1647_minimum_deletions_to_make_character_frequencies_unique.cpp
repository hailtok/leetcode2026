// Problem 1647: Minimum Deletions to Make Character Frequencies Unique
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        vector<int>alphabet(26);
        for(int i=0;i<s.size();i++){
            alphabet[s[i]-'a']++;
        }
        map<int,int>mp;
        for(int i=0;i<26;i++){
            if(alphabet[i]!=0){
                mp[alphabet[i]]++;
            }
        }
        auto i=mp.rbegin();
        int output=0,last_first=i->first,last_second=i->second-1;
        i++;
        for(;i!=mp.rend();i++){
            if(last_second!=0){
                if(last_first-i->first<=last_second){
                    output+=((last_second+(last_second-(last_first-i->first-1)))*(last_first-i->first))/2;
                    last_second-=last_first-i->first;
                    last_second+=i->second;
                }
                else{
                    output+=(last_second+1)*last_second/2;
                    last_second=i->second-1;
                }
            }
            else{
                last_second=i->second-1;
            }
            last_first=i->first;
        }
        if(last_first-last_second>=0){
            output+=(last_second+1)*last_second/2;
        }
        else{
            output+=(2*last_second-last_first+1)*(last_first)/2;
        }  
        return output;
    }
};