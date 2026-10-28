// Problem 60: Permutation Sequence
// Difficulty: Hard
// Language: cpp
// URL: https://leetcode.com/problems/permutation-sequence/

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>temp(n,1);
        vector<bool>nums(n,false);
        for(int i=2,num=2;i<temp.size();++i,++num){
            temp[i]=temp[i-1]*num;
        }
        string answer="";
        k--;
        for(int i=nums.size()-1;i>=0;--i){
            int index=k/temp[i],count=index;
            vector<int>temp2;
            for(int i=1;i<=9;i++){
                if(!nums[i]){
                    temp2.push_back(i);
                }
            }
            answer.push_back(temp2[index]+'0');
            nums[temp2[index]]=true;
            k%=temp[i];
        }
        return answer;
    }
};