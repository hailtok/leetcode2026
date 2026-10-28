// Problem 66: Plus One
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        digits[0]++;
        for(int i=0;i<digits.size();i++){
            if(digits[i]==10){
                digits[i]=0;
                if(i+1==digits.size()){
                    digits.push_back(1);
                }
                else{
                    digits[i+1]++;
                }
            }
            else{
                break;
            }
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};