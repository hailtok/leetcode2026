// Problem 779: K-th Symbol in Grammar
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution {
public:
    int kthGrammar(int n, int k) {
        bool check=false;
        while(n!=1){
            int num=pow(2,n-1);
            if(num/2<k){
                k-=num/2;
                if(check){
                    check=false;
                }
                else{
                    check=true;
                }
            }
            n--;
        }
        return check;
    }
};