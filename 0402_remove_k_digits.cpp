// Problem 402: Remove K Digits
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans1="";
        int index=1;
        while(index<num.size()){
            ans1.push_back(num[index-1]);
            if(num[index-1]>num[index]){
                while(ans1.size()>0&&k>0){
                    if(ans1.back()>num[index]){
                        ans1.pop_back();
                        --k;
                    }
                    else{
                        break;
                    }
                }
            }
            ++index;
        }
        ans1.push_back(num.back());
        while(k>0){
            ans1.pop_back();
            --k;
        }
        std::reverse(ans1.begin(),ans1.end());
        while(ans1.size()>0){
            if(ans1.back()=='0'){
                ans1.pop_back();
            }
            else{
                break;
            }
        }
        std::reverse(ans1.begin(),ans1.end());
        if(ans1.size()==0){
            return "0";
        }
        return ans1;
    }
};