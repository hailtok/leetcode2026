// Problem 171: Excel Sheet Column Number
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int answer=0;
        for(int i=0;i<columnTitle.size();++i){
            answer*=26;
            answer+=columnTitle[i]-'A'+1;
        }
        return answer;
    }
};