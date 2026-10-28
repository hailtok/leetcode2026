// Problem 12: Integer to Roman
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        vector<int>numbers{1000,500,100,50,10,5,1};
        vector<char>roman{'M','D','C','L','X','V','I'};
        string output="";
        while(num>=1000){
            num-=1000;
            output.push_back('M');
        }
        for(int i=0;i<numbers.size()-1;i+=2){
            if(num>=numbers[i]-numbers[i+2]){
                output.push_back(roman[i+2]);
                output.push_back(roman[i]);
                num=num-(numbers[i]-numbers[i+2]);
            }
            else if(num>=numbers[i+1]-numbers[i+2]&&numbers[i+1]>num){
                output.push_back(roman[i+2]);
                output.push_back(roman[i+1]);
                num=num-(numbers[i+1]-numbers[i+2]);
            }
            else{
                if(num/numbers[i+2]>=5){
                    output.push_back(roman[i+1]);
                    num-=numbers[i+1];
                }
                while(num>=numbers[i+2]){
                    output.push_back(roman[i+2]);
                    num-=numbers[i+2];
                }
            }
        }
        return output;
    }
};