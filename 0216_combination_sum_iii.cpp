// Problem 216: Combination Sum III
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>>output;
    int target,limit;
    void recursion(int index,int count,int value,vector<int>array){
        if(value==target&&count==limit){
            output.push_back(array);
            return ;
        }
        if(index==10||target-value>(index+9)*(10-index)/2||count==limit){
            return;
        }
        for(int i=index;i<=9;i++){
            array.push_back(i);
            recursion(i+1,count+1,value+i,array);
            array.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        target=n;
        limit=k;
        vector<int>temp;
        recursion(1,0,0,temp);
        return output;
    }
};