// Problem 77: Combinations
// Difficulty: Medium
// Language: cpp
// URL: https://leetcode.com/problems/combinations/

class Solution {
public:
    vector<vector<int>>output;
    int target,limit;
    void recursion(int index,vector<int>array){
        if(array.size()==target){
            output.push_back(array);
            return;
        }
        for(int i=index;i<=limit;i++){
            array.push_back(i);
            recursion(i+1,array);
            array.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        target=k;
        limit=n;
        vector<int>temp;
        recursion(1,temp);
        return output;
    }
};