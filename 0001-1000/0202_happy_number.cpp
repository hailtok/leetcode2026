// Problem 202: Happy Number
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool>umap;
        int temp=0;
        while(true){
            while(n!=0){
                temp+=(n%10)*(n%10);
                n/=10;
            }
            if(temp==1){
                break;
            }
            if(umap.find(temp)!=umap.end()){
                return false;
            }
            umap.insert({temp,false});
            n=temp;
            temp=0;
        }
        return true;
    }
};