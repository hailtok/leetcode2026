// Problem 2165: Smallest Value of the Rearranged Number
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/smallest-value-of-the-rearranged-number/

class Solution {
public:
    long long smallestNumber(long long num) {
        string temp=to_string(num),output="";
        vector<unsigned>numbers(10);
        if(num>=0){
            for(int i=0;i<temp.size();i++){
                numbers[temp[i]-'0']++;
            }
            for(int i=1;i<10;i++){
                if(numbers[i]!=0){
                    numbers[i]--;
                    output+=to_string(i);
                    break;
                }
            }
            for(int i=0;i<10;i++){
                while(numbers[i]){
                    numbers[i]--;
                    output+=to_string(i);
                }   
            }
        }
        else{
            for(int i=1;i<temp.size();i++){
                numbers[temp[i]-'0']++;
            }
            output+='-';
            for(int i=9;i>=0;i--){
                while(numbers[i]){
                    output+=to_string(i);
                    numbers[i]--;
                }
            }
        }
        return stoll(output);
    }
};