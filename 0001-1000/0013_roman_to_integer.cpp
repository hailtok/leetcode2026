// Problem 13: Roman to Integer
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        int answer=0,negative=0;
        for(int i=0;i<s.size()-1;i++){
            switch(s[i]){
                case('I'):
                    if(s[i+1]=='V'||s[i+1]=='X'){
                        negative++;
                    }
                    else{
                        answer++;
                    }
                    break;
                case('V'):
                answer+=5;
                    break;
                case('X'):
                    if(s[i+1]=='L'||s[i+1]=='C'){
                        negative+=10;
                    }
                    else{
                        answer+=10;
                    }
                    break;
                case('L'):
                answer+=50;
                    break;
                case('C'):
                    if(s[i+1]=='D'||s[i+1]=='M'){
                        negative+=100;
                    }
                    else{
                        answer+=100;
                    }
                    break;
                case('D'):
                answer+=500;
                    break;
                case('M'):
                answer+=1000;
                    break;                                                                                                   
            }
        }
        switch(s[s.size()-1]){
            case('I'):
            answer++;
                break;
            case('V'):
            answer+=5;
                break;
            case('X'):
            answer+=10;
                break;
            case('L'):
            answer+=50;
                break;
            case('C'):
            answer+=100;
                break;
            case('D'):
            answer+=500;
                break;
            case('M'):
            answer+=1000;
                break;                                                                                                   
        }        
        return answer-negative;
    }
};