// Problem 443: String Compression
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()<=1){
            return chars.size();
        }
        char temp='\0';
        int count=0,answer=0,index=-1;
        stack<int> nums;
        for(int i=0;i<chars.size();i++){
            if(temp==chars[i]){
                count++;
            }
            else{
                index++;
                if(index>0){
                    chars[index-1]=temp;
                }
                temp=chars[i];
                if(count==1){
                    count=1;
                    answer++;
                    continue;
                }
                answer++;
                while(count!=0){  
                    nums.push(count%10);
                    count/=10;
                    answer++;
                }
                while(!nums.empty()){
                    chars[index]=nums.top()+'0';
                    index++; 
                    nums.pop();
                }
                count=1;                
            }
        }
        if(index>0){
            chars[index]=temp;
        }
        if(count==1){
            return answer;
        }
        while(count!=0){
            nums.push(count%10);  
            count/=10;
            answer++;
        }
        index++;
        while(!nums.empty()){
            chars[index]=nums.top()+'0';
            index++;
            nums.pop();
        }
        return answer;
    }
};