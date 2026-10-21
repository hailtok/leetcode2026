// Problem 394: Decode String
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/decode-string/

class Solution {
public:
    string input;
    int i;
    string recursion(){
        string output="";
        int number=0;
        for(;i<input.size();i++){
            if(input[i]=='['){
                i++;
                string temp="";
                temp=recursion();
                for(int j=0;j<number;j++){
                    output+=temp;
                }
                number=0;
            }
            else if(input[i]==']'){
                return output;
            }
            else if(isdigit(input[i])){
                number*=10;
                number+=input[i]-'0';
            }
            else{
                output+=input[i];
            }
        }
        return output;
    }
    string decodeString(string s) {
        string output="";
        input=s;
        int number=0;
        for(i=0;i<s.size();i++){
            if(s[i]=='['){
                i++;
                string temp="";
                temp=recursion();
                for(int j=0;j<number;j++){
                    output+=temp;
                }
                number=0;
            }
            else if(isdigit(s[i])){
                number*=10;
                number+=s[i]-'0';
            }
            else{
                output+=s[i];
            }
        }
        return output;
    }
};