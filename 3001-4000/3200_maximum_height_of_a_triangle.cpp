// Problem 3200: Maximum Height of a Triangle
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/maximum-height-of-a-triangle/

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int answer=0;
        while(answer*(answer+1)/2<red+blue){
            answer++;
        }
        cout<<answer<<endl;
        int a=((answer+1)/2)*((answer+1)/2),b=answer*(answer+1)/2-a;
        while(true){
            cout<<"a:"<<a<<endl;
            cout<<"b:"<<b<<endl;
            if(std::max(a,b)<=std::max(red,blue)&&std::min(a,b)<=std::min(red,blue)){
                break;
            }
            else{
                answer--;
                a=((answer+1)/2)*((answer+1)/2),b=answer*(answer+1)/2-a;
            }
        }
        return answer;
    }
};