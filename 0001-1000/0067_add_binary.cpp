// Problem 67: Add Binary
// Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/add-binary/

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        bool check=false;
        int i=0;
        string answer="";
        while(i<a.size()&&i<b.size()){
            if(a[i]-'0'+b[i]-'0'+check>=2){
                answer+=to_string(a[i]-'0'+b[i]-'0'+check-2);
                check=true;
            }
            else{
                answer+=to_string(a[i]-'0'+b[i]-'0'+check);
                check=false;
            }
            i++;
        }
        while(i<a.size()){
            if(a[i]+check-'0'>=2){
                answer+=to_string(a[i]+check-'0'-2);
                check=true;
            }
            else{
                answer+=to_string(a[i]+check-'0');
                check=false;
            }
            i++;
        }
        while(i<b.size()){
            if(b[i]+check-'0'>=2){
                answer+=to_string(b[i]+check-'0'-2);
                check=true;
            }
            else{
                answer+=to_string(b[i]+check-'0');
                check=false;
            }
            i++;
        }
        if(check){
            answer+='1';
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};