// Problem 2525: Categorize Box According to Criteria
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/categorize-box-according-to-criteria/

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky=false,heavy=false;
        if(length>=1e4||width>=1e4||height>=1e4||(long long)length*(long long)width*(long long)height>=1e9){
            bulky=true;
        }
        if(mass>=100){
            heavy=true;
        }
        if(bulky){
            return heavy?"Both":"Bulky";
        }
        return heavy?"Heavy":"Neither";
    }
};