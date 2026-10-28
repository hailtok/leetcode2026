// Problem 984: String Without AAA or BBB
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/string-without-aaa-or-bbb/

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        double d_a=a,d_b=b;
        string ans="";
        for(int i=0,count=0;i<a+b;++i){
            if((a!=0&&count!=2&&d_a/d_b>=1)||count==-2){
                cout<<count<<endl;
                ans+='a';
                --d_a;
                if(count>=0){
                    ++count;
                }
                else{
                    count=1;
                }
            }
            else{
                ans+='b';
                --d_b;
                if(count<=0){
                    --count;
                }
                else{
                    count=-1;
                }
            }
        }
        return ans;
    }
};