// Problem 386: Lexicographical Numbers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/lexicographical-numbers/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>output(n);
        int cur=1;
        for(int i=0;i<n;i++){
            output[i]=cur;
            if(cur*10<=n){
                cur*=10;
            }
            else{
                if(cur>=n){
                    cur/=10;
                }
                cur++;
                while(cur%10==0){
                    cur/=10;
                }
            }
        }
        return output;
    }
};