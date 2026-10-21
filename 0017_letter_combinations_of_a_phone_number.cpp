// Problem 17: Letter Combinations of a Phone Number
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        vector<string>letters={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>output;
        output.push_back("");
        for(int i=0;i<digits.size();i++){
            vector<string>temp;
            for(int j=0;j<letters[digits[i]-'0'-2].size();j++){
                for(int k=0;k<output.size();k++){
                    temp.push_back(output[k]+letters[digits[i]-'0'-2][j]);
                }
            }
            output.clear();
            output=temp;
        }
        return output;
    }
};