// Problem 299: Bulls and Cows
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>secret_number(10);
        vector<int>guess_number(10);
        int A=0,B=0;
        for(int i=0;i<guess.size();i++){
            if(secret[i]==guess[i]){
                A++;
            }
            else{
                secret_number[secret[i]-'0']++;
                guess_number[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            B+=min(secret_number[i],guess_number[i]);
        }
        return to_string(A)+"A"+to_string(B)+"B";
    }
};