// Problem 1073: Adding Two Negabinary Numbers
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/adding-two-negabinary-numbers/

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        reverse(arr1.begin(),arr1.end());
        reverse(arr2.begin(),arr2.end());
        for(int i=0,j=0;i<arr1.size()&&j<arr2.size();++i,++j){
            arr1[i]+=arr2[j];
            arr2[j]=arr1[i];
        }
        vector<int>answer;
        if(arr1.size()>arr2.size()){
            answer=arr1;
        }
        else{
            answer=arr2;
        }
        answer.push_back(0);
        answer.push_back(0);
        for(int i=0;i<(int)answer.size()-2;++i){
            if(answer[i]>1){
                answer[i+2]+=answer[i]/2;
                answer[i+1]+=answer[i]/2;
                answer[i]%=2;
            }
        }
        while(answer.back()&&answer[answer.size()-2]>=2){
            answer[answer.size()-1]--;
            answer[answer.size()-2]-=2;
        }
        while(answer.size()>1&&answer.back()==0){
            answer.pop_back();
        }
        if(answer.back()>1){
            answer[answer.size()-1]=0;
            answer.push_back(1);
            answer.push_back(1);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};