// Problem 208: Implement Trie (Prefix Tree)
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie {
private:
    unordered_map<char,Trie*>umap;
    bool end=false;
public:
    Trie() {
        
    }
    void insert(string word) {
        Trie* cur=this;
        for(int i=0;i<word.size();++i){
            if(cur->umap.find(word[i])==cur->umap.end()){
                cur->umap[word[i]]=new Trie();
            }
            cur=cur->umap[word[i]];
        }
        cur->end=true;
    }
    bool search(string word) {
        Trie* cur=this;
        for(int i=0;i<word.size();++i){
            if(cur->umap.find(word[i])==cur->umap.end()){
                return false;
            }
            cur=cur->umap[word[i]];
        }
        return cur->end;
    }
    bool startsWith(string prefix) {
        Trie* cur=this;
        for(int i=0;i<prefix.size();++i){
            if(cur->umap.find(prefix[i])==cur->umap.end()){
                return false;
            }
            cur=cur->umap[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */