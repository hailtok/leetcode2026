// Problem 2131: Longest Palindrome by Concatenating Two Letter Words
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>umap;
        for(int i=0;i<words.size();++i){
            ++umap[words[i]];
        }
        int same=0,diff=0,three=0;
        for(int i=0;i<words.size();++i){
            if(words[i][0]==words[i][1]){
                if(umap[words[i]]%2==1){
                    three=1;
                    --same;
                    --umap[words[i]];
                }
                ++same;
            }
            else{
                string temp=words[i];
                std::reverse(words[i].begin(),words[i].end());
                if(umap.find(words[i])!=umap.end()){
                    diff+=std::min(umap[temp],umap[words[i]])*2;
                    umap.erase(temp);
                    umap.erase(words[i]);
                }
            }
        }
        cout<<same<<endl;
            cout<<diff<<endl;
            cout<<three<<endl;
        return same*2+diff*2+three*2;
    }
};